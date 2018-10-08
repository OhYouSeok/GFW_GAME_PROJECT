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
	m_currentState = MENU;
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());
	//m_textureManager.load("assets/animate-alpha.png", "animate", renderer);
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
	switch (m_currentState) {
	case MENU:
		break;
	case PLAY:
		break;
	case GAMEOVER:
		break;
	default:
		break;
	}
}
void Game::render() {
	SDL_RenderClear(renderer);

	m_textureManager.draw("animate", 0, 0, 128, 82,renderer);
	m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, renderer);

	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}