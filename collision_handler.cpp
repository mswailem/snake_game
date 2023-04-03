#include "collision_handler.h"
#include <cmath>
#include <iostream>


CollisionHandler::~CollisionHandler() {
}

CollisionHandler::CollisionHandler(){
}

void CollisionHandler::detect_collisions(Player* player, Food* food, sf::VideoMode vm) {
	//Check if the player is colliding with the walls
	if (player->right_edge +(player->width * player->velocity.x)>= vm.width || player->left_edge + (player->width * player->velocity.x) <= 0){
		player->velocity.x = 0;
	}
	if (player->bot_edge + (player->width * player->velocity.y) >= vm.height || player->top_edge + (player->width * player->velocity.y) <= 0)	{
		player->velocity.y = 0;
	}

	//Check if the player is colliding with itself
	for (int s = 3; s < player->size; s++) {
		float dx = player->position[s].x - player->position[0].x;
		int sign_dx = dx != 0? ceil(dx/std::abs(dx)) : 0;
		float dy = player->position[s].y - player->position[0].y;
		int sign_dy = dy != 0? ceil(dy/std::abs(dy)) : 0;
		if (std::abs(dx) < (player->width) + sign_dx*(player->width * player->velocity.x) && std::abs(dy) < (player->height/2+player->height/2) + sign_dy*(player->width * player->velocity.y)) {
			std::cout << "You lose!" << std::endl; //TODO: Make this a game over screen
		}
	}

	//Check if the player is colliding with the food
	float dx = player->position[0].x - food->position.x;
	int sign_dx = ceil(dx/std::abs(dx));
	float dy = player->position[0].y - food->position.y;
	int sign_dy = ceil(dy/std::abs(dy));
	if (std::abs(dx) <= (player->width/2+food->width/2) - sign_dx*(player->width * player->velocity.x) && std::abs(dy) <= (player->height/2+food->height/2) - sign_dy*(player->width * player->velocity.y)) {
		food->reposition();
		player->shape.push_back(sf::RectangleShape());
		player->position.push_back(player->position[player->size-1]+sf::Vector2f(player->right_edge, 0));
		player->shape[player->size].setSize(sf::Vector2f(player->width,player->height));
		player->shape[player->size].setOrigin(player->width/2,player->height/2);
		player->size += 1;
	}
}
