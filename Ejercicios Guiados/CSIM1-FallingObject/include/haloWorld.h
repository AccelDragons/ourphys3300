#ifndef HALOWORLD_H
#define HALOWORLD_H

#include "haloBody.h"
#include <vector>

struct hWorld
{
	// Definimos el constructor de la clase. 
	hWorld() {}
	hWorld(vec2D gravity) : gravity(gravity) {}

	// Declaramos la variable gravedad del world. 
	vec2D gravity;

	// Declaramos un vector que contenga todos los cuerpos en este world. 
	std::vector<hBody*> bodies;

	// Creamos una funci�n para establecer la gravedad del world. 
	void setGravity(const vec2D &g);

	// Creamos una funci�n para agregar un cuerpo a este world. 
	void addBody(hBody* b);

	// Creamos la funci�n Step. Esta es la encargada de la simulaci�n.
	void Step(float dt); //El dt suele ser el tiempo que toma pasar de un frame al otro. 

};

#endif /* HALOWORLD_H */
 
