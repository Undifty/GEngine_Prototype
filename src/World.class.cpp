#include "World.class.h"

/* Constructor */		World::World		( )
{
	world_map = new Map();
};


/* Destructor */		World::~World		( )
{
	delete world_map;
	world_map = NULL;
};



void					World::render		( )
{
	world_map->render();
};



Map*				World::getMap		( )
{
	return this->world_map;
};