#include "Game.hpp"
#include "loadTexture.hpp"
#include "Values.hpp"

Game::Game()
{
	srand(time(NULL));
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "Failed to Initialize SDL2, " << SDL_GetError() << std::endl;
	}
	
	window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if(!window)
	{
		std::cout << "Failed to create window, " << SDL_GetError() << std::endl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	burd.setRenderer(renderer);	
	burd.setTexture(loadTexture(renderer, "burd.png"));
	upperPipeTex = loadTexture(renderer, "upperPipe.png");
	lowerPipeTex = loadTexture(renderer, "lowerPipe.png");
}

void Game::update()
{
	srand(time(NULL));
	if(++counter % 2000 == 0)
	{
		auto y = rand() % (HEIGHT - 500) + 100;
		pipes.emplace_back(renderer, upperPipeTex, y, false);
	pipes.emplace_back(renderer, lowerPipeTex, y + (rand() % 50) + 490, false);
}	

	burd.update(mouseDown);
	for(auto &pipe : pipes)
	{
		pipe.update();

		bRect = {static_cast<int>(burd.getX() - 32), static_cast<int>(burd.getY() - 32), 64, 64};
		SDL_Rect pRect = {static_cast<int>(pipe.x - 50), static_cast<int>(pipe.y - 200), 100, 400};

		if(DEBUG)
		{
			SDL_SetRenderDrawColor(renderer, 255, 10, 64, 255);
			SDL_RenderFillRect(renderer, &pRect);
			SDL_RenderFillRect(renderer, &bRect);
		}

		if(SDL_IntersectRect(&pRect, &bRect, &collisionRect))
		{
			running = false;
		}
	}
}

int Game::exec()
{
	int oldTick = SDL_GetTicks();
	while(running)
	{

		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT) {running = false;}
			if(e.type == SDL_MOUSEBUTTONDOWN) {mouseDown = true;}
			if(e.type == SDL_MOUSEBUTTONUP) {mouseDown = false;}
		}

		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		SDL_RenderClear(renderer);

		int currentTick = SDL_GetTicks();
		
		for(int i = oldTick; i < currentTick; ++i)
		{
			update();
			oldTick = currentTick;
		}

		burd.draw();
		for(auto &pipe : pipes) {pipe.draw();}
		
		SDL_RenderPresent(renderer);
	}

	return 0;
}
