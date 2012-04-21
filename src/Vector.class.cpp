#include "Vector.class.h"


/*
*	Point2f
*/
Point2f::Point2f ( )
{
	x = y = 0;
}

Point2f::Point2f ( float p_X, float p_Y )
{
	x = p_X;
	y = p_Y;
}

std::string		Point2f::toString		( )
{
	std::string str = "(" + f2s( x ) + ", " + f2s( y ) + ")";
	return str;
}

Point2f			Point2f::operator+		( Point2f p )
{
	return Point2f( x+p.x, y+p.y );
}

Point2f			Point2f::operator-		( Point2f p )
{
	return Point2f( x-p.x, y-p.y );
}

Point2f			Point2f::operator*		( float f )
{
	return Point2f( x*f, y*f );
}

Point2f			Point2f::operator/		( float f )
{
	return Point2f( x/f, y/f );
}

Point2f			Point2f::operator=		( Point2f p )
{
	x = p.x;
	y = p.y;
	return *this;
}



/*
*	Point3f
*/
Point3f::Point3f ( )
{
	x = y = z = 0;
}

Point3f::Point3f ( float p_X, float p_Y, float p_Z )
{
	x = p_X;
	y = p_Y;
	z = p_Z;
}

std::string		Point3f::toString		( )
{
	std::string str = "(" + f2s( x ) + ", " + f2s( y ) + ", " + f2s( z ) + ")";
	return str;
}

Point3f			Point3f::operator+		( Point3f p )
{
	return Point3f( x+p.x, y+p.y, z+p.z );
}

Point3f			Point3f::operator+=		( Point3f p )
{
	x += p.x;
	y += p.y;
	z += p.z;
	return *this;
}

Point3f			Point3f::operator-		( Point3f p )
{
	return Point3f( x-p.x, y-p.y, z-p.z );
}

Point3f			Point3f::operator-=		( Point3f p )
{
	x -= p.x;
	y -= p.y;
	z -= p.z;
	return *this;
}

Point3f			Point3f::operator*		( float f )
{
	return Point3f( x*f, y*f, z*f );
}

Point3f			Point3f::operator/		( float f )
{
	return Point3f( x/f, y/f, z/f );
}

Point3f			Point3f::operator=		( Point3f p )
{
	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
}



/*
*	Vector2f
*/
Vector2f::Vector2f ( )
	: Point2f ( )
{
}

Vector2f::Vector2f ( float p_X, float p_Y )
	: Point2f ( p_X, p_Y )
{
}

Vector2f		Vector2f::operator+		( Vector2f p )
{
	return Vector2f( x+p.x, y+p.y );
}

Vector2f		Vector2f::operator-		( Vector2f p )
{
	return Vector2f( x-p.x, y-p.y );
}

Vector2f		Vector2f::operator*		( float f )
{
	return Vector2f( x*f, y*f );
}

Vector2f		Vector2f::operator/		( float f )
{
	return Vector2f( x/f, y/f );
}

Vector2f		Vector2f::operator=		( Vector2f p )
{
	x = p.x;
	y = p.y;
	return *this;
}

void			Vector2f::normalize		( )
{
	x /= length();
	y /= length();
}

float			Vector2f::length		( )
{
	return sqrt((x*x) + (y*y));
}

float			Vector2f::length2		( )
{
	return (x*x) + (y*y);
}

void			Vector2f::negate		( )
{
	x = -x;
	y = -y;
}

Vector2f			Vector2f::crossWith		( Vector2f v )
{
	return Vector2f(
		(v.y) - (y),
		(x) - (v.x)
	);
}

double				Vector2f::dotProduct	( Vector2f v )
{
	return (x * v.x) + (y * v.y);
}



/*
*	Vector3f
*/
Vector3f::Vector3f ( )
	: Point3f ( )
{
}

Vector3f::Vector3f ( float p_X, float p_Y, float p_Z )
	: Point3f ( p_X, p_Y, p_Z )
{
}

Vector3f		Vector3f::operator+		( Vector3f p )
{
	return Vector3f( x+p.x, y+p.y, z+p.z );
}

Vector3f		Vector3f::operator-		( Vector3f p )
{
	return Vector3f( x-p.x, y-p.y, z-p.z );
}

Vector3f		Vector3f::operator*		( float f )
{
	return Vector3f( x*f, y*f, z*f );
}

Vector3f		Vector3f::operator/		( float f )
{
	return Vector3f( x/f, y/f, z/f );
}

Vector3f		Vector3f::operator=		( Vector3f p )
{
	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
}

Vector3f		Vector3f::operator=		( Point3f p )
{
	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
}

void			Vector3f::normalize		( )
{
	x /= length();
	y /= length();
	z /= length();
}

float			Vector3f::length		( )
{
	return sqrt((x*x) + (y*y) + (z*z));
}

float			Vector3f::length2		( )
{
	return (x*x) + (y*y) + (z*z);
}

void			Vector3f::negate		( )
{
	x = -x;
	y = -y;
	z = -z;
}

Vector3f			Vector3f::crossWith		( Vector3f v )
{
	return Vector3f(
		(v.y * z) - (v.z * y),
		(v.z * x) - (v.x * x),
		(v.x * y) - (v.y * z)
	);
}

double				Vector3f::dotProduct	( Vector3f v )
{
	return (x * v.x) + (y * v.y) + (z * v.z);
}



void				Vector3f::render		( Point3f * p )
{
	this->render( p,  1.0f, 1.0f, 1.0f );
};


void				Vector3f::render		( Point3f * p, float r, float g, float b )
{
	float radius = 0.1;
	glBegin( GL_LINE_LOOP );
		glColor3f( r, g, b );
		float max = 2*PI;
		float step = PI/36.0;
		for ( float i=0 ; i<max ; i+=step )
		{
			glVertex3f( p->x + sin(i) * radius, p->y + cos(i) * radius, p->z );
		}
	glEnd();

	glBegin( GL_LINES );
		glColor3f( r, g, b );
		glVertex3f( p->x, p->y, p->z );
		glVertex3f( x + p->x, y + p->y, z + p->z );
	glEnd();
};