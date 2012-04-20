#include "Actor.class.h"

/* Constructor */	Actor::Actor		( )
{
	owner				= NULL;
	actor_offset		= Point3f(0, 0, 0);
	actor_type			= ACTORTYPE_MODEL;
	actor_placement		= ACTORPLACEMENT_ABSOLUTE;
	actor_flag.visible	= true;
	actor_flag.active	= false;
};


/* Destructor */	Actor::~Actor		( )
{
};


void				Actor::setType		( ActorType_e p_Type )
{
	actor_type = p_Type;
};


void				Actor::setOwner		( Entity *p_Owner )
{
	owner = p_Owner;
};


void				Actor::setOffset	( ActorPlacement_e p_Placement, Point3f p_Offset )
{
	actor_placement = p_Placement;
	actor_offset	= p_Offset;
};


void				Actor::render		( )
{
	Point3f real_point = actor_offset;
	if ( actor_placement == ACTORPLACEMENT_RELATIVE && owner != NULL )
	{
			real_point += *(owner->getPoint());


	}
};