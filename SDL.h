/*
 * SDL.h
 *
 *  Created on: Apr 1, 2017
 *      Author: ADMIN
 */

#ifndef SDL_H_
#define SDL_H_

#include <SDL/SDL.h>
#include "CSurface.h"
#include "CEvent.h"
#include <iostream>
using std::cout;
using std::endl;

class SDL : public CEvent {
private:
	bool isRunning;
	SDL_Surface* Surf_Display;
	SDL_Surface* Surf_Grid;
	SDL_Surface* Surf_X;
	SDL_Surface* Surf_O;
	SDL_Surface* Surf_X_Win;
	SDL_Surface* Surf_O_Win;
	SDL_Surface* Surf_Draw;
	int Grid[3][3];
	bool CurrentPlayer;
	int remaining;
	enum {
	    GRID_TYPE_NONE,
	    GRID_TYPE_X,
	    GRID_TYPE_O,
	    GRID_TYPE_X_HOVER,
	    GRID_TYPE_O_HOVER
	};

public:
	SDL();
	int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLButtonDown(int mX, int mY);
    void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
    void OnExit();
    void OnLoop();
    void OnRender();
    void OnCleanup();
    void Reset();
    void SetCell(int row, int column, int Type);
    void OnWin(bool Player);
};

#endif /* SDL_H_ */

