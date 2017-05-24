/*
 * SDL_OnInit.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: ADMIN
 */


#include "SDL.h"

bool SDL::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    	cout << "SDL error\n";
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
    	cout << "Video mode error\n";
    	return false;
    }

    if((Surf_Grid = CSurface::OnLoad((char*)"grid.bmp")) == NULL) {
    	cout << "Image error\n";
        return false;
    }

    if((Surf_X = CSurface::OnLoad((char*)"x.bmp")) == NULL) {
    	cout << "Image error\n";
        return false;
    }

    if((Surf_O = CSurface::OnLoad((char*)"o.bmp")) == NULL) {
    	cout << "Image error\n";
        return false;
    }

    if((Surf_X_Win = CSurface::OnLoad((char*)"xw.bmp")) == NULL) {
    	cout << "Image error\n";
        return false;
    }

    if((Surf_O_Win = CSurface::OnLoad((char*)"ow.bmp")) == NULL) {
    	cout << "Image error\n";
        return false;
    }

    if((Surf_Draw = CSurface::OnLoad((char*)"dr.bmp")) == NULL) {
    	cout << "Image error\n";
        return false;
    }

    CSurface::Transparent(Surf_X, 255, 255, 255);
    CSurface::Transparent(Surf_O, 255, 255, 255);
    //CSurface::Transparent(Surf_Tiles, 30, 150, 150);
    Reset();

    return true;
}
