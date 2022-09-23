#pragma once

#include "QOpenGLWidget"
#include "QOpenGLExtraFunctions"
#include "QOpenGLVertexArrayObject"
#include "QOpenGLBuffer"
#include "QOpenGLShaderProgram"
#include "QCoreApplication"
#include "QOpenGLTexture"

#include "camera.h"

typedef struct {
	float* data;
	int vertexNum;
	int lenth;
}VertexData;

class OpenGLWidget: public QOpenGLWidget, public QOpenGLExtraFunctions
{
	Q_OBJECT
public:
	OpenGLWidget(QWidget* parent = nullptr);
	~OpenGLWidget();
	void GetData();

protected:
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;

private:
	VertexData vertexData;
	//可执行文件目录
	QString sExePath = QCoreApplication::applicationDirPath();
	//顶点着色器
	QString m_sVertexShader;
	//面片着色器
	QString m_sFragmentShader;
	//vao vbo shaderProgram
	QOpenGLVertexArrayObject m_VAO;
	QOpenGLBuffer m_VBO;
	QOpenGLShaderProgram m_program;

};

