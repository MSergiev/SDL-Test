run: SDL.cpp CEvent.cpp CSurface.cpp SDL_OnRender.cpp SDL_OnCleanup.cpp SDL_OnEvent.cpp SDL_OnInit.cpp SDL_OnLoop.cpp
	g++ -o run SDL.cpp CEvent.cpp CSurface.cpp SDL_OnRender.cpp SDL_OnCleanup.cpp SDL_OnEvent.cpp SDL_OnInit.cpp SDL_OnLoop.cpp -lSDL
