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
	//���������ȡ����
	void mousePressEvent(QMouseEvent* event);
	//������ά������
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
	//�����
	enum m_leftORright { left = 0, right = 1 };
	Q_ENUM(m_leftORright)

	//���
	Camera m_camera;

private:
	//��������
	VertexData vertexData[4];
	//���������������ƫ��
	float fCamOffset = 1.0;
	//��ִ���ļ�Ŀ¼
	QString sExePath = QCoreApplication::applicationDirPath();
	//������ɫ��
	QString m_sVertexShader;
	//��Ƭ��ɫ��
	QString m_sFragmentShader;
	//0.������ 1.�Ҳ���� 2.������ 3.��ͼ��
	QOpenGLVertexArrayObject m_VAO[4];
	QOpenGLBuffer m_VBO[4];
	QOpenGLShaderProgram m_program[4];
	//texture
	QOpenGLTexture* m_texture = Q_NULLPTR;

	//�任����
	QMatrix4x4 m_projection;
	QMatrix4x4 m_view;
	QMatrix4x4 m_model;

	//��ת�Ƕ�
	float m_angle = 0;

	//��ά�������Ƿ�������
	bool bIs3dPointsSetted = false;

};

