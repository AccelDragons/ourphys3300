/*
	Incluimos las librer�as necesarias para el programa que desarrollaremos. 
*/
#include <iostream>
#include <vector>

//Agregamos la librer�a ctime para generar distintos "seeds" para rand().
#include <ctime>

// Librer�as para manejar el tiempo. 
#include <chrono>
#include <thread>

/*
	Hacemos la declaraci�n para el uso del namespace std.
*/
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

/*
	Creamos el main del programa. 
*/
int main()
{

	//Usamos srand() para generar un "seed" distinto siempre. 
	srand(time(0));

	// Iniciamos declarando en n�mero m�ximo de espacios que tiene el inventario del jugador. 
	const int inventorySpaceMax = 4;

	// Declaramos e inicializamos la variable para el n�mero de espacios disponibles en el inventario.
	int inventorySpaceOccupied = 0;

	// Creamos un vector que represente al inventario. 
	vector<string> inventory;

	// Creamos un vector que tenga todos los posibles cristales que se pueden obtener de una sola roca. 
	const vector<string> minerals{ "Cristal Rojo (R)", "Cristal Azul (A)", "Cristal Verde (V)" };

	// Creamos e inicializamos la variable para la entrada del usuario. 
	string userInput = "NA";

	// Creamos una variable para almacenar la posici�n de un elemento "random" dentro de "minerals"
	int randomMineralPos;

	// Creamos las variables para el m�nimo y m�ximo del valor "random"
	const int min = 0;
	const int max = minerals.size() - 1; 


	// Programamos el ciclo del emulador de "mining".
	while (userInput != "exit" && userInput != "0") {

		// Creamos el men� para el usuario.
			//... PENDIENTE... (NO OBLIGATORIO)

		// En estas l�neas, se lee la entrada del usuario. 
		cout << "===============================================================================" << endl;
		cout << "Waiting for input: "; cin >> userInput; cout << "\n";

		// "Si el usuario escribe M o m..."
		if (userInput == "m" || userInput == "M") {

			/*
				Solo agregaremos minerales al inventario si hay espacio. Verificamos si hay espacio disponible
			*/ 
			if (inventorySpaceOccupied < inventorySpaceMax) {

				// Usamos la librer�a chrono y thread para crear el mensaje temporizado de "mining".
				cout << "Mining . ";
				sleep_for(milliseconds(500));
				cout << ". ";
				sleep_for(milliseconds(500));
				cout << ".\n\n";

				// Generamos una posici�n "random" dentro del vector "minerals".
				randomMineralPos = rand() % (max - min + 1) + min;

				// Le informamos al usuario el mineral obtenido y aumentamos los espacios ocupados en el inventario.
				cout << "Has obtenido: " << minerals[randomMineralPos] << "\n\n";
				inventorySpaceOccupied++;

				//Agregamos el item obtenido al vector inventario. 
				inventory.push_back(minerals[randomMineralPos]);

				// Le informamos al usuario el n�mero de espacios restantes en el inventario. 
				cout << "Has recolectado " << inventorySpaceOccupied << " de " << inventorySpaceMax << " minerales." << "\n\n";

			}
			else {

				cout << "INVENTARIO LLENO." << "\n\n";

			}

		}
		else if (userInput == "i" || userInput == "I") {

			// Usamos la librer�a chrono y thread para crear el mensaje temporizado de "abriendo inventario".
			cout << "Abriendo inventario . ";
			sleep_for(milliseconds(500));
			cout << ". ";
			sleep_for(milliseconds(500));
			cout << ".\n\n";

			// Verificamos si el inventario est� vac�o. 
			if (inventorySpaceOccupied == 0) {
				cout << "INVENTARIO VACIO" << "\n\n";
			}
			else {

				// Creamos un ciclo for que imprima todos los elementos del vector "inventory". 
				for (int i = 0; i < inventory.size(); i++) {

					//Iteramos sobre el vector inventario para mostrar el valor de cada elemento. 
					cout << inventory[i] << "  ";

				}

			}
			cout << "\n\n";
		}
	}
}