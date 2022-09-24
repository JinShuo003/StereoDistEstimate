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

typedef struct VertexData {
	//顶点数据
	float* vertex = Q_NULLPTR;
	//每个顶点的数据维度
	int pointDim;
	//顶点总数
	int vertexNum;
	//数据总个数，=顶点总数*每个顶点维度
	int dataNum;
	//数据总大小，=数据总个数*单个数据大小
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
	void SetLineData(std::vector<cv::Point3d> v3dPoints, std::vector<cv::Scalar> vColor);
	//设置三维点数据
	void SetLineData(std::vector<cv::Point3d> v3dPoints, std::vector<float> vError);

protected:
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;

private:
	//get data
	void GetLeftCamData();
	void GetRightCamData();
	void GetCoorData();
	void GetGroundData();
	void GetPointData(std::vector<cv::Point3d> v3dPoints);
	//initialize
	void initData(UINT8 index);
	void initPointData();
	//paint
	void paintCam(UINT8 area);
	void paintCoor();
	void paintGround();
	void paintLine();
	void paintPoint();

public:
	//左或右
	enum m_dataIdx { left = 0, right = 1, coor = 2, ground = 3, point = 4};
	Q_ENUM(m_dataIdx)

	//相机
	Camera m_camera;

private:
	//顶点数据
	VertexData vertexData[6];
	//右相机相对左相机的偏移
	float fCamOffset = 1.0;
	//可执行文件目录
	QString sExePath = QCoreApplication::applicationDirPath();
	//顶点着色器
	QString m_sVertexShader;
	//面片着色器
	QString m_sFragmentShader;
	//0.左侧相机 1.右侧相机 2.坐标轴 3.地图点
	QOpenGLVertexArrayObject m_VAO[6];
	QOpenGLBuffer m_VBO[6];
	QOpenGLShaderProgram* m_program[6] = {Q_NULLPTR};
	//texture
	QOpenGLTexture* m_texture = Q_NULLPTR;

	//变换矩阵
	QMatrix4x4 m_projection;
	QMatrix4x4 m_view;
	QMatrix4x4 m_model;

	//旋转角度
	float m_angle = 0;

	//三维点数据是否已设置
	bool bIs3dLinesSetted = false;
	bool bIs3dPointsSetted = false;
};

