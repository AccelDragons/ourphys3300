#include <iostream>
#include "vector2D.h"

using namespace std;

int main()
{
	vector2D vec1(0.5f, 3.2f);
	cout << "La longitud cuadrada del vector es: " << vec1.lengthSquared() << endl;
	cout << "La longitud del vector es: " << vec1.length() << endl;
	return 0;
}