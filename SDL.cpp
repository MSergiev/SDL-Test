//============================================================================
// Name        : SDL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "SDL.h"

SDL::SDL() {
	Surf_Display = NULL;
	Surf_Grid = NULL;
	Surf_X = NULL;
	Surf_O = NULL;
	Surf_X_Win = NULL;
	Surf_O_Win = NULL;
	Surf_Draw = NULL;
	isRunning = true;
	CurrentPlayer = true;
	remaining = 9;
}

int SDL::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(isRunning) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

void SDL::Reset() {
    for(int i = 0;i < 3;i++) {
    	for(int j = 0; j < 3; j++){
    		Grid[i][j] = GRID_TYPE_NONE;
    	}
    }
    remaining = 9;
}

void SDL::SetCell(int row, int column, int Type) {
    if(row < 0 || column < 0 || row >= 3 || column >= 3) return;
    if(Type < 0 || Type > GRID_TYPE_O_HOVER) return;

    Grid[row][column] = Type;
}

int main() {

	cout << "Begin\n";
    SDL theApp;

    return theApp.OnExecute();
}
