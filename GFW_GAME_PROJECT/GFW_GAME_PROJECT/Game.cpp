#include "Game.h"

Game::Game(){}
Game::~Game(){}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		renderer = SDL_CreateRenderer(window, -1, 0);
		IsRunning = true;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Game:: handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYUP :
			IsRunning = false;
			break;
		default:
			break;

		}
	}
			

}
void Game::update() {
}
void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}