#include "collision_handler.h"


CollisionHandler::~CollisionHandler() {
}

CollisionHandler::CollisionHandler(){
}

std::string CollisionHandler::detect_collisions(Player* player, Food* food, sf::VideoMode vm) {
	if (player->right_edge >= vm.width || player->bot_edge >= vm.height){
		player->position[0]  = player->previous_position;
		player->velocity.x = 0;
	}
	if (player->left_edge <= 0 || player->top_edge <= 0)	{
		player->position[0]  = player->previous_position;
		player->velocity.y = 0;
	}
	float dx = player->position[0].x - food->position.x;
	float dy = player->position[0].y - food->position.y;
	if (std::abs(dx) <= (player->width/2+food->width/2) && std::abs(dy) <= (player->height/2+food->height/2)) {
		food->reposition();
		player->shape.push_back(sf::RectangleShape());
		player->position.push_back(player->position[player->size-1]+sf::Vector2f(player->right_edge, 0));
		player->shape[player->size].setSize(sf::Vector2f(player->width,player->height));
		player->shape[player->size].setOrigin(player->width/2,player->height/2);
		player->size += 1;
	}
	return "NONE";
}
