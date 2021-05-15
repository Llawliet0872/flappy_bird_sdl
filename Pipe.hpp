#pragma once

#ifndef PIPE_H
#define PIPE_H

#include <SDL2/SDL.h>
#include "Values.hpp"

class Pipe
{
public:
	Pipe(SDL_Renderer *_renderer, SDL_Texture *_tex, int _y, bool _up);
	~Pipe();
	void update();
	void draw();
	int y;
	float x = WIDTH;
	SDL_Rect getRect() const {return r;}

private:
	SDL_Renderer *renderer = NULL;
	SDL_Rect r;
	SDL_Texture *tex = NULL;
};

#endif
