#include "Entity.class.h"

/* Constructor */		Entity::Entity		( )
{
	position	= new Point3f( 0, 0, 0 );
	facing		= new Vector3f( 1, 0, 0 );
};


/* Destructor */		Entity::~Entity		( )
{
	delete position;
	delete facing;

	position	= NULL;
	facing		= NULL;
};


Point3f*				Entity::getPoint			( )
{
	return this->position;
};


Vector3f*				Entity::getFacing			( )
{
	return this->facing;
};


/*
*	Sets the facing of the unit to target point.
*/
void					Entity::setFacingPoint		( Point3f* p_TargetPoint )
{
	// Create a temporary vector.
	Vector3f tmp(
		p_TargetPoint->x - position->x,
		p_TargetPoint->y - position->y,
		p_TargetPoint->z - position->z
	);
	tmp.normalize();

	// Apply the new values.
	facing->x = tmp.x;
	facing->y = tmp.y;
	facing->z = tmp.z;
};


