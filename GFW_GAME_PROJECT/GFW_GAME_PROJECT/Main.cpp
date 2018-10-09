#include "Game.h"

int main(int argc, char * argv[]) {

	if (TheGame::Instance()->init("Living Dead Nightmare", 100, 100, 640, 480, false)) {
		while (TheGame::Instance()->running() == true) {
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
		}
		TheGame::Instance()->clean();
	}

	return 0;
}