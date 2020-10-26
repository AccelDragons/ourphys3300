#include "Simulation.h"

int main(int argc, char* args[])
{
	const int FPS = 60;
	const float frameDelay = 1000 / FPS;

	Uint32 frameStart;
	Uint32 frameEnd;
	float frameTime;

	Simulation* simulation = nullptr;
	simulation = new Simulation();

	simulation->init("Halo Engine", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 640, false);

	//FRAME
	while (simulation->running()) {

		frameStart = SDL_GetTicks();

		simulation->handleEvents();
		simulation->update();
		simulation->render();

		frameEnd = SDL_GetTicks();

		frameTime = frameEnd - frameStart;

		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	simulation->clean();

	return 0;
}