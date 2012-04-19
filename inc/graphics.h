#ifndef GRAPHICS_H__
#define GRAPHICS_H__

#include <SDL.h>
#include <SDL_opengl.h>
#include <gl/GL.h>
#include <gl/GLU.h>
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

	};

	void	Init	( );
	void	Tidy	( );
};

#endif