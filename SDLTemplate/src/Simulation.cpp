#include "Simulation.h"

SDL_Texture* backgroundTex;
SDL_Texture* robotTex; 
SDL_Rect robotDestR; 

Simulation::Simulation()
{}

Simulation::~Simulation()
{}

void Simulation::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0; 
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized!" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window,-1,0);

		if (renderer)
		{
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		std::cout << "Couldn't initiate SDL..." << std::endl;
		isRunning = false;
	}

	SDL_Surface* backgroundTmpSurface = IMG_Load("assets/blue.png");
	backgroundTex = SDL_CreateTextureFromSurface(renderer, backgroundTmpSurface);
	SDL_FreeSurface(backgroundTmpSurface);

	SDL_Surface* robotTmpSurface = IMG_Load("assets/chibi-robot.png");
	robotTex = SDL_CreateTextureFromSurface(renderer, robotTmpSurface);
	SDL_FreeSurface(robotTmpSurface);

}

void Simulation::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Simulation::update()
{
	count += 2;
	robotDestR.h = 64;
	robotDestR.w = 64;
	robotDestR.x = count;
	robotDestR.y = count;
	std::cout << count << std::endl;
}

void Simulation::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTex, NULL, NULL);
	SDL_RenderCopy(renderer, robotTex, NULL, &robotDestR);
	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}
