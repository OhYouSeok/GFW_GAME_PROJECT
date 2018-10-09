#include "Player.h"

Player::Player(const LoaderParams * pParams) : SDLGameObject(pParams) {

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_acceleration.setX(1);

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_velocity.setX(-2);
	}
	SDLGameObject::update();
}

void Player::clean() {

}