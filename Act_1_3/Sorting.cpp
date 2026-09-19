#include "Sorting.h"

void Sorting::mergeSort(vector<Bitacora> &bitacoras, int const begin, int const end)
{
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	Sorting::mergeSort(bitacoras, begin, mid);
	Sorting::mergeSort(bitacoras, mid + 1, end);
	Sorting::mergeB(bitacoras, begin, mid, end);
}

void Sorting::mergeB(vector<Bitacora> &bitacora, int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new Bitacora[subArrayOne],
		* rightArray = new Bitacora[subArrayTwo];

	// Copy data to temp arrays leftArray[] 
	// and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = bitacora[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = bitacora[mid + 1 + j];

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
		if (leftArray[indexOfSubArrayOne].getTimeCompare() <=
			rightArray[indexOfSubArrayTwo].getTimeCompare())
		{
			bitacora[indexOfMergedArray] =
				leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else
		{
			bitacora[indexOfMergedArray] =
				rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne)
	{
		bitacora[indexOfMergedArray] =
			leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		bitacora[indexOfMergedArray] =
			rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	delete[]leftArray;
	delete[]rightArray;
}
