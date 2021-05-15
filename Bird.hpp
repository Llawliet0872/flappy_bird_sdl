#pragma once

#ifndef BIRD_H
#define BIRD_H

#include <SDL2/SDL.h>
#include <iostream>
#include "loadTexture.hpp"
#include "Values.hpp"

class Bird
{
public:
	Bird(SDL_Renderer *_renderer);
	Bird();
	~Bird();
	void draw();
	void update(bool _b);
	float getX() const {return x;}
	float getY() const {return y;}
	void setRenderer(SDL_Renderer *_r) {renderer = _r;}
	void setTexture(SDL_Texture *_t) {texture = _t;}

private:
	SDL_Renderer *renderer = NULL;
	SDL_Texture *texture = NULL;
	SDL_Rect r;
	float x = WIDTH / 4;
	float y = HEIGHT / 2;
	float v = 0.0f;
};

#endif
