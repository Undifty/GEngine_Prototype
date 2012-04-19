#ifndef VECTOR_H__
#define VECTOR_H__

#include <iostream>
#include <cstring>
#include "common.h"

class Point2f
{
public:
	float x,y;

	// Constructors
	Point2f ( );
	Point2f ( float, float );

	// Operators
	Point2f operator-( Point2f );
	Point2f operator+( Point2f );
	Point2f operator*( float );
	Point2f operator/( float );
	Point2f operator=( Point2f );

	// Miscellaneous
	std::string		toString	( );
};



class Point3f
{
public:
	float x,y,z;

	// Constructors
	Point3f ( );
	Point3f ( float, float, float );

	// Operators
	Point3f operator-( Point3f );
	Point3f operator+( Point3f );
	Point3f operator*( float );
	Point3f operator/( float );
	Point3f operator=( Point3f );

	// Miscellaneous
	std::string		toString	( );
};



class Vector2f : public Point2f
{
public:
	// Constructors
	Vector2f ( );
	Vector2f ( float, float );
	
	// Operators
	Vector2f operator+( Vector2f );
	Vector2f operator-( Vector2f );
	Vector2f operator*( float );
	Vector2f operator/( float );
	Vector2f operator=( Vector2f );

	// Miscellaneous
	void			normalize	( );
	float			length		( );
	float			length2		( );
	void			negate		( );
	Vector2f		crossWith	( Vector2f );
	double			dotProduct	( Vector2f );
};



class Vector3f : public Point3f
{
public:
	// Constructors
	Vector3f ( );
	Vector3f ( float, float, float );

	// Operators
	Vector3f operator+( Vector3f );
	Vector3f operator-( Vector3f );
	Vector3f operator*( float );
	Vector3f operator/( float );
	Vector3f operator=( Vector3f );
	Vector3f operator=( Point3f );

	// Miscellaneous
	void			normalize		( );
	float			length			( );
	float			length2			( );
	void			negate			( );
	Vector3f		crossWith		( Vector3f );
	double			dotProduct		( Vector3f );
};

#endif