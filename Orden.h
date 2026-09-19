#pragma once
#include <vector>
using namespace std;
class Orden
{
public:
	static void ordenaBurbuja(vector<int>&, int); // Ordena en forma ascendentelos datos con el método de Burbuja
	static void ordenaIntercambio(vector<int>&, int); 	// Ordena en forma ascendente los datos con el método de Intercambio
	static void ordenaMerge(vector<int>&, int, int); // Ordena en forma ascendente los datos con el método de Merge

private:
	static void swap(int*, int*); // Función complementaria de burbuja
	static void mergeB(vector<int>&, int, int, int); // Función complementaria de mergesort
};

