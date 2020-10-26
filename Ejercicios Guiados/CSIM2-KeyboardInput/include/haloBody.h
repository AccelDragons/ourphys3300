#ifndef HALOBODY_H
#define HALOBODY_H

#include "haloMath.h"

struct hBody
{

	// Declaramos el constructor de la clase.
	hBody();

	// Declaramos la masa del objeto y el recíproco de la masa. 
	float mass;
	float invMass;

	// Declaramos la posición (lineal) del objeto. 
	vec2D position;

	// Declaramos la velocidad (lineal) del objeto. 
	vec2D velocity;

	// Declaramos la fuerza aplicada al objeto. 
	vec2D force;

	// Creamos una función para establecer la masa del objeto. 
	void setMass(const float &m);

	// Creamos una función que muestre las propiedades del objeto. 
	void displayBodyInfo();

};

#endif /* HALOBODY_H */

