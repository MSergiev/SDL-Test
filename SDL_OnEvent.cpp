/*
 * SDL_OnEvent.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: ADMIN
 */




#include "SDL.h"

void SDL::OnEvent(SDL_Event* Event) {
	 CEvent::OnEvent(Event);
}


void SDL::OnLButtonDown(int mX, int mY) {
    int row    = mX / 200;
    int column  = mY / 200;

    if(Grid[row][column] == GRID_TYPE_X || Grid[row][column] == GRID_TYPE_O) {
        return;
    }

    CurrentPlayer ? SetCell(row, column, GRID_TYPE_X) : SetCell(row, column, GRID_TYPE_O);
    CurrentPlayer = !CurrentPlayer;
    remaining--;
}

void SDL::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
    int row    = mX / 200;
    int column  = mY / 200;

    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < 3; j++){
    		if(Grid[i][j] == GRID_TYPE_X_HOVER || Grid[i][j] == GRID_TYPE_O_HOVER)
    			Grid[i][j] = GRID_TYPE_NONE;
    	}
    }

    if(Grid[row][column] == GRID_TYPE_NONE) {
            CurrentPlayer ? SetCell(row, column, GRID_TYPE_X_HOVER) : SetCell(row, column, GRID_TYPE_O_HOVER);
    }

}

void SDL::OnExit() {
    isRunning = false;
}
