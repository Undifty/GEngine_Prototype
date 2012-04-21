#ifndef ENTITY_H__
#define ENTITY_H__

#include "Vector.class.h"

class Entity
{
private:
	Point3f		position;
	Vector3f	facing;

public:
	Entity ( );
	virtual ~Entity ( );


	Point3f*		getPoint		( );
	Vector3f*		getFacing		( );
	void			setFacingPoint	( Point3f* );
	void			setPoint		( Point3f* );
	void			setFacing		( Vector3f* );
};

#endif