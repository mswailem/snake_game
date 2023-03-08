#include <SFML/Graphics.hpp>
#include <iostream>
#include "food.h"
#include "player.h"

#ifndef COLLISION_H
#define COLLISION_H

class CollisionHandler {
	private:

	public:

	CollisionHandler();

	virtual ~CollisionHandler();

	void detect_collisions(Player* player, Food* food, sf::VideoMode vm);

};

#endif
