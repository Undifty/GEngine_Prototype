#ifndef GRAPHICS_H__
#define GRAPHICS_H__

#include <SDL.h>
#include <SDL_opengl.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <cmath>
#include "common.h"

namespace GFX
{
	namespace // Simulate private variables.
	{
		const SDL_VideoInfo*	video_info;
		int						screen_width;
		int						screen_height;
		int						screen_depth;
		int						screen_flags;
		float					screen_ratio;
		bool					render_wireframe;
	};

	void	Init		( );
	void	Tidy		( );

	void	Prepare2D	( );
	void	Prepare3D	( );

	int		GetWidth	( );
	int		GetHeight	( );

	void	Wireframe	( bool );

	void	SetPixel	( SDL_Surface*, int, int, Uint32 );
	Uint32	GetPixel	( SDL_Surface*, int, int );
	int		GetBlue		( Uint32 );
	int		GetGreen	( Uint32 );
	int		GetRed		( Uint32 );
};

#endif