/*
 * CApp_OnCleanup.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: ADMIN
 */



#include "SDL.h"

void SDL::OnCleanup() {
    //SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Surf_Grid);
    SDL_FreeSurface(Surf_X);
    SDL_FreeSurface(Surf_O);
    SDL_FreeSurface(Surf_X_Win);
    SDL_FreeSurface(Surf_O_Win);
    SDL_FreeSurface(Surf_Draw);
	SDL_Quit();
}
