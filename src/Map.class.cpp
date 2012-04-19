#include "Map.class.h"


/* Constructor */		Map::Map		( )
{
	map_width	= 16;
	map_height	= 16;

	/*
	vertices.push_back( MapVertex( -1.0f, -2.0f, -1.0f ) );
	vertices.push_back( MapVertex( +1.0f, -1.0f, -1.0f ) );
	vertices.push_back( MapVertex( -1.0f, +0.0f, +1.0f ) );
	vertices.push_back( MapVertex( +1.0f, +1.0f, +1.0f ) );
	*/

	vertices.push_back( MapVertex( 0, 0.0f, 0 ) );
	vertices.push_back( MapVertex( map_width, 0.0f, 0 ) );
	vertices.push_back( MapVertex( 0, +0.0f, map_height ) );
	vertices.push_back( MapVertex( map_width, +0.0f, map_height ) );
};


/* Destructor */		Map::~Map		( )
{
};


void					Map::render		( )
{
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.0f, 1.0f, 0.0f);
		int n= vertices.size();
		MapVertex v(0,0,0);
		for ( int i=0 ; i<n ; i++ )
		{
			v = vertices[i];
			glVertex3f( v.x, v.y, v.z );
		}
	glEnd();
};





/********************
*	MapVertex-class.
*********************/

/* Constructor */		MapVertex::MapVertex		( float p_X, float p_Y, float p_Z )
{
	x = p_X;
	y = p_Y;
	z = p_Z;
};


/* Destructor */		MapVertex::~MapVertex		( )
{
};