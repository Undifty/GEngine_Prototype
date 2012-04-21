#include "Camera.class.h"

/* Constructor */		Camera::Camera			( )
{
	m_position	= Point3f( 0, 1, 0 );
	m_target	= Vector3f( 0, -5, 30 );
	m_target.normalize();
	m_right		= Vector3f( 1, 0, 0 );
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


void					Camera::render			( )
{
	m_target.render( &m_position, 1.0, 0.5, 0.5 );
	m_right.render( &m_position, 0.5, 1.0, 0.5 );
	m_up.render( &m_position, 0.5, 0.5, 1.0 );
};

void					Camera::setTarget		( Point3f *p_Target, float p_Dist )
{
	Point3f new_cam_pos = *(p_Target);

	Vector3f mod = m_target;
	mod.normalize();
	mod = mod * p_Dist;

	new_cam_pos = new_cam_pos - mod;

	m_position = new_cam_pos;
	debug_log( "cam_target: " + m_target.toString() );
	debug_log( "cam position: " + m_position.toString() );
};


void					Camera::rotateLeft		( float rad )
{
	double x = m_target.x;
	double z = m_target.z;
		
	m_target.x = ( x * cos(rad) - z * sin(rad) );
	m_target.z = ( z * cos(rad) + x * sin(rad) );
	m_target.normalize();
};