#pragma once

#ifndef GAME_H
#define GAME_H

#include "Bird.hpp"
#include "Pipe.hpp"
#include <vector>

class Game
{
public:
	Game();
	int exec();
	void update();

private:
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *upperPipeTex = NULL;
	SDL_Texture *lowerPipeTex = NULL;
	SDL_Event e;
	Bird burd;
	SDL_Rect collisionRect, pRect, bRect;
	std::vector <Pipe> pipes;
	bool running = true;
	bool mouseDown = false;
	int counter = 0;
};

#endif
