/*
 * Copyright (C) 2010 Yamagi Burmeister
 * Copyright (C) 1997-2001 Id Software, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *
 * ----------------------------------------------------------------------
 *
 * CalculateGammaRamp() is derived from SDL2's SDL_CalculateGammaRamp()
 * (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>
 * Published under zlib License: http://www.libsdl.org/license.php
 *
 * =======================================================================
 *
 * This file implements an OpenGL context and window handling through
 * SDL. The code is complicated by supporting the fairly different SDL
 * 1.2 and SDL 2 APIs, each with hardware gamma or software gamma by
 * RANDR.
 *
 * =======================================================================
 */

#include "../../common/header/common.h" /* CVar_*, qboolean (through shared.h) */
#include "../../client/header/ref.h"


#include <SDL/SDL.h>

static SDL_Surface* window = NULL;
cvar_t *vid_displayrefreshrate;

/*
 * Initializes the SDL video subsystem
 */
int
GLimp_Init(void)
{
	vid_displayrefreshrate = Cvar_Get("vid_displayrefreshrate", "-1", CVAR_ARCHIVE);

	if (!SDL_WasInit(SDL_INIT_VIDEO))
	{

		if (SDL_Init(SDL_INIT_VIDEO) == -1)
		{
			Com_Printf("Couldn't init SDL video: %s.\n", SDL_GetError());
			return false;
		}
	}

	return true;
}



static qboolean CreateSDLWindow(int flags, int w, int h)
{
	window = SDL_SetVideoMode(w, h, 16, SDL_SWSURFACE);
	return window != NULL;
}

static qboolean GetWindowSize(int* w, int* h)
{
	if(window == NULL || w == NULL || h == NULL)
		return false;

	*w = window->w;
	*h = window->h;

	return true;
}

static qboolean initSuccessful = false;

/*
 * Initializes the OpenGL window
 */
qboolean
GLimp_InitGraphics(int fullscreen, int *pwidth, int *pheight)
{
	int flags;
	int curWidth, curHeight;
	int width = *pwidth;
	int height = *pheight;
	unsigned int fs_flag = 0;

	/* Is the surface used? */
	if (window)
	{
		SDL_FreeSurface(window);
		window = NULL;
	}

	/* Create the window */
	VID_NewWindow(width, height);

	/* No cursor */
	SDL_ShowCursor(0);

	initSuccessful = true;

	return true;
}

/*
 * (Un)grab Input
 */
void GLimp_GrabInput(qboolean grab)
{
}

int glimp_refreshRate = -1;

/*
 * Returns the current display refresh rate.
 */
int GLimp_GetRefreshRate(void)
{
	if (vid_displayrefreshrate->value > -1)
	{
		glimp_refreshRate = ceil(vid_displayrefreshrate->value);
	}

	// Asume 60hz.
	return 60;
}

/*
 * Shuts the SDL render backend down
 */
void
VID_ShutdownWindow(void)
{
	if (window)
	{
		/* cleanly ungrab input (needs window) */
		GLimp_GrabInput(false);
		SDL_FreeSurface(window);
	}

	window = NULL;
	// make sure that after vid_restart the refreshrate will be queried from SDL2 again.
	glimp_refreshRate = -1;

	initSuccessful = false; // not initialized anymore

	if (SDL_WasInit(SDL_INIT_VIDEO) == SDL_INIT_VIDEO)
	{
		SDL_Quit();
	}
	else
	{
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}
}
