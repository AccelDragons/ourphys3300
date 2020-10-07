#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Simulation
{
public:
	Simulation();
	~Simulation();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning;
	int count = 0;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif /* SIMULATION_H */