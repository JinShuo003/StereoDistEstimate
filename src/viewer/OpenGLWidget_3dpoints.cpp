#include "OpenGLWidget.h"
#include "iostream"

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

	m_camera.move(-6, 0, 2);
	m_camera.look(0, 30, 0);
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

void OpenGLWidget::SetPointData(std::vector<cv::Point3d> v3dPoints)
{
	if (vertexData[3].vertex != Q_NULLPTR) {
		delete[] vertexData[3].vertex;
	}
	vertexData[3].vertex = new float[v3dPoints.size()*3*2];
	for (int i = 0; i < v3dPoints.size(); i++)
	{
		vertexData[3].vertex[6 * i] = 0;
		vertexData[3].vertex[6 * i + 1] = 0; 
		vertexData[3].vertex[6 * i + 2] = 0;
		vertexData[3].vertex[6 * i + 3] = v3dPoints[i].x;
		vertexData[3].vertex[6 * i + 4] = -v3dPoints[i].y;
		vertexData[3].vertex[6 * i + 5] = -v3dPoints[i].z;
	}
	vertexData[3].pointDim = 3;
	vertexData[3].vertexNum = v3dPoints.size() * 2 * vertexData[3].pointDim;
	vertexData[3].lenth = vertexData[3].vertexNum * sizeof(float);

	cout << "vertex_point: " << endl;
	cout << "vertexData.vertexNum: " << vertexData[3].vertexNum << endl;
	cout << "vertexData.lenth: " << vertexData[3].lenth << endl;
	for (int i = 0; i < vertexData[3].vertexNum; i++)
	{
		cout << vertexData[3].vertex[i] << ',';
		if ((i + 1) % vertexData[3].pointDim == 0) {
			cout << endl;
		}
	}

	initPoint();
	bIs3dPointsSetted = true;
}

void OpenGLWidget::GetLeftCamData()
{
	// 顶点缓存中前三个是顶点坐标, 后两个是纹理坐标, 一个顶点由5个float值组成
	static float vertex_leftCam[] = {
		0, 0, 0,
		-0.2, 0.1, 0.1,
		-0.2, -0.1, 0.1,

		0, 0, 0,
		-0.2, -0.1, 0.1,
		0.2, -0.1, 0.1,

		0, 0, 0,
		0.2, -0.1, 0.1,
		0.2, 0.1, 0.1,

		0, 0, 0,
		-0.2, 0.1, 0.1,
		0.2, 0.1, 0.1,
	};
	vertexData[0].pointDim = 3;
	vertexData[0].vertex = vertex_leftCam;
	vertexData[0].vertexNum = sizeof(vertex_leftCam) / sizeof(float) / vertexData[0].pointDim;
	vertexData[0].lenth = sizeof(vertex_leftCam);

	cout << "left camera: " << endl;
	cout << "vertexData.vertexNum: " << vertexData[0].vertexNum << endl;
	cout << "vertexData.lenth: " << vertexData[0].lenth << endl;
	for (int i = 0; i < vertexData[0].vertexNum; i++)
	{
		cout << vertexData[0].vertex[i] << ',';
		if ((i + 1) % vertexData[0].pointDim == 0) {
			cout << endl;
		}
	}
}

void OpenGLWidget::GetRightCamData()
{
	// 顶点缓存中前三个是顶点坐标, 后两个是纹理坐标, 一个顶点由5个float值组成
	static float vertex_rightCam[] = {
		0, 0, 0,
		-0.2, 0.1, 0.1,
		-0.2, -0.1, 0.1,

		0, 0, 0,
		-0.2, -0.1, 0.1,
		0.2, -0.1, 0.1,

		0, 0, 0,
		0.2, -0.1, 0.1,
		0.2, 0.1, 0.1,

		0, 0, 0,
		-0.2, 0.1, 0.1,
		0.2, 0.1, 0.1,
	};
	for (int i = 0; i < 12; i++)
	{
		vertex_rightCam[3 * i] += fCamOffset;
	}
	vertexData[1].pointDim = 3;
	vertexData[1].vertex = vertex_rightCam;
	vertexData[1].vertexNum = sizeof(vertex_rightCam) / sizeof(float) / vertexData[1].pointDim;
	vertexData[1].lenth = sizeof(vertex_rightCam);

	cout << "right camera: " << endl;
	cout << "vertexData.vertexNum: " << vertexData[1].vertexNum << endl;
	cout << "vertexData.lenth: " << vertexData[1].lenth << endl;
	for (int i = 0; i < vertexData[1].vertexNum; i++)
	{
		cout << vertexData[1].vertex[i] << ',';
		if ((i + 1) % vertexData[1].pointDim == 0) {
			cout << endl;
		}
	}
}

void OpenGLWidget::GetCoorData()
{
	// 顶点缓存中前三个是顶点坐标, 后两个是纹理坐标, 一个顶点由5个float值组成
	static float vertex_coor[] = {
		//向右
		0, 0, 0,
		0.5, 0, 0,

		//向上
		0, 0, 0,
		0, 0.5, 0,

		//向前
		0, 0, 0,
		0, 0, -0.5,
	};
	vertexData[2].pointDim = 3;
	vertexData[2].vertex = vertex_coor;
	vertexData[2].vertexNum = sizeof(vertex_coor) / sizeof(float) / vertexData[2].pointDim;
	vertexData[2].lenth = sizeof(vertex_coor);

	cout << "coor: " << endl;
	cout << "vertexData.vertexNum: " << vertexData[2].vertexNum << endl;
	cout << "vertexData.lenth: " << vertexData[2].lenth << endl;
	for (int i = 0; i < vertexData[2].vertexNum; i++)
	{
		cout << vertexData[2].vertex[i] << ',';
		if ((i + 1) % vertexData[2].pointDim == 0) {
			cout << endl;
		}
	}
}

void OpenGLWidget::GetPointData()
{
	// 顶点缓存中前三个是顶点坐标, 后两个是纹理坐标, 一个顶点由5个float值组成
	static float vertex_point[] = {
		0, 0, 0,
		0.5, 0.2, -1.6,

		0, 0, 0,
		-0.5, -0.2, -1.7,

		0, 0, 0,
		0.3, 0.6, -2.6,
	};

	vertexData[3].pointDim = 3;
	vertexData[3].vertex = vertex_point;
	vertexData[3].vertexNum = sizeof(vertex_point) / sizeof(float);
	vertexData[3].lenth = sizeof(vertex_point);

	cout << "vertex_point: " << endl;
	cout << "vertexData.vertexNum: " << vertexData[3].vertexNum << endl;
	cout << "vertexData.lenth: " << vertexData[3].lenth << endl;
	for (int i = 0; i < vertexData[3].vertexNum; i++)
	{
		cout << vertexData[3].vertex[i] << ',';
		if ((i + 1) % vertexData[3].pointDim == 0) {
			cout << endl;
		}
	}
}

void OpenGLWidget::initLeftCam()
{
	m_VAO[0].create();
	m_VBO[0].create();

	QString sVertexShaderName = "transform.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "transform.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program[0].addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program[0].addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);

	m_program[0].link();

	m_VAO[0].bind();
	m_VBO[0].bind();

	m_VBO[0].allocate(vertexData[0].vertex, vertexData[0].lenth);

	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有5个float数据, 所以下一个数据需要偏移5 * sizeof(float)个字节
	m_program[0].setAttributeBuffer("vPos", GL_FLOAT, 0, 3, 0);
	m_program[0].enableAttributeArray("vPos");

	m_program[0].release();
	m_VAO[0].release();
}

void OpenGLWidget::initRightCam()
{
	m_VAO[1].create();
	m_VBO[1].create();

	QString sVertexShaderName = "transform.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "transform.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program[1].addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program[1].addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);

	m_program[1].link();

	m_VAO[1].bind();
	m_VBO[1].bind();

	m_VBO[1].allocate(vertexData[1].vertex, vertexData[1].lenth);

	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有5个float数据, 所以下一个数据需要偏移5 * sizeof(float)个字节
	m_program[1].setAttributeBuffer("vPos", GL_FLOAT, 0, 3, 0);
	m_program[1].enableAttributeArray("vPos");

	m_program[1].release();
	m_VAO[1].release();
}

void OpenGLWidget::initCoor()
{
	m_VAO[2].create();
	m_VBO[2].create();

	QString sVertexShaderName = "transform.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "transform.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program[2].addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program[2].addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);

	m_program[2].link();

	m_VAO[2].bind();
	m_VBO[2].bind();

	m_VBO[2].allocate(vertexData[2].vertex, vertexData[2].lenth);

	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有5个float数据, 所以下一个数据需要偏移5 * sizeof(float)个字节
	m_program[2].setAttributeBuffer("vPos", GL_FLOAT, 0, 3, 0);
	m_program[2].enableAttributeArray("vPos");

	//// 顶点颜色
	//GLfloat colors[] = {
	//	1.0f, 0.0f, 0.0f,
	//	1.0f, 0.0f, 0.0f,

	//	0.0f, 1.0f, 0.0f,
	//	0.0f, 1.0f, 0.0f,

	//	0.0f, 0.0f, 1.0f,
	//	0.0f, 0.0f, 1.0f,
	//};

	//m_VBO[2].write(6 * sizeof(GLfloat), colors, 12 * sizeof(GLfloat));
	//GLuint vColor = m_program[2].attributeLocation("vColor");
	//m_program[2].setAttributeBuffer(vColor, GL_FLOAT, 6 * sizeof(GLfloat), 3, 0);
	//glEnableVertexAttribArray(vColor);

	m_program[2].release();
	m_VAO[2].release();
}

void OpenGLWidget::initPoint()
{
	//若已创建过，则全部释放
	if (m_VAO[3].isCreated()) {
		m_VAO[3].release();
	}
	if (m_VBO[3].isCreated()) {
		m_VBO[3].release();
	}

	m_VAO[3].create();
	m_VBO[3].create();
	
	QString sVertexShaderName = "transform.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "transform.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program[3].addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program[3].addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);

	m_program[3].link();


	m_VAO[3].bind();
	m_VBO[3].bind();

	m_VBO[3].allocate(vertexData[3].vertex, vertexData[3].lenth);

	// 绑定顶点坐标信息
	m_program[3].setAttributeBuffer("vPos", GL_FLOAT, 0, 3, 0);
	m_program[3].enableAttributeArray("vPos");

	m_program[3].release();
	m_VAO[3].release();
}

void OpenGLWidget::paintCam(UINT8 area)
{
	m_VAO[area].bind();
	m_program[area].bind();
	// 绑定变换矩阵
	m_program[area].setUniformValue("projection", m_projection);
	m_program[area].setUniformValue("view", m_camera.view());
	m_program[area].setUniformValue("model", m_model);

	// 绘制
	for (int i = 0; i < 4; i++)
	{
		glDrawArrays(GL_LINE_LOOP, i * 3, 3);
	}

	m_program[area].release();
	m_VAO[area].release();
}

void OpenGLWidget::paintCoor()
{
	m_VAO[2].bind();
	m_program[2].bind();
	// 绑定变换矩阵
	m_program[2].setUniformValue("projection", m_projection);
	m_program[2].setUniformValue("view", m_camera.view());
	m_program[2].setUniformValue("model", m_model);

	// 绘制
	for (int i = 0; i < 4; i++)
	{
		glDrawArrays(GL_LINES, i * 2, 2);
	}

	m_program[2].release();
	m_VAO[2].release();
}

void OpenGLWidget::paintPoint()
{
	m_VAO[3].bind();
	m_program[3].bind();
	// 绑定变换矩阵
	m_program[3].setUniformValue("projection", m_projection);
	m_program[3].setUniformValue("view", m_camera.view());
	m_program[3].setUniformValue("model", m_model);

	// 绘制
	for (int i = 0; i < vertexData[3].vertexNum/2; i++)
	{
		glDrawArrays(GL_LINES, i * 2, 2);
	}

	m_program[3].release();
	m_VAO[3].release();
}

void OpenGLWidget::initializeGL() {
	initializeOpenGLFunctions();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0, 0.5, 0.7, 1);

	initLeftCam();
	initRightCam();
	initCoor();
}

void OpenGLWidget::resizeGL(int w, int h)
{
	m_projection.setToIdentity();
	m_projection.perspective(60, (float)w / h, 0.001, 1000);
}

void OpenGLWidget::paintGL() {
	paintCam(m_leftORright::left);
	paintCam(m_leftORright::right);
	paintCoor();
	if (bIs3dPointsSetted == true) {
		paintPoint();
	}
}