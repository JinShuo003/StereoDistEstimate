#include "viewer/OpenGLWidget.h"

#include "QRandomGenerator"
#include "QtMath"

#include "iostream"
#include <thread>

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

	installEventFilter(&m_camera);
}

OpenGLWidget::~OpenGLWidget()
{

}

void OpenGLWidget::mousePressEvent(QMouseEvent* event)
{
	setFocusPolicy(Qt::ClickFocus);
}


void OpenGLWidget::SetLineData(std::vector<cv::Point3d> v3dPoints)
{
	if (Q_NULLPTR != vertexData[4].vertex) {
		delete[] vertexData[4].vertex;
	}
	//ÿ��������ά�ȣ����һ��0, 0��
	vertexData[4].vertex = new float[v3dPoints.size() * 2 * 6];
	//��һά��Ϊ����������Ϊ2*v3dPoints.size()���ڶ�ά��Ϊ6
	for (int i = 0; i < 2*v3dPoints.size(); i++)
	{
		static float fLineColor1 = (float)QRandomGenerator::global()->bounded(1.0);
		static float fLineColor2 = (float)QRandomGenerator::global()->bounded(1.0);
		static float fLineColor3 = (float)QRandomGenerator::global()->bounded(1.0);
		//ż��ʱ���õ�Ϊԭ��
		if (i % 2 == 0) {
			vertexData[4].vertex[i * 6] = 0;
			vertexData[4].vertex[i * 6 + 1] = 0;
			vertexData[4].vertex[i * 6 + 2] = 0;
			vertexData[4].vertex[i * 6 + 3] = fLineColor1;
			vertexData[4].vertex[i * 6 + 4] = fLineColor2;
			vertexData[4].vertex[i * 6 + 5] = fLineColor3;
		}
		//����ʱ���õ�Ϊʵ����ά��
		else {
			vertexData[4].vertex[i * 6] = v3dPoints[i/2].x;
			vertexData[4].vertex[i * 6 + 1] = -v3dPoints[i/2].y;
			vertexData[4].vertex[i * 6 + 2] = -v3dPoints[i/2].z;
			vertexData[4].vertex[i * 6 + 3] = fLineColor1;
			vertexData[4].vertex[i * 6 + 4] = fLineColor2;
			vertexData[4].vertex[i * 6 + 5] = fLineColor3;
			fLineColor1 = (float)QRandomGenerator::global()->bounded(1.0);
			fLineColor2 = (float)QRandomGenerator::global()->bounded(1.0);
			fLineColor3 = (float)QRandomGenerator::global()->bounded(1.0);
		}
		////����ɫ��һ�£��÷���������ɫ
		//QVector3D directionVec = QVector3D(v3dPoints[i/2].x, v3dPoints[i/2].y, v3dPoints[i/2].z).normalized();
		//vertexData[4].vertex[i * 6 + 3] = (float)QRandomGenerator::global()->bounded(1.0);
		//vertexData[4].vertex[i * 6 + 4] = (float)QRandomGenerator::global()->bounded(1.0);
		//vertexData[4].vertex[i * 6 + 5] = (float)QRandomGenerator::global()->bounded(1.0);
	}
	vertexData[4].pointDim = 6;
	vertexData[4].vertexNum = v3dPoints.size() * 2;
	vertexData[4].dataNum = v3dPoints.size() * 2 * vertexData[4].pointDim;
	vertexData[4].lenth = vertexData[4].dataNum * sizeof(float);

	initPointData();
	bIs3dLinesSetted = true;

	//GetPointData(v3dPoints);
}

void OpenGLWidget::SetLineData(std::vector<cv::Point3d> v3dPoints, std::vector<float> vError)
{
	if (Q_NULLPTR != vertexData[4].vertex) {
		delete[] vertexData[4].vertex;
	}
	//ÿ��������ά�ȣ����һ��0, 0��
	vertexData[4].vertex = new float[v3dPoints.size() * 2 * 6];
	//��һά��Ϊ����������Ϊ2*v3dPoints.size()���ڶ�ά��Ϊ6
	for (int i = 0; i < 2 * v3dPoints.size(); i++)
	{
		//����
		//ż��ʱ���õ�Ϊԭ��
		if (i % 2 == 0) {
			vertexData[4].vertex[i * 6] = 0;
			vertexData[4].vertex[i * 6 + 1] = 0;
			vertexData[4].vertex[i * 6 + 2] = 0;
		}
		//����ʱ���õ�Ϊʵ����ά��
		else {
			vertexData[4].vertex[i * 6] = v3dPoints[i / 2].x;
			vertexData[4].vertex[i * 6 + 1] = -v3dPoints[i / 2].y;
			vertexData[4].vertex[i * 6 + 2] = -v3dPoints[i / 2].z;
		}

		//��ɫ
		//�����ֵ��ɫ�������ڵ���10%ʱΪ��ɫ��ԽСԽ�ӽ���ɫ��Ϊ5%ʱΪ��ɫ
		if (vError[i / 2] >= 0.1) {
			vertexData[4].vertex[i * 6 + 3] = 1.f;
			vertexData[4].vertex[i * 6 + 4] = 0.f;
			vertexData[4].vertex[i * 6 + 5] = 0.f;
		}
		//��ɫ
		else if(qAbs(vError[i / 2] - 0.05) <= 1e-3){
			vertexData[4].vertex[i * 6 + 3] = 1.f;
			vertexData[4].vertex[i * 6 + 4] = 1.f;
			vertexData[4].vertex[i * 6 + 5] = 0.f;
		}
		//��ɫ����ɫ����
		else if (vError[i / 2] >= 0 && vError[i / 2] < 0.05) {
			vertexData[4].vertex[i * 6 + 3] = vError[i/2] / 0.05;
			vertexData[4].vertex[i * 6 + 4] = 1.f;
			vertexData[4].vertex[i * 6 + 5] = 0.f;
		}
		//��ɫ����ɫ����
		else {
			vertexData[4].vertex[i * 6 + 3] = 1.f;
			vertexData[4].vertex[i * 6 + 4] = 2 - vError[i / 2] / 0.05;
			vertexData[4].vertex[i * 6 + 5] = 0.f;
		}
	}
	vertexData[4].pointDim = 6;
	vertexData[4].vertexNum = v3dPoints.size() * 2;
	vertexData[4].dataNum = v3dPoints.size() * 2 * vertexData[4].pointDim;
	vertexData[4].lenth = vertexData[4].dataNum * sizeof(float);

	initPointData();
	bIs3dLinesSetted = true;

	//GetPointData(v3dPoints);
}

void OpenGLWidget::GetLeftCamData()
{
	// ���㻺����ǰ�����Ƕ�������, ��������RGBɫ��
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
	// ���㻺����ǰ�����Ƕ�������, ����������������, һ��������5��floatֵ���
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

	//cout << "right camera: " << endl;
	//cout << "vertexData.vertexNum: " << vertexData[1].vertexNum << endl;
	//cout << "vertexData.dataNum: " << vertexData[1].dataNum << endl;
	//cout << "vertexData.lenth: " << vertexData[1].lenth << endl;
	//for (int i = 0; i < vertexData[1].dataNum; i++)
	//{
	//	cout << vertexData[1].vertex[i] << ',';
	//	if ((i + 1) % vertexData[1].pointDim == 0) {
	//		cout << endl;
	//	}
	//}
}

void OpenGLWidget::GetCoorData()
{
	// ���㻺����ǰ�����Ƕ�������, ����������������, һ��������5��floatֵ���
	static float vertex_coor[] = {
		//����
		0, 0, 0,       1, 0, 0, 
		0.5, 0, 0,     1, 0, 0, 

		//����
		0, 0, 0,       0, 1, 0,
		0, 0.5, 0,     0, 1, 0,

		//��ǰ
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

	//cout << "coor: " << endl;
	//cout << "vertexData.vertexNum: " << vertexData[2].vertexNum << endl;
	//cout << "vertexData.dataNum: " << vertexData[2].dataNum << endl;
	//cout << "vertexData.lenth: " << vertexData[2].lenth << endl;
	//for (int i = 0; i < vertexData[2].dataNum; i++)
	//{
	//	cout << vertexData[2].vertex[i] << ',';
	//	if ((i + 1) % vertexData[2].pointDim == 0) {
	//		cout << endl;
	//	}
	//}
}

void OpenGLWidget::GetGroundData()
{
	//���ɵ�����������
	std::vector<std::vector<std::vector<float>>> vertex_ground_vec;
	int16_t nSideLenth = 50;
	int16_t nDivideTimes = 10;
	float step = nSideLenth / nDivideTimes;
	//����ÿһ�����㣬ÿһ��������Ҫ�ĸ��������һ��������
	//��������ÿ������Ϊ���Ͻǣ���Ҫ�������ϡ����¡����¡����ϵ�˳�����
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
				//����
				vertex_ground_vec[i][j].push_back((j + vVertexOffset[k].second)*step - 25);
				vertex_ground_vec[i][j].push_back(-2);
				vertex_ground_vec[i][j].push_back((i + vVertexOffset[k].first)*step - 25);
				//��ɫ
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
	static float* vertex_ground = Q_NULLPTR;
	if (Q_NULLPTR != vertex_ground) {
		delete[] vertex_ground;
	}
	//������������nDivideTimes * nDivideTimes����ÿ����������4�����㣬ÿ������ά��Ϊ6
	vertex_ground = new float[(int64)nDivideTimes * nDivideTimes * 4 * 6];
	for (int i = 0; i < nDivideTimes; i++)
	{
		for (int j = 0; j < nDivideTimes; j++)
		{
			for (int k = 0; k < vertex_ground_vec[i][j].size(); k++)
			{
				vertex_ground[nDivideTimes * 24 * i + 24 * j + k] = vertex_ground_vec[i][j][k];
			}
		}
	}

	vertexData[3].pointDim = 6;
	vertexData[3].vertex = vertex_ground;
	vertexData[3].vertexNum = nDivideTimes * nDivideTimes * 4;
	vertexData[3].dataNum = vertexData[3].vertexNum * 6;
	vertexData[3].lenth = vertexData[3].dataNum * sizeof(float);

}

//void OpenGLWidget::GetPointData(std::vector<cv::Point3d> v3dPoints)
//{
//	//�ҳ����е���������ֵ
//	float fMaxDepth = 0;
//	for (int i = 0; i < v3dPoints.size(); i++)
//	{
//		if (v3dPoints[i].z > fMaxDepth) {
//			fMaxDepth = v3dPoints[i].z;
//		}
//	}
//	std::vector<std::vector<cv::Point3f>> vertex_point_vec(v3dPoints.size());
//	for (int i = 0; i < vertex_point_vec.size(); i++)
//	{
//		float fR = v3dPoints[i].z / fMaxDepth * 10;
//		vertex_point_vec[i].push_back(cv::Point3f(0, 0, 0));
//		for (int j = 0; j < 36; j++)
//		{
//			float fRadian = 0.2 * j * M_PI;
//			vertex_point_vec[i].push_back(cv::Point3f(fR * cosf(fRadian) + v3dPoints[i].x, fR * sinf(fRadian) + v3dPoints[i].y, v3dPoints[i].z));
//		}
//	}
//	// ���㻺����ǰ�����Ƕ�������, ����������������, һ��������5��floatֵ���
//	static float* vertex_point = new float[v3dPoints.size() * 37 * 3];
//	for (int i = 0; i < vertex_point_vec.size(); i++)
//	{
//		for (int j = 0; j < 37; j++)
//		{
//			for (int k = 0; k < 3; k++)
//			{
//				vertex_point[nDivideTimes * 37 * i + 37 * j + k]
//			}
//		}
//	}
//
//	vertexData[4].pointDim = 3;
//	vertexData[4].vertex = vertex_point;
//	vertexData[4].vertexNum = sizeof(vertex_point) / sizeof(float);
//	vertexData[4].dataNum = sizeof(vertex_point) / sizeof(float);
//	vertexData[4].lenth = sizeof(vertex_point);
//
//
//	bIs3dPointsSetted = true;
//}


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

	// �󶨶���������Ϣ, ��0 * sizeof(float)�ֽڿ�ʼ��ȡ3��float, ��Ϊһ��������5��float����, ������һ��������Ҫƫ��5 * sizeof(float)���ֽ�
	m_program[index]->bind();
	m_program[index]->setAttributeBuffer("vPos", GL_FLOAT, 0 * sizeof(float), 3, 6 * sizeof(float));
	m_program[index]->enableAttributeArray("vPos");
	m_program[index]->setAttributeBuffer("vColor", GL_FLOAT, 3 * sizeof(float), 3, 6 * sizeof(float));
	m_program[index]->enableAttributeArray("vColor");

	m_program[index]->release();
	m_VAO[index].release();
}

void OpenGLWidget::initPointData()
{
	if (Q_NULLPTR != m_program[4]) {
		 delete m_program[4];
	}
	m_program[4] = new QOpenGLShaderProgram;

	//���Ѵ���������ȫ���ͷ�
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
	
	// �󶨶���������Ϣ, ��0 * sizeof(float)�ֽڿ�ʼ��ȡ3��float, ��Ϊһ��������5��float����, ������һ��������Ҫƫ��5 * sizeof(float)���ֽ�
	m_program[4]->bind();
	m_program[4]->setAttributeBuffer("vPos", GL_FLOAT, 0 * sizeof(float), 3, 6 * sizeof(float));
	m_program[4]->enableAttributeArray("vPos");
	m_program[4]->setAttributeBuffer("vColor", GL_FLOAT, 3 * sizeof(float), 3, 6 * sizeof(float));
	m_program[4]->enableAttributeArray("vColor");

	m_program[4]->release();
	m_VAO[4].release();
}


void OpenGLWidget::paintCam(UINT8 area)
{
	glLineWidth(1);
	m_VAO[area].bind();
	m_program[area]->bind();
	// �󶨱任����
	m_program[area]->setUniformValue("projection", m_projection);
	m_program[area]->setUniformValue("view", m_camera.view());
	m_program[area]->setUniformValue("model", m_model);

	// ����
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
	// �󶨱任����
	m_program[2]->setUniformValue("view", m_camera.view());
	m_program[2]->setUniformValue("model", m_model);
	m_program[2]->setUniformValue("projection", m_projection);

	// ����
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
	// �󶨱任����
	m_program[3]->setUniformValue("projection", m_projection);
	m_program[3]->setUniformValue("view", m_camera.view());
	m_program[3]->setUniformValue("model", m_model);

	// ����
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
	// �󶨱任����
	m_program[4]->setUniformValue("projection", m_projection);
	m_program[4]->setUniformValue("view", m_camera.view());
	m_program[4]->setUniformValue("model", m_model);

	// ����
	for (int i = 0; i < vertexData[4].vertexNum/2; i++)
	{
		glDrawArrays(GL_LINES, i * 2, 2);
	}

	m_program[4]->release();
	m_VAO[4].release();
}

//void OpenGLWidget::paintPoint()
//{
//	glLineWidth(3);
//	m_VAO[5].bind();
//	m_program[5]->bind();
//	// �󶨱任����
//	m_program[5]->setUniformValue("projection", m_projection);
//	m_program[5]->setUniformValue("view", m_camera.view());
//	m_program[5]->setUniformValue("model", m_model);
//
//	// ����
//	for (int i = 0; i < vertexData[5].vertexNum / 2; i++)
//	{
//		glDrawArrays(GL_LINES, i * 2, 2);
//	}
//
//	m_program[5]->release();
//	m_VAO[5].release();
//}


void OpenGLWidget::initializeGL() {
	initializeOpenGLFunctions();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
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
	
	//if (bIs3dPointsSetted == true) {
	//	paintPoint();
	//}
}