#pragma once

#include "opencv2/opencv.hpp"

#include "QOpenGLWidget"
#include "QOpenGLExtraFunctions"
#include "QOpenGLVertexArrayObject"
#include "QOpenGLBuffer"
#include "QOpenGLShaderProgram"
#include "QCoreApplication"
#include "QOpenGLTexture"

#include "camera.h"

typedef struct {
	float* vertex = Q_NULLPTR;
	int pointDim;
	int vertexNum;
	int lenth;
}VertexData;

class OpenGLWidget: public QOpenGLWidget, public QOpenGLExtraFunctions
{
	Q_OBJECT
public:
	OpenGLWidget(QWidget* parent = nullptr);
	~OpenGLWidget();
	//鼠标点击，获取焦点
	void mousePressEvent(QMouseEvent* event);
	//设置三维点数据
	void SetPointData(std::vector<cv::Point3d> v3dPoints);

protected:
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;

private:
	//get data
	void GetLeftCamData();
	void GetRightCamData();
	void GetCoorData();
	void GetPointData();
	//initialize
	void initLeftCam();
	void initRightCam();
	void initCoor();
	void initPoint();
	//paint
	void paintCam(UINT8 area);
	void paintCoor();
	void paintPoint();

public:
	//左或右
	enum m_leftORright { left = 0, right = 1 };
	Q_ENUM(m_leftORright)

	//相机
	Camera m_camera;

private:
	//顶点数据
	VertexData vertexData[4];
	//右相机相对左相机的偏移
	float fCamOffset = 1.0;
	//可执行文件目录
	QString sExePath = QCoreApplication::applicationDirPath();
	//顶点着色器
	QString m_sVertexShader;
	//面片着色器
	QString m_sFragmentShader;
	//0.左侧相机 1.右侧相机 2.坐标轴 3.地图点
	QOpenGLVertexArrayObject m_VAO[4];
	QOpenGLBuffer m_VBO[4];
	QOpenGLShaderProgram m_program[4];
	//texture
	QOpenGLTexture* m_texture = Q_NULLPTR;

	//变换矩阵
	QMatrix4x4 m_projection;
	QMatrix4x4 m_view;
	QMatrix4x4 m_model;

	//旋转角度
	float m_angle = 0;

	//三维点数据是否已设置
	bool bIs3dPointsSetted = false;

};

