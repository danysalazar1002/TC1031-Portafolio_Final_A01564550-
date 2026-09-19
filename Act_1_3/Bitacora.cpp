#include "Bitacora.h"

Bitacora::Bitacora()
{
	month = "";
	day = "";
	hour = "";
	dirIp = "";
	error = "";
	timeCompare = 0;
}

Bitacora::Bitacora(string mes, string dia, string hora, string ip, string err)
{
	month = mes;
	day = dia;
	hour = hora;
	dirIp = ip;
	error = err;

	//Seccion para determinar el valor del tiempo que se pueda utilizar en el sort:

	int sizeTime = 0; // Variable temporal que almacena el tiempo que usara un sistema de numero posicional para medir el tiempo
	string tempHour = this->hour;

	map<string, int> diccMonth = {
		{"Jan", 100000000},{"Feb", 200000000},{"Mar", 300000000},
		{"Apr", 400000000},{"May", 500000000},{"Jun", 600000000},
		{"Jul", 700000000},{"Aug", 800000000},{"Sep", 900000000},
		{"Oct", 1000000000},{"Nov", 1100000000},{"Dec", 1200000000}
	}; //diccionario para acceder facilmente al valor del mes (en vez que usar if y else if, que era lo que estaba haciendo)

	sizeTime += diccMonth[this->month]; //Suma el mes
	sizeTime += stoi(this->day) * 1000000; // Suma el dia

	for (int i = 0; i < tempHour.length(); i++)
	{
		if (tempHour[i] == ':')
		{
			tempHour.erase(i, 1);
		}
	}

	sizeTime += stoi(tempHour);

	timeCompare = sizeTime;
}

void Bitacora::setMonth(string mes)
{
	month = mes;
}

void Bitacora::setDay(string dia)
{
	day = dia;
}

void Bitacora::setHour(string hora)
{
	hour = hora;
}

void Bitacora::setDirIp(string ip)
{
	dirIp = ip;
}

void Bitacora::setError(string err)
{
	error = err;
}

string Bitacora::getMonth()
{
	return month;
}

string Bitacora::getDay()
{
	return day;
}

string Bitacora::getHour()
{
	return hour;
}

string Bitacora::getDirIp()
{
	return dirIp;
}

string Bitacora::getError()
{
	return error;
}

int Bitacora::getTimeCompare()
{
	return timeCompare;
}

//int Bitacora::convertirNum() // Funcion que calcula, pero se puso mejor en el constructor, porque se volvia n2
//{
//	int sizeTime = 0; // Variable que almacena el tiempo que usara un sistema de numero posicional para medir el tiempo
//	string tempHour = this->hour;
//
//	map<string, int> diccMonth = {
//		{"Jan", 100000000},{"Feb", 200000000},{"Mar", 300000000},
//		{"Apr", 400000000},{"May", 500000000},{"Jun", 600000000},
//		{"Jul", 700000000},{"Aug", 800000000},{"Sep", 900000000},
//		{"Oct", 1000000000},{"Nov", 1100000000},{"Dec", 1200000000}
//	}; //diccionario para acceder facilmente al valor del mes (en vez que usar if y else if, que era lo que estaba haciendo)
//
//	sizeTime += diccMonth[this->month]; //Suma el mes
//	sizeTime += stoi(this->day) * 1000000; // Suma el dia
//
//	for (int i = 0; i < tempHour.length(); i++)
//	{
//		if (tempHour[i] == ':')
//		{
//			tempHour.erase(i,1);
//		}
//	}
//
//	sizeTime += stoi(tempHour);
//
//	return sizeTime;
//}

string Bitacora::imprimeBitacora()
{
	return (this->month + " " + this->day + " " + this->hour + " " + this->dirIp + " " + this->error + " ");
}
