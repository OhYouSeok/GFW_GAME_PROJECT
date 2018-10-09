#include <iostream>
#include <vector>

#include "SDL.h"

class Game;

class InputHandler {
public:
	static InputHandler * Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void claen() {};

	bool isKeyDown(SDL_Scancode key);
	const Uint8* m_keystates;
	void onKeyDown();
	void onKeyUp();

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler * s_pInstance;
};
typedef InputHandler TheInputHandler;
