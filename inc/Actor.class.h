#ifndef ACTOR_H__
#define ACTOR_H__

#include "Entity.class.h"
#include "Vector.class.h"

enum ActorType_e{
	ACTORTYPE_MODEL, 
	ACTORTYPE_EFFECT, 
	ACTORTYPE_ATTACHMENT
};

enum ActorPlacement_e{
	ACTORPLACEMENT_ABSOLUTE, 
	ACTORPLACEMENT_RELATIVE
};


struct	ActorFlag_s
{
	bool	visible;
	bool	active;
};


class Actor
{
private:
	// The owner of the Actor.
	Entity*				owner;

	// Where to position the Actor.
	Point3f				actor_offset;
	ActorPlacement_e	actor_placement;

	// How the Actor is displayed.
	ActorType_e			actor_type;

	// Miscellaneous flags.
	ActorFlag_s			actor_flag;

public:
	Actor ( );
	virtual ~Actor ( );

	void			setType		( ActorType_e );
	void			setOwner	( Entity* );
	void			setOffset	( ActorPlacement_e, Point3f );

	void			render		( );
};

#endif