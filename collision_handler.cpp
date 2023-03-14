#include "collision_handler.h"
#include <cmath>


CollisionHandler::~CollisionHandler() {
}

CollisionHandler::CollisionHandler(){
}

void CollisionHandler::detect_collisions(Player* player, Food* food, sf::VideoMode vm) {
	if (player->right_edge +(player->width * player->velocity.x)>= vm.width || player->left_edge + (player->width * player->velocity.x) <= 0){
		player->velocity.x = 0;
	}
	if (player->bot_edge + (player->width * player->velocity.y) >= vm.height || player->top_edge + (player->width * player->velocity.y) <= 0)	{
		player->velocity.y = 0;
	}
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
