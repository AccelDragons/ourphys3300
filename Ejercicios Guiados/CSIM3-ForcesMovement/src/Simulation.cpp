#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* background;
GameObject* asteroid;
SDL_Event Simulation::event;

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

	background = new GameObject("assets/space-background.png", renderer);
	asteroid = new GameObject("assets/asteroid.png", renderer);
	
	world.addBody(&asteroidBody);
	world.gravity = vec2D(0.0f, 0.0f);
	asteroidBody.position = vec2D(0.0f, 360.0f);
}

void Simulation::handleEvents()
{
	SDL_PollEvent(&event);

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			asteroidBody.addForce(vec2D(0.0f, -forceValue));
			keyDown[0] = true;
			std::cout << "W pressed!" << std::endl;
			break;

		case SDLK_a:
			asteroidBody.addForce(vec2D(-forceValue, 0.0f));
			keyDown[1] = true;
			break;

		case SDLK_s:
			asteroidBody.addForce(vec2D(0.0f, forceValue));
			keyDown[2] = true;
			break;

		case SDLK_d:
			asteroidBody.addForce(vec2D(forceValue, 0.0f));
			keyDown[3] = true;
			break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			std::cout << "W released!" << std::endl;
			keyDown[0] = false;
			break;

		case SDLK_a:
			keyDown[1] = false;
			break;

		case SDLK_s:
			keyDown[2] = false;
			break;

		case SDLK_d:
			keyDown[3] = false;
			break;
		}
	}

	keyCounter = 0;

	while (keyCounter <= 3) {
		if (keyDown[keyCounter] && !keyAppliedDown[keyCounter]) {
			keyAppliedDown[keyCounter] = true;
			keyAppliedUp[keyCounter] = false;
		}
		else if (!keyDown[keyCounter] && !keyAppliedUp[keyCounter]) {
			keyAppliedUp[keyCounter] = true;
			keyAppliedDown[keyCounter] = false;
		}
		keyCounter++;
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
	asteroid->update(asteroidBody.position.x, asteroidBody.position.y, 32, 32);
}

void Simulation::render()
{
	SDL_RenderClear(renderer);

	background->render(true);
	asteroid->render();

	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}
