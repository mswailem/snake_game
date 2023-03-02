#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"


using namespace std;


int main(int argc, char* argv[])
{
	Game game;

    while (game.running())
    {
		game.update();

		game.render();
    }

    return 0;
}
