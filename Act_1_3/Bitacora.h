#pragma once
#include <string>
#include <map>
using namespace std;

class Bitacora
{
private:
	string month;
	string day;
	string hour;
	string dirIp;
	string error;
	int timeCompare;
public:
	Bitacora();
	Bitacora(string, string, string, string, string);

	void setMonth(string);
	void setDay(string);
	void setHour(string);
	void setDirIp(string);
	void setError(string);

	string getMonth();
	string getDay();
	string getHour();
	string getDirIp();
	string getError();
	int getTimeCompare();

	// int convertirNum(); // Usa el renglon de bitacora y traduce los strings a enteros 
						// para crear un numero de tiempo que se pueda ordenar
	string imprimeBitacora();
};

