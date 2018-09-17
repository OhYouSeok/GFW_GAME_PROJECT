#ifndef Game_h
#define Game_h

#include <SDL.h>
#include<iostream>

class Game {
public:
	Game();
	~Game();

	void init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void handleEvents();
	void render();
	void clean();
	bool running() { return IsRunning };

private:
	bool IsRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif