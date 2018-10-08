#ifndef Game_h
#define Game_h

#include "header.h"
#include "TextureManager.h"
#include "GameStateMachine.h"

class Game {
public:
	Game();
	~Game();

	void init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void handleEvents();
	void render();
	void clean();
	bool running() { return IsRunning; }
private:
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
	TextureManager m_textureManager;
	GameStateMachine * m_pGameStateMachine;
};

#endif