#pragma once

#include <QObject>
#include <QMatrix4x4>
#include <QVector3D>
#include <QOpenGLWidget>
#include <QEvent>
#include <QKeyEvent>

class Camera : public QObject
{
	Q_OBJECT
public:
	Camera(QObject* parent = nullptr);
	~Camera();
	void look(float yaw, float pitch, float roll);
	void move(float x, float y, float z);
	void reset(float x, float y, float z, float yaw, float pitch, float roll);
	void update();
	QMatrix4x4 view() { return m_view; }
public:
	float m_moveSpeed = 0.f;
	float m_lookSpeed = 0.f;

protected:
	bool eventFilter(QObject* obj, QEvent* ev) override;

private:
	QMatrix4x4 m_view;
	QVector3D m_pos{ 0,0,0 };
	QVector3D m_front{ 0,0,-1 };
	QVector3D m_up{ 0,1,0 };
	QVector3D m_move{ 0,0,0 };
	float m_yaw = 0.f;
	float m_pitch = 0.f;
	float m_roll = 0.f;
	//鼠标是否被按下
	bool m_isLeftMouseBtnPressed = false;
	QPoint m_pressLocation;
};
