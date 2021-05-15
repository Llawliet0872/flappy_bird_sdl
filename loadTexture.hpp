#pragma once

#ifndef LOADTEXTURE_H
#define LOADTEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_Texture *loadTexture(SDL_Renderer *_renderer, std::string path);

#endif
