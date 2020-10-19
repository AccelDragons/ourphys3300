#include "haloBody.h"

hBody::hBody()
{
	position.setZero();

	velocity.setZero();

	force.setZero();

	mass = 1.0f;
	invMass = 1.0f; /* 1/mass */
}

void hBody::setMass(const float& m)
{
	mass = m;
	invMass = 1 / m;
}

void hBody::displayBodyInfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "Inv mass: " << invMass << std::endl;
	std::cout << "pos: ", position.displayVector();
	std::cout << "vel: ", velocity.displayVector();
	std::cout << "\n" << std::endl;
}
