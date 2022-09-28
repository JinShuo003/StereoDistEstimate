#include "viewer/OpenGLWidget.h"

#include "QPushButton"
#include "QRandomGenerator"
#include "QtMath"

#include "iostream"
#include <exception>

using std::cout;
using std::endl;

OpenGLWidget::OpenGLWidget(QWidget* parent):
	QOpenGLWidget(parent)
{
	auto newFormat = this->format();
	newFormat.setSamples(16);
	this->setFormat(newFormat);

	GetLeftCamData();
	GetRightCamData();
	GetCoorData();
	GetGroundData();

	m_camera.reset(-2, 0, 0.5, 0, 10, 0);
	m_camera.update();

	init();
	installEventFilter(&m_camera);
}

OpenGLWidget::~OpenGLWidget()
{

}

void OpenGLWidget::init() {
	//Slider
	m_cameraSpeedControler = new QSlider(Qt::Horizontal, this);
	m_cameraSpeedControler->setRange(1, 7);
	m_cameraSpeedControler->setSingleStep(1);
	m_cameraSpeedControler->setValue(4);
	m_cameraSpeedControler->setTracking(true);
	m_cameraSpeedControler->setFixedSize(QSize(100, 30));
	float fCurrentSpeed = (float)m_cameraSpeedControler->value() / 100;
	m_camera.m_lookSpeed = fCurrentSpeed * 1.5;
	m_camera.m_moveSpeed = fCurrentSpeed;
	m_cameraSpeedControler->setStyleSheet("QSlider::handle:horizontal{ background: rgb(0, 0, 0)}");

	//label
	m_cameraSpeedLabel = new QLabel(this);
	m_cameraSpeedLabel->setFixedSize(QSize(110, 30));
	m_cameraSpeedLabel->setText(QString("Camera Speed: %1").arg(m_cameraSpeedControler->value()));
	m_cameraSpeedLabel->setStyleSheet("color:red;");

	//layout
	m_cameraSpeedVLayout = new QVBoxLayout();
	m_cameraSpeedHLayout = new QHBoxLayout();
	m_cameraSpeedHLayout->addStretch();
	m_cameraSpeedHLayout->addWidget(m_cameraSpeedLabel);
	m_cameraSpeedHLayout->addWidget(m_cameraSpeedControler);
	m_cameraSpeedVLayout->addLayout(m_cameraSpeedHLayout);
	m_cameraSpeedVLayout->addStretch();
	this->setLayout(m_cameraSpeedVLayout);

	//connect
	connect(this->m_cameraSpeedControler, &QSlider::valueChanged, this, &OpenGLWidget::Slot_SliderValueChanged);
}

void OpenGLWidget::mousePressEvent(QMouseEvent* event)
{
	setFocusPolicy(Qt::ClickFocus);
}


void OpenGLWidget::SetLineData(std::vector<cv::Point3d> v3dPoints, std::vector<cv::Scalar> vColor)
{
	if (Q_NULLPTR != vertexData[4].vertex) {
		delete[] vertexData[4].vertex;
	}
	//每个点六个维度，多加一倍0, 0点
	vertexData[4].vertex = new float[v3dPoints.size() * 2 * 6];
	//第一维度为点数，总数为2*v3dPoints.size()，第二维度为6
	for (int i = 0; i < 2*v3dPoints.size(); i++)
	{
		//偶数时，该点为原点
		if (i % 2 == 0) {
			vertexData[4].vertex[i * 6] = 0;
			vertexData[4].vertex[i * 6 + 1] = 0;
			vertexData[4].vertex[i * 6 + 2] = 0;
			vertexData[4].vertex[i * 6 + 3] = vColor[i / 2][2] / 255;
			vertexData[4].vertex[i * 6 + 4] = vColor[i / 2][1] / 255;
			vertexData[4].vertex[i * 6 + 5] = vColor[i / 2][0] / 255;
		}
		//奇数时，该点为实际三维点
		else {
			vertexData[4].vertex[i * 6] = v3dPoints[i/2].x;
			vertexData[4].vertex[i * 6 + 1] = -v3dPoints[i/2].y;
			vertexData[4].vertex[i * 6 + 2] = -v3dPoints[i/2].z;
			vertexData[4].vertex[i * 6 + 3] = vColor[i / 2][2] / 255;
			vertexData[4].vertex[i * 6 + 4] = vColor[i / 2][1] / 255;
			vertexData[4].vertex[i * 6 + 5] = vColor[i / 2][0] / 255;
		}
	}
	vertexData[4].pointDim = 6;
	vertexData[4].vertexNum = v3dPoints.size() * 2;
	vertexData[4].dataNum = v3dPoints.size() * 2 * vertexData[4].pointDim;
	vertexData[4].lenth = vertexData[4].dataNum * sizeof(float);

	initLineData();
	bIs3dLinesSetted = true;

	GetPointData(v3dPoints, vColor);
}

void OpenGLWidget::SetLineData(std::vector<cv::Point3d> v3dPoints, std::vector<float> vError)
{
	if (Q_NULLPTR != vertexData[4].vertex) {
		delete[] vertexData[4].vertex;
	}
	//每个点六个维度，多加一倍0, 0点
	vertexData[4].vertex = new float[v3dPoints.size() * 2 * 6];
	//求每个点的颜色
	std::vector<cv::Scalar> vColor(v3dPoints.size());
	for (int i = 0; i < vColor.size(); i++)
	{
		//用误差值着色，误差大于等于10%时为红色，越小越接近绿色，为5%时为黄色
		if (vError[i] >= 0.1) {
			vColor[i] = cv::Scalar(255.f, 0.f, 0.f);
		}
		//黄色
		else if (qAbs(vError[i] - 0.05) <= 1e-3) {
			vColor[i] = cv::Scalar(255.f, 255.f, 0.f);
		}
		//绿色到黄色渐变
		else if (vError[i] >= 0 && vError[i] < 0.05) {
			vColor[i] = cv::Scalar(vError[i] / 0.05 * 255, 255.f, 0.f);
		}
		//黄色到红色渐变
		else {
			vColor[i] = cv::Scalar(255.f, 2 - vError[i / 2] / 0.05 * 255, 0.f);
		}
	}
	//第一维度为点数，总数为2*v3dPoints.size()，第二维度为6
	for (int i = 0; i < 2 * v3dPoints.size(); i++)
	{
		//偶数时，该点为原点
		if (i % 2 == 0) {
			vertexData[4].vertex[i * 6] = 0;
			vertexData[4].vertex[i * 6 + 1] = 0;
			vertexData[4].vertex[i * 6 + 2] = 0;
		}
		//奇数时，该点为实际三维点
		else {
			vertexData[4].vertex[i * 6] = v3dPoints[i / 2].x;
			vertexData[4].vertex[i * 6 + 1] = -v3dPoints[i / 2].y;
			vertexData[4].vertex[i * 6 + 2] = -v3dPoints[i / 2].z;
		}
		//颜色
		vertexData[4].vertex[i * 6 + 3] = vColor[i / 2][0] / 255;
		vertexData[4].vertex[i * 6 + 4] = vColor[i / 2][1] / 255;
		vertexData[4].vertex[i * 6 + 5] = vColor[i / 2][2] / 255;
	}
	vertexData[4].pointDim = 6;
	vertexData[4].vertexNum = v3dPoints.size() * 2;
	vertexData[4].dataNum = v3dPoints.size() * 2 * vertexData[4].pointDim;
	vertexData[4].lenth = vertexData[4].dataNum * sizeof(float);

	initLineData();
	bIs3dLinesSetted = true;

	GetPointData(v3dPoints, vColor);
}

void OpenGLWidget::GetLeftCamData()
{
	if (Q_NULLPTR == vertexData[0].vertex) {
		delete[] vertexData[0].vertex;
	}
	// 顶点缓存中前三个是顶点坐标, 后三个是RGB色彩
	static float vertex_leftCam[] = {
		0, 0, 0,               0, 0, 1,
		-0.2, 0.1, 0.1,        0, 0, 1,
		-0.2, -0.1, 0.1,       0, 0, 1,

		0, 0, 0,               0, 0, 1,
		-0.2, -0.1, 0.1,       0, 0, 1,
		0.2, -0.1, 0.1,        0, 0, 1,

		0, 0, 0,               0, 0, 1,
		0.2, -0.1, 0.1,        0, 0, 1,
		0.2, 0.1, 0.1,         0, 0, 1,

		0, 0, 0,               0, 0, 1,
		-0.2, 0.1, 0.1,        0, 0, 1,
		0.2, 0.1, 0.1,         0, 0, 1,
	};
	vertexData[0].pointDim = 6;
	vertexData[0].vertex = vertex_leftCam;
	vertexData[0].vertexNum = sizeof(vertex_leftCam) / sizeof(float) / vertexData[0].pointDim;
	vertexData[0].dataNum = sizeof(vertex_leftCam) / sizeof(float);
	vertexData[0].lenth = sizeof(vertex_leftCam);
}

void OpenGLWidget::GetRightCamData()
{
	if (Q_NULLPTR == vertexData[1].vertex) {
		delete[] vertexData[1].vertex;
	}
	// 顶点缓存中前三个是顶点坐标, 后两个是纹理坐标, 一个顶点由5个float值组成
	static float vertex_rightCam[] = {
		0, 0, 0,               0, 0, 1,
		-0.2, 0.1, 0.1,        0, 0, 1,
		-0.2, -0.1, 0.1,       0, 0, 1,

		0, 0, 0,               0, 0, 1,
		-0.2, -0.1, 0.1,       0, 0, 1,
		0.2, -0.1, 0.1,        0, 0, 1,

		0, 0, 0,               0, 0, 1,
		0.2, -0.1, 0.1,        0, 0, 1,
		0.2, 0.1, 0.1,         0, 0, 1,

		0, 0, 0,               0, 0, 1,
		-0.2, 0.1, 0.1,        0, 0, 1,
		0.2, 0.1, 0.1,         0, 0, 1,
	};
	for (int i = 0; i < 12; i++)
	{
		vertex_rightCam[6 * i] += fCamOffset;
	}
	vertexData[1].pointDim = 6;
	vertexData[1].vertex = vertex_rightCam;
	vertexData[1].vertexNum = sizeof(vertex_rightCam) / sizeof(float) / vertexData[1].pointDim;
	vertexData[1].dataNum = sizeof(vertex_rightCam) / sizeof(float);
	vertexData[1].lenth = sizeof(vertex_rightCam);
}

void OpenGLWidget::GetCoorData()
{
	if (Q_NULLPTR == vertexData[2].vertex) {
		delete[] vertexData[2].vertex;
	}
	// 顶点缓存中前三个是顶点坐标, 后两个是纹理坐标, 一个顶点由5个float值组成
	static float vertex_coor[] = {
		//向右
		0, 0, 0,       1, 0, 0, 
		0.5, 0, 0,     1, 0, 0, 

		//向上
		0, 0, 0,       0, 1, 0,
		0, 0.5, 0,     0, 1, 0,

		//向前
		0, 0, 0,       0, 0, 1,
		0, 0, -0.5,    0, 0, 1
	};
	for (int i = 0; i < 6; i++)
	{
		vertex_coor[6 * i] += fCamOffset/2;
		vertex_coor[6 * i + 2] += fCamOffset / 2;
	}
	vertexData[2].pointDim = 6;
	vertexData[2].vertex = vertex_coor;
	vertexData[2].vertexNum = sizeof(vertex_coor) / sizeof(float) / vertexData[2].pointDim;
	vertexData[2].dataNum = sizeof(vertex_coor) / sizeof(float);
	vertexData[2].lenth = sizeof(vertex_coor);
}

void OpenGLWidget::GetGroundData()
{
	//生成地面棋盘数据
	std::vector<std::vector<std::vector<float>>> vertex_ground_vec;
	int16_t nSideLenth = 50;
	int16_t nDivideTimes = 10;
	float step = nSideLenth / nDivideTimes;
	//遍历每一个顶点，每一个顶点需要四个顶点绘制一个正方形，遍历到的每个顶点为左上角，需要按照左上、左下、右下、右上的顺序插入
	std::vector<std::pair<qint8, qint8>> vVertexOffset;
	vVertexOffset.push_back(std::pair<qint8, qint8>(0, 0));
	vVertexOffset.push_back(std::pair<qint8, qint8>(1, 0));
	vVertexOffset.push_back(std::pair<qint8, qint8>(1, 1));
	vVertexOffset.push_back(std::pair<qint8, qint8>(0, 1));
	vertex_ground_vec.resize(nDivideTimes);
	for (int i = 0; i < nDivideTimes; i++)
	{
		vertex_ground_vec[i].resize(nDivideTimes);
		for (int j = 0; j < nDivideTimes; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				//坐标
				vertex_ground_vec[i][j].push_back((j + vVertexOffset[k].second)*step - 25);
				vertex_ground_vec[i][j].push_back(-2);
				vertex_ground_vec[i][j].push_back((i + vVertexOffset[k].first)*step - 25);
				//颜色
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
					vertex_ground_vec[i][j].push_back(1);
					vertex_ground_vec[i][j].push_back(0.937);
					vertex_ground_vec[i][j].push_back(0.835);
				}
				else {
					vertex_ground_vec[i][j].push_back(0.69);
					vertex_ground_vec[i][j].push_back(0.886);
					vertex_ground_vec[i][j].push_back(1);
				}
			}
		}
	}

	if (Q_NULLPTR == vertexData[3].vertex) {
		delete[] vertexData[3].vertex;
	}
	//正方形数量有nDivideTimes * nDivideTimes个，每个正方形有4个顶点，每个顶点维度为6
	vertexData[3].vertex = new float[(int64)nDivideTimes * nDivideTimes * 4 * 6];
	for (int i = 0; i < nDivideTimes; i++)
	{
		for (int j = 0; j < nDivideTimes; j++)
		{
			for (int k = 0; k < vertex_ground_vec[i][j].size(); k++)
			{
				vertexData[3].vertex[nDivideTimes * 24 * i + 24 * j + k] = vertex_ground_vec[i][j][k];
			}
		}
	}

	vertexData[3].pointDim = 6;
	vertexData[3].vertexNum = nDivideTimes * nDivideTimes * 4;
	vertexData[3].dataNum = vertexData[3].vertexNum * 6;
	vertexData[3].lenth = vertexData[3].dataNum * sizeof(float);
}

void OpenGLWidget::GetPointData(std::vector<cv::Point3d> v3dPoints, std::vector<cv::Scalar> vColor)
{
	//构造所有点，第一维表示每个特征点，第二维维度为37，表示球心和球上36个点，第三维维度为6，坐标+颜色
	std::vector<std::vector<std::vector<float>>> vertex_point_vec(v3dPoints.size());
	for (int i = 0; i < vertex_point_vec.size(); i++)
	{
		//球心
		vertex_point_vec[i].resize(38);
		vertex_point_vec[i][0].push_back((float)v3dPoints[i].x);
		vertex_point_vec[i][0].push_back((float)-v3dPoints[i].y);
		vertex_point_vec[i][0].push_back((float)-v3dPoints[i].z);
		vertex_point_vec[i][0].push_back(vColor[i][2] / 255.f);
		vertex_point_vec[i][0].push_back(vColor[i][1] / 255.f);
		vertex_point_vec[i][0].push_back(vColor[i][0] / 255.f);
		//计算圆的半径
		float fR = v3dPoints[i].z / 100;
		fR = fR > 1 ? 1 : fR;
		fR = fR < 0.05 ? 0.05 : fR;
		//将圆等分为36个三角形，每个圆心角为10度
		for (int j = 1; j < 38; j++)
		{
			float fRadian = j * 2 * M_PI / 36;
			vertex_point_vec[i][j].push_back(fR * cosf(fRadian) + (float)v3dPoints[i].x);
			vertex_point_vec[i][j].push_back(fR * sinf(fRadian) - (float)v3dPoints[i].y);
			vertex_point_vec[i][j].push_back((float)-v3dPoints[i].z);
			vertex_point_vec[i][j].push_back(vColor[i][2] / 255.f);
			vertex_point_vec[i][j].push_back(vColor[i][1] / 255.f);
			vertex_point_vec[i][j].push_back(vColor[i][0] / 255.f);
		}
	}

	if (Q_NULLPTR == vertexData[5].vertex) {
		delete[] vertexData[5].vertex;
	}
	vertexData[5].vertex = new float[v3dPoints.size() * 38 * 6];
	for (int i = 0; i < vertex_point_vec.size(); i++)
	{
		for (int j = 0; j < 38; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				vertexData[5].vertex[38 * 6 * i + 6 * j + k] = vertex_point_vec[i][j][k];
			}
		}
	}

	vertexData[5].pointDim = 6;
	vertexData[5].vertexNum = v3dPoints.size() * 38;
	vertexData[5].dataNum = vertexData[5].vertexNum * vertexData[5].pointDim;
	vertexData[5].lenth = vertexData[5].dataNum * sizeof(float);

	initPointData();
	bIs3dPointsSetted = true;
}


void OpenGLWidget::initData(UINT8 index)
{
	if (Q_NULLPTR == m_program[index]) {
		m_program[index] = new QOpenGLShaderProgram;
	}
	m_VAO[index].create();
	m_VBO[index].create();

	QString sVertexShaderName = "transform_color.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "transform_color.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program[index]->addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program[index]->addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);
	m_program[index]->link();

	m_VAO[index].bind();
	m_VBO[index].bind();

	m_VBO[index].allocate(vertexData[index].vertex, vertexData[index].lenth);

	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有6个float数据, 所以下一个数据需要偏移6 * sizeof(float)个字节
	m_program[index]->bind();
	m_program[index]->setAttributeBuffer("vPos", GL_FLOAT, 0 * sizeof(float), 3, 6 * sizeof(float));
	m_program[index]->enableAttributeArray("vPos");
	m_program[index]->setAttributeBuffer("vColor", GL_FLOAT, 3 * sizeof(float), 3, 6 * sizeof(float));
	m_program[index]->enableAttributeArray("vColor");

	m_program[index]->release();
	m_VAO[index].release();
}

void OpenGLWidget::initLineData()
{
	if (Q_NULLPTR != m_program[4]) {
		 delete m_program[4];
	}
	m_program[4] = new QOpenGLShaderProgram;

	//若已创建过，则全部释放
	if (!m_VAO[4].isCreated()) {
		m_VAO[4].create();
	}
	if (!m_VBO[4].isCreated()) {
		m_VBO[4].create();
	}

	QString sVertexShaderName = "transform_color.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "transform_color.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program[4]->addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program[4]->addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);
	m_program[4]->link();

	m_VAO[4].bind();
	m_VBO[4].bind();

	m_VBO[4].allocate(vertexData[4].vertex, vertexData[4].lenth);
	
	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有5个float数据, 所以下一个数据需要偏移5 * sizeof(float)个字节
	m_program[4]->bind();
	m_program[4]->setAttributeBuffer("vPos", GL_FLOAT, 0 * sizeof(float), 3, 6 * sizeof(float));
	m_program[4]->enableAttributeArray("vPos");
	m_program[4]->setAttributeBuffer("vColor", GL_FLOAT, 3 * sizeof(float), 3, 6 * sizeof(float));
	m_program[4]->enableAttributeArray("vColor");

	m_program[4]->release();
	m_VAO[4].release();
}

void OpenGLWidget::initPointData()
{
	if (Q_NULLPTR != m_program[5]) {
		delete m_program[5];
	}
	m_program[5] = new QOpenGLShaderProgram;

	//若已创建过，则全部释放
	if (!m_VAO[5].isCreated()) {
		m_VAO[5].create();
	}
	if (!m_VBO[5].isCreated()) {
		m_VBO[5].create();
	}

	QString sVertexShaderName = "transform_color.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "transform_color.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program[5]->addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program[5]->addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);
	m_program[5]->link();

	m_VAO[5].bind();
	m_VBO[5].bind();

	m_VBO[5].allocate(vertexData[5].vertex, vertexData[5].lenth);

	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有6个float数据, 所以下一个数据需要偏移6 * sizeof(float)个字节
	m_program[5]->bind();
	m_program[5]->setAttributeBuffer("vPos", GL_FLOAT, 0 * sizeof(float), 3, 6 * sizeof(float));
	m_program[5]->enableAttributeArray("vPos");
	m_program[5]->setAttributeBuffer("vColor", GL_FLOAT, 3 * sizeof(float), 3, 6 * sizeof(float));
	m_program[5]->enableAttributeArray("vColor");

	m_program[5]->release();
	m_VAO[5].release();
}


void OpenGLWidget::paintCam(UINT8 area)
{
	glLineWidth(1);
	m_VAO[area].bind();
	m_program[area]->bind();
	// 绑定变换矩阵
	m_program[area]->setUniformValue("projection", m_projection);
	m_program[area]->setUniformValue("view", m_camera.view());
	m_program[area]->setUniformValue("model", m_model);

	// 绘制
	for (int i = 0; i < 4; i++)
	{
		glDrawArrays(GL_LINE_LOOP, i * 3, 3);
	}

	m_program[area]->release();
	m_VAO[area].release();
}

void OpenGLWidget::paintCoor()
{
	glLineWidth(1);
	m_VAO[2].bind();
	m_program[2]->bind();
	// 绑定变换矩阵
	m_program[2]->setUniformValue("view", m_camera.view());
	m_program[2]->setUniformValue("model", m_model);
	m_program[2]->setUniformValue("projection", m_projection);

	// 绘制
	for (int i = 0; i < 4; i++)
	{
		glDrawArrays(GL_LINES, i * 2, 2);
	}

	m_program[2]->release();
	m_VAO[2].release();
}

void OpenGLWidget::paintGround()
{
	m_VAO[3].bind();
	m_program[3]->bind();
	// 绑定变换矩阵
	m_program[3]->setUniformValue("projection", m_projection);
	m_program[3]->setUniformValue("view", m_camera.view());
	m_program[3]->setUniformValue("model", m_model);

	// 绘制
	for (int i = 0; i < 100; i++)
	{
		glDrawArrays(GL_TRIANGLE_FAN, i*4, 4);
	}

	m_program[3]->release();
	m_VAO[3].release();
}

void OpenGLWidget::paintLine()
{
	glLineWidth(3);
	m_VAO[4].bind();
	m_program[4]->bind();
	// 绑定变换矩阵
	m_program[4]->setUniformValue("projection", m_projection);
	m_program[4]->setUniformValue("view", m_camera.view());
	m_program[4]->setUniformValue("model", m_model);

	// 绘制
	for (int i = 0; i < vertexData[4].vertexNum/2; i++)
	{
		glDrawArrays(GL_LINES, i * 2, 2);
	}

	m_program[4]->release();
	m_VAO[4].release();
}

void OpenGLWidget::paintPoint()
{
	glLineWidth(3);
	m_VAO[5].bind();
	m_program[5]->bind();
	// 绑定变换矩阵
	m_program[5]->setUniformValue("projection", m_projection);
	m_program[5]->setUniformValue("view", m_camera.view());
	m_program[5]->setUniformValue("model", m_model);

	// 绘制
	for (int i = 0; i < vertexData[5].vertexNum; i++)
	{
		glDrawArrays(GL_TRIANGLE_FAN, i * 38, 38);
	}

	m_program[5]->release();
	m_VAO[5].release();
}


void OpenGLWidget::initializeGL() {
	initializeOpenGLFunctions();
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	//glLineWidth(3);
	glClearColor(0.8, 0.8, 0.8, 1);

	initData(m_dataIdx::left);
	initData(m_dataIdx::right);
	initData(m_dataIdx::coor);
	initData(m_dataIdx::ground);
}

void OpenGLWidget::resizeGL(int w, int h)
{
	m_projection.setToIdentity();
	m_projection.perspective(60, (float)w / h, 0.001, 1000);
}

void OpenGLWidget::paintGL() {
	paintCam(m_dataIdx::left);
	paintCam(m_dataIdx::right);
	paintCoor();
	paintGround();
	if (bIs3dLinesSetted == true) {
		paintLine();
	}
	if (bIs3dPointsSetted == true) {
		paintPoint();
	}
}


void OpenGLWidget::Slot_SliderValueChanged()
{
	float fCurrentSpeed = (float)m_cameraSpeedControler->value() / 100;
	m_camera.m_lookSpeed = fCurrentSpeed * 1.5;
	m_camera.m_moveSpeed = fCurrentSpeed;
	m_cameraSpeedLabel->setText(QString("Camera Speed: %1").arg(m_cameraSpeedControler->value()));
}