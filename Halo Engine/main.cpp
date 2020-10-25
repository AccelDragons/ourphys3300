#include "haloWorld.h"

int main()
{
	hWorld firstSimulation(vec2D(0.0f,9.81f));
	hBody firstBody;
	hBody secondBody;
	secondBody.position = vec2D(5.0f, 10.0f);
	secondBody.velocity = vec2D(7.5f, 3.8f);

	firstSimulation.addBody(&firstBody);
	firstSimulation.addBody(&secondBody);

	float frameTime = 0.5f; // Esto normalmente se mide con SDL.
	int counter = 0;

	while (counter<10) {
		firstBody.displayBodyInfo();
		secondBody.displayBodyInfo();
		firstSimulation.Step(frameTime);
		counter++;
	}

	return 0;
}