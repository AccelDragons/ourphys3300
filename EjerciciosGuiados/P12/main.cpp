// IMPORTAMOS LAS LIBRERIAS NECESARIAS PARA EL PROGRAMA
#include<iostream>
#include<vector>
#include<string> //???
#include<ctime>

using namespace std;

//Declaramos las funciones que usaremos en este programa. 
vector<string> generateInventory();
bool uniqueCrystalVerification(vector<string> itemList);
void openInventory(vector<string> inventory);


//Escribimos el cuerpo de la función generateInventory().
vector<string> generateInventory()
{

	//Declaramos un inventario (local).
	vector<string> randomInventory(10, "NA");

	//Creamos un vector con todos los objetos posibles. 
	const vector<string> allItems = { "Crystallized Azure Dragon's Tears", "Crystallized Exiled Heretic's Bone", "Crystallized Great Feline's Ash", "Fishermen's Plate", "Iron Plate" };

	//Definimos las variables para el uso del rand().
	int randomItemPos;
	int min = 0;
	int max = allItems.size() - 1;

	//Definimos una variable que nos diga si hay un cristal presente en el inventario.
	bool containsCrystal = false; 

	//Declaramos una variable booleana, "longBooleanExpression". 
	bool longBooleanExpression;

	//Declaramos una variable contador para el ciclo while. 
	int counter = 0;

	//Creamos el ciclo que llena el inventario "random". 
	while (counter < randomInventory.size()) {

		//Generamos la posición "random".
		randomItemPos = rand() % (max - min + 1) + min;

		//Usando la función uniqueCrystalVerification, verificamos si hay un cristal en el inventario.
		containsCrystal = uniqueCrystalVerification(randomInventory);

		//Verificamos si el objeto es o no un cristal. 
		longBooleanExpression = (allItems[randomItemPos] == "Crystallized Azure Dragon's Tears") || (allItems[randomItemPos] == "Crystallized Exiled Heretic's Bone") || (allItems[randomItemPos] == "Crystallized Great Feline's Ash");

		//Si no hay cristal, entonces se puede agregar cualquier cosa al inventario.
		if (!containsCrystal) {

			randomInventory[counter] = allItems[randomItemPos];
			counter++; //El counter solo se aumenta cuando se haya agregado algo al inventario. 

		}
		else if (!longBooleanExpression) {  //Si hay cristal, entonces si el objeto que me ha salido NO es un cristal, entonces se puede agregar.

			randomInventory[counter] = allItems[randomItemPos];
			counter++;

		}

	}

	system("CLS");
	cout << "INVENTORY GENERATED! \n\n" << endl;
	system("pause"); //Para esperar que el usuario presione alguna tecla. 

	return randomInventory;

}

//Creamos una función que verifique si ya existe un cristal en la lista pasada como argumento. 
bool uniqueCrystalVerification(vector<string> itemList) 
{

	//Declaramos una variable counter por motivos prácticos. 
	int counter = 0;

	//Declaramos una variable que "diga" si hay un cristal en la lista pasada. 
	bool isCrystalPresent = false;

	//Declaramos el "longBooleanExpression". 
	bool longBooleanExpression;

	//Creamos el ciclo que verifica si hay un cristal en el vector (en la lista).
	while ((counter < itemList.size()) && (!isCrystalPresent)) {

		//Verificamos si hay alguno de los cristales en la lista de objetos. 
		longBooleanExpression = (itemList[counter] == "Crystallized Azure Dragon's Tears") ||  (itemList[counter] == "Crystallized Exiled Heretic's Bone") || (itemList[counter] == "Crystallized Great Feline's Ash");

		//Si hay un cristal, entonces cambiamos el valor de "isCrystalPresent" a "true".
		if (longBooleanExpression) {
			isCrystalPresent = true;
		}

		//Aumentamos el counter (ya que el while no lo hace solo).
		counter++;

	}

	return isCrystalPresent;

}

void openInventory(vector<string> inventory)
{

	//Declaramos la variable que mantiene el inventario abierto. 
	bool inventoryOpened = true;

	//Declaramos la variable para la entrada del usuario. 
	int userInput;

	//Creamos el "UI" del inventario. 
	system("CLS");
	cout << "===============================================================" << endl;
	cout << "= = INVENTORY = =" << "\n" << endl;

	//Creamos el ciclo que nos mantiene el inventario abierto. 
	while (inventoryOpened) {

		//Creamos el ciclo que itera sobre el inventario para imprimirlo (mostrarlo en pantalla).
		for (int counter = 0; counter < inventory.size(); counter++) {

			cout << counter + 1 << ". " << inventory[counter] << endl;

		}

		//Creamos la opción EXIT.
		cout << inventory.size() + 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;

		//Esperamos la entrada del usuario.
		cout << "AWAITING USER INPUT:  "; cin >> userInput;

		//Si el usuario selecciona EXIT, debe salir del inventario y volver al main().
		if (userInput == inventory.size() + 1) {

			inventoryOpened = false;

		}

		//Limpia la ventana.
		system("CLS");

	}

}


int main()
{
	
	//RANDOM SEED.
	srand(time(0));

	//Creamos un vector para el inventario. 
	vector<string> inventory(10,"NA");

	//Creamos una variable bool para mantener el menú funcionando. 
	bool menuOpen = true;

	//Creamos la variable para la entrada del usuario. 
	int mainMenuOption;

	//Usamos un ciclo while para mantener el menú funcionando. 
	while (menuOpen) {

		//Este comando limpia la ventana de comandos. 
		system("CLS");

		//Creamos el "UI" para el menú.
		cout << "===============================================================" << endl;
		cout << "= = MAIN MENU = =" << "\n" << endl;
		cout << "1. INVENTORY GENERATOR (FOR DEVELOPERS)" << endl;
		cout << "2. OPEN INVENTORY" << endl;
		cout << "3. CREATE OPAQUE CRYSTAL" << endl;
		cout << "4. CREATE MEMORY CRYSTAL" << endl;
		cout << "5. EXIT GAME" << endl;
		cout << "===============================================================" << endl;

		//Leemos la entrada del usuario. 
		cout << "AWAITING USER INPUT:  "; cin >> mainMenuOption;

		//Usamos un switch() para manejar el menú con la entrada del usuario.
		switch (mainMenuOption) {

			case 1:
				inventory = generateInventory();
				break;

			case 2:
				openInventory(inventory);
				break;

			case 3:

				break;

			case 4:

				break;

			case 5:
				menuOpen = false;
				break;

			default: 
				system("CLS");
				break;

		}


	}
	
	return 0;

}