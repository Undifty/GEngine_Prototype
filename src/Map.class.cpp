#include "Map.class.h"


/* Constructor */		Map::Map		( )
{
	map_width	= 1;
	map_height	= 1;

	vertices.push_back( MapVertex( 0, 0, 0 ) );
	vertices.push_back( MapVertex( map_width, 0, 0 ) );
	vertices.push_back( MapVertex( 0, map_height, 0 ) );
	vertices.push_back( MapVertex( map_width, map_height, 0 ) );
};


/* Destructor */		Map::~Map		( )
{
};


void					Map::render		( )
{
	glBegin(GL_TRIANGLE_FAN);

    glVertex3f(-1.0f, -0.5f, -4.0f);    // A
    glVertex3f( 1.0f, -0.5f, -4.0f);    // B
    glVertex3f( 0.0f,  0.5f, -4.0f);    // C

    glVertex3f(-1.5f,  0.0f, -4.0f);    // D
    glVertex3f(-1.8f, -1.0f, -4.0f);    // E
    glVertex3f( 0.2f, -1.5f, -4.0f);    // F

    glVertex3f( 1.0f, -0.5f, -4.0f);    // G

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