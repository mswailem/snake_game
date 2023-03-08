#include <SFML/Graphics.hpp>
#include <iostream>
#include "food.h"
#include "player.h"

#ifndef INPUT_H
#define INPUT_H

class InputHandler {
	private:

	public:

	InputHandler();

	virtual ~InputHandler();

	void handle_inputs(Player* player);

};

#endif
