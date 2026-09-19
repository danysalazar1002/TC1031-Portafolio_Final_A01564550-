#pragma once
#include "Bitacora.h"
#include <vector>
class Sorting
{
public:
	static void mergeSort(vector<Bitacora>&, int, int);

private:
	static void mergeB(vector<Bitacora>&, int, int, int);
};