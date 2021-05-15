#include "Pipe.hpp"

Pipe::Pipe(SDL_Renderer *_renderer, SDL_Texture *_tex, int _y, bool _up)
:y(_y), renderer(_renderer), tex(_tex)
{}

Pipe::~Pipe(){}

void Pipe::update()
{
	x -= 0.16;
}

void Pipe::draw()
{
	r.x = x - 50;
	r.y = y - 200;
	r.w = 100;
	r.h = 400;

	SDL_RenderCopyEx(renderer, tex, NULL, &r, 0, nullptr, SDL_FLIP_NONE);
}
