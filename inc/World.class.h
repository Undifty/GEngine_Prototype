#ifndef WORLD_H__
#define WORLD_H__

#include "Entity.class.h"
#include "Map.class.h"

class World
{
private:
	Map*		world_map;

public:
	World ( );
	virtual ~World ( );

	void		render		( );
};

#endif