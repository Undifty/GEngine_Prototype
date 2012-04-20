#include "Map.class.h"


/* Constructor */		Map::Map		( )
{
	map_width	= 32;
	map_height	= 32;


	for ( int z=0 ; z<map_height-1 ; z++ )
	{
		for ( int x=0 ; x<map_width ; x++ )
		{
			vertices.push_back( MapVertex( x, 0.0f, z ) );
			vertices.push_back( MapVertex( x, 0.0f, z+1.0 ) );
		}
	}

	/*
	vertices.push_back( MapVertex( 0, 0.0f, 0 ) );
	vertices.push_back( MapVertex( map_width, 0.0f, 0 ) );
	vertices.push_back( MapVertex( map_width, +0.0f, map_height ) );
	vertices.push_back( MapVertex( 0, +0.0f, map_height ) );
	*/
};


/* Destructor */		Map::~Map		( )
{
};


void					Map::render		( )
{
	float r[] = {1.0, 1.0, 0.0, 0.0};
	float g[] = {1.0, 0.0, 1.0, 0.0};
	float b[] = {1.0, 0.0, 0.0, 1.0};

	GFX::Wireframe( true );
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.5f, 0.5f, 0.5f);
		int n= vertices.size();
		MapVertex v(0,0,0);
		for ( int i=0 ; i<n ; i++ )
		{
			//glColor3f( r[i], g[i], b[i] );
			v = vertices[i];
			glVertex3f( v.x, v.y, v.z );
		}
	glEnd();
	GFX::Wireframe( false );
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