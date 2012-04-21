#include "Entity.class.h"

/* Constructor */		Entity::Entity		( )
{
	position	= Point3f( 0, 0, 0 );
	facing		= Vector3f( 0, 0, 30 );
};


/* Destructor */		Entity::~Entity		( )
{

};


Point3f*				Entity::getPoint			( )
{
	return &(this->position);
};


Vector3f*				Entity::getFacing			( )
{
	return &(this->facing);
};


/*
*	Sets the facing of the unit to target point.
*/
void					Entity::setFacingPoint		( Point3f* p_TargetPoint )
{
	// Create a temporary vector.
	Vector3f tmp(
		p_TargetPoint->x - position.x,
		p_TargetPoint->y - position.y,
		p_TargetPoint->z - position.z
	);
	tmp.normalize();

	// Apply the new values.
	facing.x = tmp.x;
	facing.y = tmp.y;
	facing.z = tmp.z;
};


void					Entity::setPoint			( Point3f *p_NewPoint )
{
	position.x = (p_NewPoint->x);
	position.y = (p_NewPoint->y);
	position.z = (p_NewPoint->z);
};


void					Entity::setFacing			( Vector3f *p_NewFacing )
{
	facing.x = (p_NewFacing->x);
	facing.y = (p_NewFacing->y);
	facing.z = (p_NewFacing->z);
};

