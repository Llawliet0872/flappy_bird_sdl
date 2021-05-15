#include "loadTexture.hpp"

SDL_Texture *loadTexture(SDL_Renderer *_renderer, std::string path)
{
	SDL_Texture *loadedTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if(!loadedSurface) {std::cout << "Failed to load image, " << IMG_GetError() << std::endl;}
	else
	{
		loadedTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if(!loadedTexture) {std::cout << "Failed to create texture, " << IMG_GetError << ", " << SDL_GetError() << std::endl;}
		SDL_FreeSurface(loadedSurface);
	}

	return loadedTexture;
}
