#include "Camera.class.h"

/* Constructor */		Camera::Camera			( )
{
	m_position	= Point3f( 0, 0, 0 );
	m_target	= Vector3f( 0, 1, 30 );
	m_right		= Vector3f( -1, 0, 0 );
	m_up		= Vector3f( 0, 1, 0 );
};


/* Destructor */		Camera::~Camera			( )
{
};


Vector3f*				Camera::getTarget		( )
{
	return &m_target;
};


Vector3f*				Camera::getUp		( )
{
	return &m_up;
};


Point3f*				Camera::getPoint		( )
{
	return &m_position;
};