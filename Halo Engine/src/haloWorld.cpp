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
		bodies[counter]->velocity.x += (gravity.x + bodies[counter]->force.x * bodies[counter]->invMass) * dt;
		bodies[counter]->velocity.y += (gravity.y + bodies[counter]->force.y * bodies[counter]->invMass) * dt;
	}

	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->position.x += bodies[counter]->velocity.x * dt;
		bodies[counter]->position.y += bodies[counter]->velocity.y * dt;

		bodies[counter]->force.setZero();
	}
}
