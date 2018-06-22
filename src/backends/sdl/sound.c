/*
 * Copyright (C) 1997-2001 Id Software, Inc.
 * Copyright (C) 2010, 2013 Yamagi Burmeister
 * Copyright (C) 2005 Ryan C. Gordon
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
 * USA.
 *
 * =======================================================================
 *
 * SDL sound backend. Since SDL is just an API for sound playback, we
 * must caculate everything in software: mixing, resampling, stereo
 * spartializations, etc. Therefor this file is rather complex. :)
 * Samples are read from the cache (see the upper layer of the sound
 * system), manipulated and written into sound.buffer. sound.buffer is
 * passed to SDL (in fact requested by SDL via the callback) and played
 * with a platform dependend SDL driver. Parts of this file are based
 * on ioQuake3s snd_sdl.c.
 *
 * =======================================================================
 */

/* SDL includes */
#ifdef SDL2
#include <SDL2/SDL.h>
#else // SDL1.2
#include <SDL/SDL.h>
#endif //SDL2

/* Local includes */
#include "../../client/header/client.h"
#include "../../client/sound/header/local.h"


/* ------------------------------------------------------------------ */

/* End of low-pass filter stuff */
/* ============================ */

/*
 * Transfers a mixed "paint buffer" to
 * the SDL output buffer and places it
 * at the appropriate position.
 */
void
SDL_TransferPaintBuffer(int endtime)
{

}

/*
 * Mixes an 8 bit sample into a channel.
 */
void
SDL_PaintChannelFrom8(channel_t *ch, sfxcache_t *sc, int count, int offset)
{

}

/*
 * Mixes an 16 bit sample into a channel
 */
void
SDL_PaintChannelFrom16(channel_t *ch, sfxcache_t *sc, int count, int offset)
{

}

/*
 * Mixes all pending sounds into
 * the available output channels.
 */
void
SDL_PaintChannels(int endtime)
{

}


/*
 * Spatialize a sound effect based on it's origin.
 */
void
SDL_SpatializeOrigin(vec3_t origin, float master_vol, float dist_mult,
		int *left_vol, int *right_vol)
{

}

/*
 * Spatializes a channel.
 */
void
SDL_Spatialize(channel_t *ch)
{
}

/*
 * Entities with a "sound" field will generated looped sounds
 * that are automatically started, stopped, and merged together
 * as the entities are sent to the client
 */
void
SDL_AddLoopSounds(void)
{

}

/*
 * Clears the playback buffer so
 * that all playback stops.
 */
void
SDL_ClearBuffer(void)
{

}

/*
 * Calculates the absolute timecode
 * of current playback.
 */
void
SDL_UpdateSoundtime(void)
{

}

/*
 * Updates the volume scale table
 * based on current volume setting.
 */
void
SDL_UpdateScaletable(void)
{

}

/*
 * Saves a sound sample into cache. If
 * necessary endianess convertions are
 * performed.
 */
qboolean
SDL_Cache(sfx_t *sfx, wavinfo_t *info, byte *data)
{

	return true;
}

/*
 * Playback of "raw samples", e.g. samples
 * without an origin entity. Used for music
 * and cinematic playback.
 */
void
SDL_RawSamples(int samples, int rate, int width,
		int channels, byte *data, float volume)
{

}

/*
 * Runs every frame, handles all necessary
 * sound calculations and fills the play-
 * back buffer.
 */
void
SDL_Update(void)
{

}

/* ------------------------------------------------------------------ */

/*
 * Gives information over user
 * defineable variables
 */
void
SDL_SoundInfo(void)
{
	
}


/*
 * Initializes the SDL sound
 * backend and sets up SDL.
 */
qboolean
SDL_BackendInit(void)
{

	return 1;
}

/*
 * Shuts the SDL backend down.
 */
void
SDL_BackendShutdown(void)
{

}

int
SDL_DriftBeginofs(float timeofs)
{}
