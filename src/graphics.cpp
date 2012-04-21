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
		gluPerspective( 45.0f, screen_ratio, 1.0, 1024.0 );

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
};