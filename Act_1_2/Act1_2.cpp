// Act1_2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Daniel Salazar Domínguez A01564550

#include <iostream>
#include "Busqueda.h"
#include "Orden.h"
using namespace std;


int main()
{
	vector<int> vectorUpd = {};
	int n = 0;

	while (true)
	{

		int numBusqueda = 0;
		int opcion = 0;
		int valor = 0;

		cout << "1.- Ingresar vector de numeros" << endl
			<< "2.- Busqueda binaria y secuencial" << endl
			<< "3.- Salir" << endl;

		cout << "Ingrese una opcion: "; 
		cin >> opcion;

		switch (opcion)
		{
			case 1:
			{
				vectorUpd = {};
				vector<int> temp1;
				vector<int> temp2;
				vector<int> temp3;

				cout << "Tamano del vector: ";
				cin >> n;

				for (int i = 0; i < n;i++)
				{
					cout << "Ingresa un valor: ";
					cin >> valor;

					vectorUpd.push_back(valor);
				}

				cout << "Vector ordenado 3 metodos: " << endl;

				temp1 = vectorUpd;
				temp2 = vectorUpd;
				temp3 = vectorUpd;
				
				cout << "BubbleSort: " << endl;
				Orden::ordenaBurbuja(temp1, n);
				for (int i = 0; i < temp1.size(); i++)
					cout << temp1[i] << " ";
				cout << endl;

				cout << "Intercambio: " << endl;
				Orden::ordenaIntercambio(temp2, n);
				for (int i = 0; i < temp2.size(); i++)
					cout << temp2[i] << " ";
				cout << endl;

				cout << "MergeSort: " << endl;
				Orden::ordenaMerge(temp3, 0, vectorUpd.size() - 1);
				for (int i = 0; i < temp3.size(); i++)
					cout << temp3[i] << " ";
				cout << endl;

				Orden::ordenaBurbuja(vectorUpd, n);
				cout << "Vector ordenado creado..." << endl;
				continue;
			}
			case 2:
			{
				if (vectorUpd.empty())
				{
					cout << "Vector Vacio..." << endl;
					continue;
				}

				for (int i = 0; i < vectorUpd.size(); i++)
					cout << vectorUpd[i] << " ";

				cout << endl << "Numero de busquedas: ";
				cin >> numBusqueda;

				for (int i = 0; i < numBusqueda;i++)
				{
					cout << "Ingresa numero que buscas: ";
					cin >> valor;

					if (Busqueda::busqBinaria(vectorUpd, n, valor) != Busqueda::busqSecuencial(vectorUpd, n, valor))
					{
						cout << "Error en busquedas (diferentes outputs)" << endl;
						continue;
					}
					else
					{
						cout << "Busqueda Binaria posicion del vector: " << Busqueda::busqBinaria(vectorUpd, n, valor) << endl;
						cout << "Busqueda Secuencial posicion del vector: " << Busqueda::busqSecuencial(vectorUpd, n, valor) << endl;
					}
				}
			}
				continue;
			case 3:
				return 0;
		}
	}

	//Casos prueba

	/*1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion : 1
		Tamano del vector : 5
		Ingresa un valor : 5
		Ingresa un valor : 4
		Ingresa un valor : 3
		Ingresa un valor : 2
		Ingresa un valor : 1
		Vector ordenado 3 metodos :
		BubbleSort :
		1 2 3 4 5
		Intercambio :
		1 2 3 4 5
		MergeSort :
		1 2 3 4 5
		Vector ordenado creado...
		1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion : 2
		1 2 3 4 5
		Numero de busquedas : 1
		Ingresa numero que buscas : 4
		Busqueda Binaria posicion del vector : 3
		Busqueda Secuencial posicion del vector : 3
		1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion : 1
		Tamano del vector : 3
		Ingresa un valor : 1
		Ingresa un valor : 2
		Ingresa un valor : 3
		Vector ordenado 3 metodos :
		BubbleSort :
		1 2 3
		Intercambio :
		1 2 3
		MergeSort :
		1 2 3
		Vector ordenado creado...
		1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion : 2
		1 2 3
		Numero de busquedas : 3
		Ingresa numero que buscas : 1
		Busqueda Binaria posicion del vector : 0
		Busqueda Secuencial posicion del vector : 0
		Ingresa numero que buscas : 2
		Busqueda Binaria posicion del vector : 1
		Busqueda Secuencial posicion del vector : 1
		Ingresa numero que buscas : 3
		Busqueda Binaria posicion del vector : 2
		Busqueda Secuencial posicion del vector : 2
		1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion : 1
		Tamano del vector : 4
		Ingresa un valor : 1
		Ingresa un valor : 1
		Ingresa un valor : 2
		Ingresa un valor : 2
		Vector ordenado 3 metodos :
		BubbleSort :
		1 1 2 2
		Intercambio :
		1 1 2 2
		MergeSort :
		1 1 2 2
		Vector ordenado creado...
		1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion : 1
		Tamano del vector : 1
		Ingresa un valor : 1
		Vector ordenado 3 metodos :
		BubbleSort :
		1
		Intercambio :
		1
		MergeSort :
		1
		Vector ordenado creado...
		1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion : 2
		1
		Numero de busquedas : 1
		Ingresa numero que buscas : 1
		Busqueda Binaria posicion del vector : 0
		Busqueda Secuencial posicion del vector : 0
		1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion : 2
		1
		Numero de busquedas : 3
		Ingresa numero que buscas : 2
		Busqueda Binaria posicion del vector : -1
		Busqueda Secuencial posicion del vector : -1
		Ingresa numero que buscas : 2
		Busqueda Binaria posicion del vector : -1
		Busqueda Secuencial posicion del vector : -1
		Ingresa numero que buscas : 2
		Busqueda Binaria posicion del vector : -1
		Busqueda Secuencial posicion del vector : -1
		1. - Ingresar vector de numeros
		2. - Busqueda binaria y secuencial
		3. - Salir
		Ingrese una opcion :*/

	//Prueba de funciones:

	//vector<int> vector1 = {5,6,9,10,600,12,24,3};
	//vector<int> vector2 = { 100,50,20,10,9,1,700,2,3,6 };
	//vector<int> vector3 = { 5,1,8,2,9,7,3 };

	//cout << "Ordenados:" << endl;
	//Orden::ordenaBurbuja(vector1, vector1.size());
	//for (int i = 0; i < vector1.size(); i++)
	//	cout << vector1[i] << ",";
	//cout << endl;
	//cout << "Busqueda binaria: " << Busqueda::busqBinaria(vector1, vector1.size(), 600) << endl
	//	 << "Busqueda secuencial: " << Busqueda::busqSecuencial(vector1, vector1.size(), 600) << endl;

	//cout << "Ordenados:" << endl;
	//Orden::ordenaIntercambio(vector2, vector2.size());
	//for (int i = 0; i < vector2.size(); i++)
	//	cout << vector2[i] << ",";
	//cout << endl;
	//cout << "Busqueda binaria: " << Busqueda::busqBinaria(vector2, vector2.size(), 20) << endl
	//	 << "Busqueda secuencial: " << Busqueda::busqSecuencial(vector2, vector2.size(), 20) << endl;

	//cout << "Ordenados:" << endl;
	//Orden::ordenaMerge(vector3,0, vector3.size() - 1);
	//for (int i = 0; i < vector3.size(); i++)
	//	cout << vector3[i] << ",";
	//cout << endl;
	//cout << "Busqueda binaria: " << Busqueda::busqBinaria(vector3, vector3.size(), 9) << endl
	//	 << "Busqueda secuencial: " << Busqueda::busqSecuencial(vector3, vector3.size(), 9) << endl;
}

