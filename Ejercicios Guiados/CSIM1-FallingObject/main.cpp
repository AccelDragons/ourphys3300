#include "Simulation.h"

int main(int argc, char* args[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	Uint32 frameEnd;
	float frameTime;

	Simulation* simulation = nullptr;
	simulation = new Simulation();

	simulation->init("Halo Engine", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, false);

	hWorld world(vec2D(0.0f, 850.0f));
	hBody robotBody;
	//robotBody.position = vec2D(0.0f,150.0f);
	robotBody.velocity = vec2D(450.0f,0.0f);
	world.addBody(&robotBody);

	hBody boxBody;
	boxBody.position = vec2D(400.0f,150.0f);
	world.addBody(&boxBody);

	//FRAME
	while (simulation->running()) {
		robotBody.displayBodyInfo();

		frameStart = SDL_GetTicks();

		simulation->handleEvents();
		simulation->update(robotBody.position, boxBody.position);
		simulation->render();

		frameEnd = SDL_GetTicks();

		frameTime = frameEnd - frameStart;

		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		frameEnd = SDL_GetTicks();
		frameTime = frameEnd - frameStart;
		frameTime = frameTime / 1000;

		world.Step(frameTime);
	}

	simulation->clean();

	return 0;
}