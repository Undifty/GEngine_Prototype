#include "graphics.h"

namespace GFX
{

	void	Init	( )
	{
		video_info		= NULL;
		screen_width	= 0;
		screen_height	= 0;
		screen_depth	= 0;
		screen_flags	= 0;
		screen_ratio	= 0;

		if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) die( "Could not initialize SDL!" );
		atexit( SDL_Quit );

		video_info = SDL_GetVideoInfo();
		if ( !video_info ) die( "Could not get VideoInfo!" );

		screen_width	= 640;
		screen_height	= 480;
		screen_ratio	= (float) screen_width / (float) screen_height;
		screen_depth	= video_info->vfmt->BitsPerPixel;
		screen_flags	= SDL_OPENGL;

		if ( SDL_SetVideoMode( 
				screen_width, 
				screen_height, 
				screen_depth, 
				screen_flags 
		) == 0 ) die( "Could not set VideoMode!" );

		// Setup OpenGL
		glShadeModel( GL_SMOOTH );

		glCullFace( GL_BACK );
		//glFrontFace( GL_CCW );
		glFrontFace( GL_CW );
		glEnable( GL_CULL_FACE );
		//glEnable( GL_LIGHTING );
		glEnable( GL_NORMALIZE );

		glClearColor( 0, 0, 0, 0 );
	};

	void	Tidy	( )
	{
		//SDL_Quit();
	};


	void	Prepare2D	( )
	{
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		gluOrtho2D( 0.0f, screen_width, screen_height, 0.0f );

		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
		glTranslatef( 0.375, 0.375, 0.0 );

		glDisable( GL_DEPTH_TEST );
	};

	void	Prepare3D	( )
	{
		glViewport(0, 0, screen_width, screen_height);
		glMatrixMode( GL_PROJECTION );

		glLoadIdentity();
		gluPerspective( 45.0f, screen_ratio, 0.1, 1024.0 );

		glDepthFunc( GL_LEQUAL );
		glEnable( GL_DEPTH_TEST );
	};


	void	Wireframe		( bool on )
	{
		render_wireframe = on;
		if ( on )
		{
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		}
		else
		{
			glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
		}
	};


	int		GetWidth		( )
	{
		return screen_width;
	};

	int		GetHeight		( )
	{
		return screen_height;
	};


	Uint32 GetPixel ( SDL_Surface * map, int p_x, int p_y )
	{
		int bpp = map->format->BytesPerPixel;
		Uint8 * p = (Uint8*) map->pixels + p_y * map->pitch + p_x * bpp;
    
		switch ( bpp )
		{
			case 1: 	return *p;
			case 2:	return *(Uint16*)p;
			case 3:	return SDL_BYTEORDER == SDL_BIG_ENDIAN? p[0]<<16 | p[1] << 8 | p[2]: p[0] | p[1] << 8 | p[2] << 16;
			case 4:	return *(Uint32*)p;
			default: 	return 0;
		}
	};
  
	void SetPixel ( SDL_Surface * p_s, int p_x, int p_y, Uint32 p_color )
	{
		Uint32* mem = (Uint32*) p_s->pixels;
		mem[ p_y * p_s->w + p_x ] = p_color;
	}

	int GetRed ( Uint32 i ) { return (i & 0x00FF0000) >> 16; };
	int GetGreen ( Uint32 i ) { return (i & 0x0000FF00) >> 8; };
	int GetBlue ( Uint32 i ) { return (i & 0x000000FF) >> 0; };
};