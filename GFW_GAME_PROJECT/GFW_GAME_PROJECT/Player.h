#include "GameObject.h"

class Player :public GameObject {
public:
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer * pRenderer);
	void update() {
		m_x = 10;
		m_y = 20;
	}
	void clean() {
		GameObject::clean();
	}
};
