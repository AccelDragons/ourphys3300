#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <math.h>
#include <vector>

class vector2D
{
public:
	// Creamos los miembros que corresponden a las componentes del vector.
	float x, y;

	// Creamos un constructor DEFAULT que no hace nada.
	vector2D() {}

	// Creamos un constructor para definir el valor de las componentes del vector.
	vector2D(float x, float y) : x(x), y(y) {}

	// Creamos un método que calcule la longitud cuadrada del vector. 
	float lengthSquared();

	// Creamos un método que calcule la longitud del vector. 
	float length();

	// Creamos un método que me permita agregar (sumar) un vector a este objeto vector2D.
	void operator += (const vector2D& v);
};

#endif

