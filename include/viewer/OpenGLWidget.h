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
	//��������
	float* vertex = Q_NULLPTR;
	//ÿ�����������ά��
	int pointDim;
	//��������
	int vertexNum;
	//�����ܸ�����=��������*ÿ������ά��
	int dataNum;
	//�����ܴ�С��=�����ܸ���*�������ݴ�С
	int lenth;
}VertexData;

class OpenGLWidget: public QOpenGLWidget, public QOpenGLExtraFunctions
{
	Q_OBJECT
public:
	OpenGLWidget(QWidget* parent = nullptr);
	~OpenGLWidget();
	//���������ȡ����
	void mousePressEvent(QMouseEvent* event);
	//������ά������
	void SetLineData(std::vector<cv::Point3d> v3dPoints, std::vector<cv::Scalar> vColor);
	//������ά������
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
	//�����
	enum m_dataIdx { left = 0, right = 1, coor = 2, ground = 3, point = 4};
	Q_ENUM(m_dataIdx)

	//���
	Camera m_camera;

private:
	//��������
	VertexData vertexData[6];
	//���������������ƫ��
	float fCamOffset = 1.0;
	//��ִ���ļ�Ŀ¼
	QString sExePath = QCoreApplication::applicationDirPath();
	//������ɫ��
	QString m_sVertexShader;
	//��Ƭ��ɫ��
	QString m_sFragmentShader;
	//0.������ 1.�Ҳ���� 2.������ 3.��ͼ��
	QOpenGLVertexArrayObject m_VAO[6];
	QOpenGLBuffer m_VBO[6];
	QOpenGLShaderProgram* m_program[6] = {Q_NULLPTR};
	//texture
	QOpenGLTexture* m_texture = Q_NULLPTR;

	//�任����
	QMatrix4x4 m_projection;
	QMatrix4x4 m_view;
	QMatrix4x4 m_model;

	//��ת�Ƕ�
	float m_angle = 0;

	//��ά�������Ƿ�������
	bool bIs3dLinesSetted = false;
	bool bIs3dPointsSetted = false;
};

