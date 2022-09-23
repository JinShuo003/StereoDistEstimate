#include "OpenGLWidget.h"
#include "iostream"

using std::cout;
using std::endl;

OpenGLWidget::OpenGLWidget(QWidget* parent):
	QOpenGLWidget(parent)
{
	GetData();
}

OpenGLWidget::~OpenGLWidget()
{
	delete vertexData.data;
}

void OpenGLWidget::GetData()
{
	//       位置             颜色
	static float _vertex[] = {
		-0.5, 0.5, 0.0,     1.0, 0.0, 0.0,
		-0.5, -0.5, 0.0,    0.0, 1.0, 0.0,
		 0.5, -0.5, 0.0,    0.0, 0.0, 1.0,
		 0.5, 0.5, 0.0,     1.0, 1.0, 1.0
	};

	vertexData.data = _vertex;
	vertexData.vertexNum = sizeof(_vertex) / sizeof(float);
	vertexData.lenth = sizeof(_vertex);

	cout << "vertexData.vertexNum: " << vertexData.vertexNum << endl;
	cout << "vertexData.lenth: " << vertexData.lenth << endl;
	for (int i = 0; i < vertexData.vertexNum; i++)
	{
		cout << vertexData.data[i] << ',';
		if ((i + 1) % 6 == 0) {
			cout << endl;
		}
	}
	
}

void OpenGLWidget::initializeGL() {
	initializeOpenGLFunctions();
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0.5, 0.7, 1);

	m_VAO.create();
	m_VBO.create();

	QString sVertexShaderName = "test.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "test.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);

	m_program.link();

	m_VAO.bind();
	m_VBO.bind();

	m_VBO.allocate(vertexData.data, vertexData.lenth);

	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有5个float数据, 所以下一个数据需要偏移5 * sizeof(float)个字节
	m_program.bind();
	m_program.setAttributeBuffer("vPos", GL_FLOAT, 0 * sizeof(float), 3, 6 * sizeof(float));
	m_program.enableAttributeArray("vPos");
	m_program.setAttributeBuffer("vColor", GL_FLOAT, 3 * sizeof(float), 3, 6 * sizeof(float));
	m_program.enableAttributeArray("vColor");

	m_program.release();
	m_VAO.release();
}

void OpenGLWidget::resizeGL(int w, int h)
{
}


void OpenGLWidget::paintGL() {
	m_VAO.bind();
	m_program.bind();

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	m_program.release();
	m_VAO.release();
}