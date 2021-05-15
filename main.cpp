#define SDL_MAIN_HANDLED

#include <iostream>
#include "Game.hpp"

int main(void)
{
	Game game;

	return game.exec();
}
