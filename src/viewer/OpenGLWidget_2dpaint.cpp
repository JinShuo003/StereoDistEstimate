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
	static float _vertex[] = {
		-0.5, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0,
		 0.5, 0.5, 0.0
	};

	vertexData.data = _vertex;
	vertexData.vertexNum = sizeof(_vertex) / sizeof(float);
	vertexData.lenth = sizeof(_vertex);

	cout << "vertexData.vertexNum: " << vertexData.vertexNum << endl;
	cout << "vertexData.lenth: " << vertexData.lenth << endl;
	for (int i = 0; i < vertexData.vertexNum; i++)
	{
		cout << vertexData.data[i] << ',';
		if ((i + 1) % 3 == 0) {
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

	// �󶨶���������Ϣ, ��0 * sizeof(float)�ֽڿ�ʼ��ȡ3��float, ��Ϊһ��������5��float����, ������һ��������Ҫƫ��5 * sizeof(float)���ֽ�
	m_program.bind();
	m_program.setAttributeBuffer("vPos", GL_FLOAT, 0, 3, 0);
	m_program.enableAttributeArray("vPos");

	m_program.release();
	m_VAO.release();
}

void OpenGLWidget::resizeGL(int w, int h)
{
	//m_projection.setToIdentity();
	//m_projection.perspective(60, (float)w / h, 0.001, 1000);

	//m_model.setToIdentity();
	//m_model.rotate(m_angle, 0, 1, 0);
}


void OpenGLWidget::paintGL() {
	//m_texture->bind();
	m_VAO.bind();
	m_program.bind();

	//// �󶨱任����
	//m_shader.setUniformValue("projection", m_projection);
	//m_shader.setUniformValue("view", m_view);
	//m_shader.setUniformValue("model", m_model);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	m_program.release();
	m_VAO.release();
	//m_texture->release();
}