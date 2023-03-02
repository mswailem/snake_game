#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include "food.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game {
	private:
		sf::RenderWindow* window;
		sf::VideoMode vm;
		sf::Event event;
		Player* player;
		Food* food;
		sf::Clock clock;
		sf::Time frametime;

	public:

	Game();

	virtual ~Game();

	const bool running() const;

	void init_vars();
	void init_window();
	void pollEvents();
	void update();
	void render();
	std::string detect_collisions();

};

#endif 
