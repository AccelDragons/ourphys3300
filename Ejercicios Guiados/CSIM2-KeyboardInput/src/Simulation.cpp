#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* background;
GameObject* ship;

SDL_Event Simulation::event; /* Game::event; */

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

	background = new GameObject("assets/spacebackground.png", renderer);
	ship = new GameObject("assets/spaceship.png", renderer);

	world.gravity = vec2D(0.0f, 0.0f);
	world.addBody(&shipBody);
	shipBody.position = vec2D(400.0f, 320.0f);
}

void Simulation::handleEvents()
{
	SDL_PollEvent(&event);

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_w:
				shipBody.velocity += vec2D(0.0f, -movingSpeed);
				std::cout << "W pressed!" << std::endl;
				break;

			case SDLK_a:
				shipBody.velocity += vec2D(-movingSpeed, 0.0f);
				break;

			case SDLK_s:
				shipBody.velocity += vec2D(0.0f, movingSpeed);
				break;

			case SDLK_d:
				shipBody.velocity += vec2D(movingSpeed, 0.0f);
				break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			shipBody.velocity -= vec2D(0.0f, -movingSpeed);
			std::cout << "W released!" << std::endl;
			break;

		case SDLK_a:
			shipBody.velocity -= vec2D(-movingSpeed, 0.0f);
			break;

		case SDLK_s:
			shipBody.velocity -= vec2D(0.0f, movingSpeed);
			break;

		case SDLK_d:
			shipBody.velocity -= vec2D(movingSpeed, 0.0f);
			break;
		}
	}

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
	ship->update(shipBody.position.x, shipBody.position.y, 32, 32);
}

void Simulation::render()
{
	SDL_RenderClear(renderer);
	background->render(true);
	ship->render();
	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}
