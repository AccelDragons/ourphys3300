#include "haloWorld.h"

void hWorld::setGravity(const vec2D& g)
{
	gravity = g;
}

void hWorld::addBody(hBody* b)
{
	bodies.push_back(b);
}

void hWorld::Step(float dt)
{
	for (int counter = 0; counter < bodies.size(); counter++){
		bodies[counter]->velocity.x = gravity.x * dt + bodies[counter]->velocity.x;
		bodies[counter]->velocity.y = gravity.y * dt + bodies[counter]->velocity.y;
	}

	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->position.x = bodies[counter]->velocity.x * dt + bodies[counter]->position.x;
		bodies[counter]->position.y = bodies[counter]->velocity.y * dt + bodies[counter]->position.y;
	}
}
