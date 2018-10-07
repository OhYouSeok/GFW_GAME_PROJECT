#include "Game.h"

Game * game = 0;

int main(int argc, char * argv[]) {
	game = new Game();
	game->init("Run For Your Life !", 250, 50, 1024, 768, 0);
	while (game->running() == true) {
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();

	return 0;
}