/*
 * SDL__OnRender.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: ADMIN
 */

#include "SDL.h"

void SDL::OnRender() {
    CSurface::OnDraw(Surf_Display, Surf_Grid, 0, 0);

    if(remaining <= 0){
    	cout << "Draw\n";
		CSurface::OnDraw(Surf_Display, Surf_Draw, 0, 200);
		SDL_Flip(Surf_Display);
		SDL_Delay(2000);
		Reset();
		return;
    }

    for(int i = 0; i < 3; i++) {
    	for(int j = 0; j < 3; j++){
			if(Grid[i][j] == GRID_TYPE_X_HOVER) {
				CSurface::Alpha(Surf_X, 100);
				CSurface::OnDraw(Surf_Display, Surf_X, i*200, j*200);
			}else if(Grid[i][j] == GRID_TYPE_O_HOVER) {
				CSurface::Alpha(Surf_O, 100);
				CSurface::OnDraw(Surf_Display, Surf_O, i*200, j*200);
			}else if(Grid[i][j] == GRID_TYPE_X) {
				CSurface::Alpha(Surf_X, 255);
				CSurface::OnDraw(Surf_Display, Surf_X, i*200, j*200);
			}else if(Grid[i][j] == GRID_TYPE_O) {
				CSurface::Alpha(Surf_O, 200);
				CSurface::OnDraw(Surf_Display, Surf_O, i*200, j*200);
			}

			if(Grid[i][j]==GRID_TYPE_X){
				if((Grid[(i+1)%3][j]==GRID_TYPE_X && Grid[(i+2)%3][j]==GRID_TYPE_X) ||
				   (Grid[i][(j+1)%3]==GRID_TYPE_X && Grid[i][(j+2)%3]==GRID_TYPE_X) ||
				   (Grid[(i+1)%3][(j+1)%3]==GRID_TYPE_X && Grid[(i+2)%3][(j+2)%3]==GRID_TYPE_X)){
					cout << "X wins\n";
					CSurface::OnDraw(Surf_Display, Surf_X_Win, 0, 200);
					SDL_Flip(Surf_Display);
					SDL_Delay(2000);
					Reset();
					return;
				}
			} else if(Grid[i][j]==GRID_TYPE_O){
				if((Grid[(i+1)%3][j]==GRID_TYPE_O && Grid[(i+2)%3][j]==GRID_TYPE_O) ||
				   (Grid[i][(j+1)%3]==GRID_TYPE_O && Grid[i][(j+2)%3]==GRID_TYPE_O) ||
				   (Grid[(i+1)%3][(j+1)%3]==GRID_TYPE_O && Grid[(i+2)%3][(j+2)%3]==GRID_TYPE_O)){
					cout << "O wins\n";
					CSurface::OnDraw(Surf_Display, Surf_O_Win, 0, 200);
					SDL_Flip(Surf_Display);
					SDL_Delay(2000);
					Reset();
					return;
				}
			} else if((Grid[0][2]==GRID_TYPE_X && Grid[1][1]==GRID_TYPE_X && Grid[2][0]==GRID_TYPE_X)){
				cout << "X wins\n";
				CSurface::OnDraw(Surf_Display, Surf_X_Win, 0, 200);
				SDL_Flip(Surf_Display);
				SDL_Delay(2000);
				Reset();
				return;
			} else if((Grid[0][2]==GRID_TYPE_O && Grid[1][1]==GRID_TYPE_O && Grid[2][0]==GRID_TYPE_O)){
				cout << "O wins\n";
				CSurface::OnDraw(Surf_Display, Surf_O_Win, 0, 200);
				SDL_Flip(Surf_Display);
				SDL_Delay(2000);
				Reset();
				return;
			}
    	}
    }


	SDL_Flip(Surf_Display);
}
