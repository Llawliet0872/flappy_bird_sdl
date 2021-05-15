#include "Bird.hpp"

Bird::Bird(SDL_Renderer *_renderer)
:renderer(_renderer)
{}

Bird::Bird()
{}

Bird::~Bird()
{
	SDL_DestroyTexture(texture);
	renderer = NULL;
	SDL_DestroyRenderer(renderer);
	texture = NULL;
}

void Bird::draw()
{
	r.x = x - 64;
	r.y = y - 64;
	r.w = 128;
	r.h = 128;

	SDL_RenderCopyEx(renderer, texture, NULL, &r, v * 70, NULL, SDL_FLIP_NONE);
}

void Bird::update(bool _b)
{
	if(_b) {v -= 0.002f;}
		
	v += 0.001f;
	y += v;
}


