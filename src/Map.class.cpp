#include "Map.class.h"


/* Constructor */		Map::Map		( )
{
	map_width	= 32;
	map_height	= 32;

	float height = 0;

	for ( int row=0 ; row<map_height ; row++ )
	{
		vertices.push_back( Vertex_Arr1D() );
		for ( int col=0 ; col<map_width ; col++ )
		{
			vertices[row].push_back( MapVertex( col, height, row ) );
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
			v = &vertices[z+1][x];
			glVertex3f( v->x, v->y, v->z );

			v = &vertices[z][x];
			glVertex3f( v->x, v->y, v->z );
		}
		glEnd();
	}

	// Reset
	GFX::Wireframe( false );
};


void				Map::resizeCanvas		( int p_W, int p_H )
{
	bool x_more = p_W >= map_width;
	bool y_more = p_H >= map_height;
	float height = 0;

	if ( y_more )
	{
		for ( int row=map_height ; row<p_H ; row++ )
		{
			vertices.push_back( Vertex_Arr1D() );
			for ( int col=0 ; col<map_width ; col++ )
			{
				vertices[row].push_back( MapVertex( col, height, row ) );
			}
		}
	}

	if ( x_more )
	{
		for ( int row=0 ; row<p_H ; row++ )
		{
			vertices.push_back( Vertex_Arr1D() );
			for ( int col=map_width ; col<p_W ; col++ )
			{
				vertices[row].push_back( MapVertex( col, height, row ) );
			}
		}
	}

	map_height	= p_H;
	map_width	= p_W;
};


void					Map::parseHeightmap ( std::string p_Path, int p_X, int p_Y )
{
	SDL_Surface * bmp = NULL;
	bmp = SDL_LoadBMP( p_Path.c_str() );
	if ( bmp == NULL )
	{
		debug_log("Could not parse file `" + p_Path + "` as heightmap!");
		return;
	}

	float h, hs = 0.08;
	int bmp_w = bmp->w;
	int bmp_h = bmp->h;
	int bmp_x = 0;
	int bmp_y = 0;
	int start_x = (p_X < 0)? 0: p_X;
	int start_y = (p_Y < 0)? 0: p_Y;
	int stop_x	= (map_width < (start_x + bmp_w))? map_width: (start_x + bmp_w);
	int stop_y	= (map_height < (start_y + bmp_h))? map_height: (start_y + bmp_h);
	debug_log("bmp dimensions("+i2s(bmp_w)+", "+i2s(bmp_h)+")");

	Uint32 pixel = 0;
	for ( int row=start_y ; row<stop_y ; row++ )
	{
		bmp_y = row - start_y;
		for ( int col=start_x ; col<stop_x ; col++ )
		{
			bmp_x = col - start_x;
			pixel = GFX::GetPixel( bmp, bmp_x, bmp_y );
			h = GFX::GetBlue( pixel );
			vertices[row][col].y = h * hs - 10;
		}
	}

	SDL_FreeSurface( bmp );
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