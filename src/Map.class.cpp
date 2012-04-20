#include "Map.class.h"


/* Constructor */		Map::Map		( )
{
	map_width	= 32;
	map_height	= 32;


	for ( int row=0 ; row<map_height ; row++ )
	{
		vertices.push_back( Vertex_Arr1D() );
		for ( int col=0 ; col<map_width ; col++ )
		{
			vertices[row].push_back( MapVertex( col, -1, row ) );
		}
	}
};


/* Destructor */		Map::~Map		( )
{
	for ( int row=0 ; row<map_height ; row++ )
	{
		vertices[row].clear();
	}
	vertices.clear();
};


void					Map::render		( )
{
	// Draw terrain as Wireframe
	GFX::Wireframe( true );

	MapVertex *v = NULL;
	glColor3f(0.5f, 0.5f, 0.5f);
	for ( int z=0 ; z<map_height-1 ; z++ )
	{
		glBegin(GL_TRIANGLE_STRIP);
		for ( int x=0 ; x<map_width ; x++ )
		{
			v = &vertices[z][x];
			glVertex3f( v->x, v->y, v->z );

			v = &vertices[z+1][x];
			glVertex3f( v->x, v->y, v->z );
		}
		glEnd();
	}

	// Reset
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