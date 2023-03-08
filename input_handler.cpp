#include "input_handler.h"

InputHandler::InputHandler() {
}


InputHandler::~InputHandler() {
}

void InputHandler::handle_inputs(Player *player) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player->velocity.x =-player->speed;
		player->velocity.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player->velocity.x =player->speed;
		player->velocity.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player->velocity.y =-player->speed;
		player->velocity.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player->velocity.y =player->speed;
		player->velocity.x = 0;
	}

}
