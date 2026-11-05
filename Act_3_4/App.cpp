#include "App.h"

void App::app()
{
	// Primer parte leer el archivo que se adapto a .csv, para hacero mas sencillo de leer
	unordered_map<string, int> salenDe; //Complejidad O(1)
	unordered_map<string, int> lleganDe; //Complejidad O(1)

	Tree* tree1 = new Tree();
	Tree* tree2 = new Tree();

	ifstream fileData("4.3.csv");
	string textLine;

	if (!fileData.is_open()) {
		throw "Falla al abrir el archivo...";
	}

	getline(fileData, textLine); // Salta la primer linea porque son los titulos de las columnas

	while (getline(fileData, textLine)) {
		stringstream separator(textLine);

		string value1; // lee la primer IP, la cual nos da los puntos de acceso a los cuales llega
		string value2;
		string extra;

		getline(separator, value1, ',');

		// Agregamos al diccionario, si no existe se pone como llave 1:

		salenDe[value1]++; // si se repiten le agrega una llave

		//Se hace lo mismo para la segunda columna

		getline(separator, extra, ',');
		getline(separator, extra, ',');

		getline(separator, value2, ',');

		lleganDe[value2]++;
	}

	// Despues de crear el diccionario, ahora se crea en formato BST para poder observar los de mayor acceso:

	for (auto const& [value, key] : salenDe) // recorre todo el diccionario para agregarlos al arbol BST, para tenerlos ordenados
	{
		tree1->insert(key, value);
	}

	for (auto const& [value, key] : lleganDe) 
	{
		tree2->insert(key, value);
	}

	// Imprime los 5 IP con mas llaves

	cout << "salenDe: " << endl;
	tree1->inorderReverse(5);
	cout << endl;

	cout << "lleganDe: " << endl;
	tree2->inorderReverse(5);
}

