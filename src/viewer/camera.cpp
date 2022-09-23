#include "viewer/camera.h"
#include "iostream"

using std::cout;
using std::endl;

Camera::Camera(QObject* parent) {

}

Camera::~Camera() {

}

void Camera::move(float x, float y, float z)
{
	auto _right = QVector3D::crossProduct(m_front, m_up).normalized();
	auto _front = QVector3D::crossProduct(m_up, _right).normalized();
	m_pos += _front * x;
	m_pos += _right * y;
	m_pos += m_up * z;
}

void Camera::reset(float x, float y, float z, float yaw, float pitch, float roll)
{
	m_move = QVector3D(0, 0, 0);
	m_pos = QVector3D(0, 0, 0);
	m_front = QVector3D(0, 0, -1);
	m_up = QVector3D(0, 1, 0);
	m_yaw = 0.f;
	m_pitch = 0.f;
	m_roll = 0.f;

	move(x, y, z);
	look(yaw, pitch, roll);
	update();
}

void Camera::look(float yaw, float pitch, float roll)
{
	m_yaw += yaw;
	while (m_yaw >= 360)
		m_yaw -= 360;
	while (m_yaw < 0)
		m_yaw += 360;

	m_pitch += pitch;
	if (m_pitch > 89)
		m_pitch = 89;
	if (m_pitch < -89)
		m_pitch = -89;
	{
		QVector3D _front{ 0,0,-1 };
		QMatrix4x4 _mat;
		_mat.setToIdentity();
		_mat.rotate(m_pitch, 1, 0, 0);
		_mat.rotate(m_yaw, 0, 1, 0);
		m_front = _front * _mat;
	}
}

void Camera::update()
{
	auto _move = m_move.normalized() * m_moveSpeed;
	move(_move.x(), _move.y(), _move.z());

	m_view.setToIdentity();
	m_view.lookAt(m_pos, m_pos + m_front, m_up);
}

bool Camera::eventFilter(QObject* obj, QEvent* ev)
{
	auto _widget = qobject_cast<QOpenGLWidget*>(obj);
	if (_widget)
	{
		//当按下鼠标左键时，记录动作，记录点击的位置，获取焦点
		if (ev->type() == QEvent::MouseButtonPress)
		{
			auto event = static_cast<QMouseEvent*>(ev);
			if (event->button() == Qt::LeftButton) {
				m_isLeftMouseBtnPressed = true;
				m_pressLocation = event->pos();
			}
		}
		//当松开鼠标左键时，记录动作
		else if (ev->type() == QEvent::MouseButtonRelease)
		{
			auto event = static_cast<QMouseEvent*>(ev);
			if (event->button() == Qt::LeftButton) {
				m_isLeftMouseBtnPressed = false;
			}
		}
		//当鼠标移动时，若左键已按下则更新look
		else if (ev->type() == QEvent::MouseMove)
		{
			auto event = static_cast<QMouseEvent*>(ev);
			_widget->setMouseTracking(true);
			if (m_isLeftMouseBtnPressed) {
				auto _move = event->pos() - m_pressLocation;
				look(_move.x() * m_lookSpeed, _move.y() * m_lookSpeed, 0);
				m_pressLocation = event->pos();
			}
		}
		//键盘按下
		else if (ev->type() == QEvent::KeyPress)
		{
			auto event = static_cast<QKeyEvent*>(ev);
			if (event->key() == Qt::Key_W)
			{
				m_move.setX(1);
			}
			else if (event->key() == Qt::Key_S)
			{
				m_move.setX(-1);
			}
			else if (event->key() == Qt::Key_A)
			{
				m_move.setY(-1);
			}
			else if (event->key() == Qt::Key_D)
			{
				m_move.setY(1);
			}
			else if (event->key() == Qt::Key_Q)
			{
				m_move.setZ(1);
			}
			else if (event->key() == Qt::Key_E)
			{
				m_move.setZ(-1);
			}
			else if (event->key() == Qt::Key_Space)
			{
				reset(-2, 0, 0.5, 0, 10, 0);
				update();
			}
		}
		else if (ev->type() == QEvent::KeyRelease)
		{
			auto event = static_cast<QKeyEvent*>(ev);
			if (event->key() == Qt::Key_W)
			{
				m_move.setX(0);
			}
			else if (event->key() == Qt::Key_S)
			{
				m_move.setX(0);
			}
			else if (event->key() == Qt::Key_A)
			{
				m_move.setY(0);
			}
			else if (event->key() == Qt::Key_D)
			{
				m_move.setY(0);
			}
			else if (event->key() == Qt::Key_Q)
			{
				m_move.setZ(0);
			}
			else if (event->key() == Qt::Key_E)
			{
				m_move.setZ(0);
			}
		}
		update();
		_widget->update();
	}

	/*if (_widget)
	{
		if (ev->type() == QEvent::KeyPress)
		{
			auto event = static_cast<QKeyEvent*>(ev);
			if (event->key() == Qt::Key_Escape)
			{
				_widget->setMouseTracking(false);
				_widget->setCursor(Qt::ArrowCursor);
			}
			else if (event->key() == Qt::Key_W)
			{
				m_move.setX(1);
			}
			else if (event->key() == Qt::Key_S)
			{
				m_move.setX(-1);
			}
			else if (event->key() == Qt::Key_A)
			{
				m_move.setY(-1);
			}
			else if (event->key() == Qt::Key_D)
			{
				m_move.setY(1);
			}
			else if (event->key() == Qt::Key_Space)
			{
				m_move.setZ(1);
			}
			else if (event->key() == Qt::Key_C)
			{
				m_move.setZ(-1);
			}
		}
		else if (ev->type() == QEvent::KeyRelease)
		{
			auto event = static_cast<QKeyEvent*>(ev);
			if (event->key() == Qt::Key_W)
			{
				m_move.setX(0);
			}
			else if (event->key() == Qt::Key_S)
			{
				m_move.setX(0);
			}
			else if (event->key() == Qt::Key_A)
			{
				m_move.setY(0);
			}
			else if (event->key() == Qt::Key_D)
			{
				m_move.setY(0);
			}
			else if (event->key() == Qt::Key_Space)
			{
				m_move.setZ(0);
			}
			else if (event->key() == Qt::Key_C)
			{
				m_move.setZ(0);
			}
		}
		else if (ev->type() == QEvent::MouseButtonPress)
		{
			auto _lastPos = _widget->mapToGlobal(_widget->rect().center());
			QCursor::setPos(_lastPos);

			_widget->setMouseTracking(true);
			_widget->setCursor(Qt::BlankCursor);
		}
		else if (ev->type() == QEvent::MouseMove)
		{
			auto event = static_cast<QMouseEvent*>(ev);
			auto _lastPos = _widget->mapToGlobal(_widget->rect().center());
			QCursor::setPos(_lastPos);

			auto _move = event->globalPos() - _lastPos;
			look(_move.x() * m_lookSpeed, _move.y() * m_lookSpeed, 0);
		}
		else if (ev->type() == QEvent::Leave)
		{
			_widget->setMouseTracking(false);
			_widget->setCursor(Qt::ArrowCursor);
		}
	}*/
	return false;
}
