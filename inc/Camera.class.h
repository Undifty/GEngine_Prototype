#ifndef CAMERA_H__
#define CAMERA_H__

#include "Vector.class.h"

class Camera
{
private:
	Point3f		m_position;
	Vector3f	m_target;
	Vector3f	m_right;
	Vector3f	m_up;

public:
	Camera ( );
	virtual ~Camera ( );

	Vector3f*	getTarget ( );
	Vector3f*	getUp ( );
	Point3f*	getPoint ( );

	void		rotateLeft ( float );

	void		setTarget ( Point3f *, float );

	void		render	( );
};

#endif