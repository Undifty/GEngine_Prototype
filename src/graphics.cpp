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

		if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) die( "Could not initialize SDL!" );
		atexit( SDL_Quit );

		video_info = SDL_GetVideoInfo();
		if ( !video_info ) die( "Could not get VideoInfo!" );

		screen_width	= 640;
		screen_height	= 480;
		screen_depth	= video_info->vfmt->BitsPerPixel;
		screen_flags	= SDL_OPENGL;

		if ( SDL_SetVideoMode( 
				screen_width, 
				screen_height, 
				screen_depth, 
				screen_flags 
		) == 0 ) die( "Could not set VideoMode!" );

	};

	void	Tidy	( )
	{
	};
};