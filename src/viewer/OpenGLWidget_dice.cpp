#include "OpenGLWidget.h"
#include "iostream"

using std::cout;
using std::endl;

OpenGLWidget::OpenGLWidget(QWidget* parent):
	QOpenGLWidget(parent)
{
	GetData();

	m_camera.move(-6, 0, 3);
	m_camera.look(0, 30, 0);
	m_camera.update();

	installEventFilter(&m_camera);
}

OpenGLWidget::~OpenGLWidget()
{

}

void OpenGLWidget::GetData()
{
	// 顶点缓存中前三个是顶点坐标, 后两个是纹理坐标, 一个顶点由5个float值组成
	static float _vertex[] = {
		//顶点					纹理
		// 1
			-1,  1,  1,		0.50, 0.25,	// 左上
			-1, -1,  1,		0.50, 0.50,	// 左下
			 1, -1,  1,		0.75, 0.50,	// 右下
			 1,  1,  1,		0.75, 0.25,  // 右上
		// 6
			 1,  1, -1,		0.00, 0.25,	// 左上
			 1, -1, -1,		0.00, 0.50,	// 左下
			-1, -1, -1,		0.25, 0.50,	// 右下
			-1,  1, -1,		0.25, 0.25,	// 右上
		// 2
			 1,	 1,  1,		0.75, 0.25,  // 左上
			 1,	-1,  1,		0.75, 0.50,	// 左下
			 1,	-1, -1,		1.00, 0.50,	// 右下
			 1,	 1, -1,		1.00, 0.25,	// 右上
		// 5
			-1,  1, -1,		0.25, 0.25,	// 左上
			-1, -1, -1,		0.25, 0.50,	// 左下
			-1, -1,  1,		0.50, 0.50,	// 右下
			-1,  1,  1,		0.50, 0.25,	// 右上
		// 3
			-1,  1, -1,		0.00, 0.00,	// 左上
			-1,  1,  1,		0.00, 0.25,	// 左下
			 1,  1,  1,		0.25, 0.25,  // 右下
			 1,  1, -1,		0.25, 0.00,	// 右上
		// 4
			-1, -1,  1,		0.00, 0.50,  // 左上
			-1, -1, -1,		0.00, 0.75,	// 左下
			 1, -1, -1,		0.25, 0.75,	// 右下
			 1, -1,  1,		0.25, 0.50,	// 右上
	};

	vertexData.pointDim = 5;
	vertexData.vertex = _vertex;
	vertexData.vertexNum = sizeof(_vertex) / sizeof(float);
	vertexData.lenth = sizeof(_vertex);

	cout << "vertexData.vertexNum: " << vertexData.vertexNum << endl;
	cout << "vertexData.lenth: " << vertexData.lenth << endl;
	for (int i = 0; i < vertexData.vertexNum; i++)
	{
		cout << vertexData.vertex[i] << ',';
		if ((i + 1) % vertexData.pointDim == 0) {
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

	QString sVertexShaderName = "transform.vert";
	QString sVertexShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sVertexShaderName);
	QString sFragShaderName = "transform.frag";
	QString sFragShaderPath = QString("%1/shader/%2").arg(sExePath).arg(sFragShaderName);
	m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, sVertexShaderPath);
	m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, sFragShaderPath);

	m_program.link();

	m_VAO.bind();
	m_VBO.bind();

	m_VBO.allocate(vertexData.vertex, vertexData.lenth);

	// 绑定顶点坐标信息, 从0 * sizeof(float)字节开始读取3个float, 因为一个顶点有5个float数据, 所以下一个数据需要偏移5 * sizeof(float)个字节
	m_program.setAttributeBuffer("vPos", GL_FLOAT, 0 * sizeof(float), 3, 5 * sizeof(float));
	m_program.enableAttributeArray("vPos");
	// 绑定纹理坐标信息, 从3 * sizeof(float)字节开始读取2个float, 因为一个顶点有5个float数据, 所以下一个数据需要偏移5 * sizeof(float)个字节
	m_program.setAttributeBuffer("vTexture", GL_FLOAT, 3 * sizeof(float), 2, 5 * sizeof(float));
	m_program.enableAttributeArray("vTexture");

	QString sTextureName = "dice.png";
	QString sTextureFullPath = QString("%1/texture/%2").arg(sExePath).arg(sTextureName);
	m_texture = new QOpenGLTexture(QImage(sTextureFullPath));

	m_program.release();
	m_VAO.release();
}

void OpenGLWidget::resizeGL(int w, int h)
{
	m_projection.setToIdentity();
	m_projection.perspective(60, (float)w / h, 0.001, 1000);
}


void OpenGLWidget::paintGL() {
	m_texture->bind();
	m_VAO.bind();
	m_program.bind();
	// 绑定变换矩阵
	m_program.setUniformValue("projection", m_projection);
	m_program.setUniformValue("view", m_camera.view());
	m_program.setUniformValue("model", m_model);

	// 绘制
	for (int i = 0; i < 6; ++i)
	{
		glDrawArrays(GL_TRIANGLE_FAN, i * 4, 4);
	}

	m_program.release();
	m_VAO.release();
	m_texture->release();
}