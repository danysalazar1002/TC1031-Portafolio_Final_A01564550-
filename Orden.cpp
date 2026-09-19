#include "Orden.h"

void Orden::ordenaIntercambio(vector<int> &v, int n)
{
	int i, j, aux;
	for (i = 1; i < n; i++) // El índice j explora sublista a[i-1]..a[0] buscando posición correcta del elemento destino, para asignarlo en a[j]
	{
		j = i;
		aux = v[i]; // se localiza el punto de inserción explorando hacia abajo
		while (j > 0 && aux < v[j - 1]) // desplazar elementos hacia arriba para hacer espacio
		{
			v[j] = v[j - 1];
			j--;
		}
		v[j] = aux;
	}
}

void Orden::ordenaBurbuja(vector<int> &v, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1])
				swap(&v[j], &v[j + 1]);
}

void Orden::ordenaMerge(vector<int> &vec, int const begin, int const end)
{
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	Orden::ordenaMerge(vec, begin, mid);
	Orden::ordenaMerge(vec, mid + 1, end);
	Orden::mergeB(vec, begin, mid, end);
}

void Orden::swap(int* val1, int* val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void Orden::mergeB(vector<int> &vec, int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] 
	// and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = vec[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = vec[mid + 1 + j];

	// Initial index of first sub-array
	// Initial index of second sub-array
	auto indexOfSubArrayOne = 0,
		indexOfSubArrayTwo = 0;

	// Initial index of merged array
	int indexOfMergedArray = left;

	// Merge the temp arrays back into 
	// array[left..right]
	while (indexOfSubArrayOne < subArrayOne &&
		indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne] <=
			rightArray[indexOfSubArrayTwo])
		{
			vec[indexOfMergedArray] =
				leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else
		{
			vec[indexOfMergedArray] =
				rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne)
	{
		vec[indexOfMergedArray] =
			leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		vec[indexOfMergedArray] =
			rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	delete[]leftArray;
	delete[]rightArray;
}

