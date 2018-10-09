#pragma once

#ifndef Game_h
#define Game_h

#include "header.h"
#include "TextureManager.h"
#include "GameStateMachine.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	Game();
	~Game();

	bool init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void handleEvents();
	void render();
	void clean();
	bool running() { return IsRunning; }

	static Game * Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	SDL_Renderer * getRenderer() const { return renderer; }

private:
	static Game * s_pInstance;
	bool IsRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
	enum game_states {
		MENU = 0,
		PLAY = 1,
		GAMEOVER=2
	};
	int m_currentFrame;
	int m_currentState;
	std::vector<GameObject *> m_gameObjects;
	GameStateMachine * m_pGameStateMachine;
};
typedef Game TheGame;
#endif