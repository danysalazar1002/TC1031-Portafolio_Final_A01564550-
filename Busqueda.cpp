#include "Busqueda.h"

int Busqueda::busqSecuencial(vector<int> vec, int n, int clave)
{
	for (int i = 0; i < n; i++)
	{
		if (vec[i] == clave)
			return i;
	}
	return -1;
}

int Busqueda::busqBinaria(vector<int> vec, int n, int clave)
{
	int central, bajo, alto, valorCentral;
	bajo = 0;
	//n = lista.length;
	alto = n - 1;
	while (bajo <= alto) {
		central = (bajo + alto) / 2;
		valorCentral = vec[central];
		if (clave == valorCentral)
			return central;
		else if (clave < valorCentral)
			alto = central - 1;
		else
			bajo = central + 1;
	}
	return -1;
}