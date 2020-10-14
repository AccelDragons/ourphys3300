#ifndef HALOWORLD_H
#define HALOWORLD_H

#include "haloBody.h"
#include <vector>

struct haloWorld
{
	// Declaramos la variable gravedad del world. 
	vec2D gravity;

	// Declaramos un vector que contenga todos los cuerpos en este world. 
	std::vector<hBody*> bodies;

	// Creamos una funci�n para establecer la gravedad del world. 
	void setGravity();

	// Creamos una funci�n para agregar un cuerpo a este world. 
	void addBody(hBody* b);

};

#endif /* HALOWORLD_H */
 
