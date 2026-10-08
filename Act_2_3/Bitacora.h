#pragma once
#include <string>
#include <sstream>
using namespace std;

class Bitacora
{
private:
	string month;
	string day;
	string hour;
	string dirIp;
	string error;
	long long int ipCompare; //variable de ip para comparar
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
	long long int getIpCompare();
	
	void calculeIpCompare();
	friend ostream& operator<<(ostream& text, const Bitacora& bit);
	//string imprimeBitacora(); //Se cambio por una sobrecarga de <<
};

