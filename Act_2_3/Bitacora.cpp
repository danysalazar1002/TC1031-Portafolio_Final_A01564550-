#include "Bitacora.h"

Bitacora::Bitacora()
{
	month = "";
	day = "";
	hour = "";
	dirIp = "";
	error = "";
	ipCompare = 0;
}

Bitacora::Bitacora(string mes, string dia, string hora, string ip, string err)
{
	month = mes;
	day = dia;
	hour = hora;
	dirIp = ip;
	error = err;
	
	// Aqui se crea el ip en un numero que se pueda comparar

	this->calculeIpCompare();
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

	this->calculeIpCompare();
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

long long int Bitacora::getIpCompare()
{
	return ipCompare;
}

void Bitacora::calculeIpCompare()
{
	ipCompare = 0; //Se inicializa para que se calcule desde cero
	stringstream ipTemp(dirIp);

	string octet1; // octeto 1
	string octet2; // octeto 2
	string octet3; // octeto 3
	string octet4; // octeto 4

	getline(ipTemp, octet1, '.');
	getline(ipTemp, octet2, '.');
	getline(ipTemp, octet3, '.');
	getline(ipTemp, octet4, ':');

	//Se van a multiplicar por multiplos de 1000, para darles numeros individuales

	ipCompare += stoll(octet1) * 1000000000LL;
	ipCompare += stoll(octet2) * 1000000LL;
	ipCompare += stoll(octet3) * 1000LL;
	ipCompare += stoll(octet4);
}

//string Bitacora::imprimeBitacora()
//{
//	return (this->month + " " + this->day + " " + this->hour + " " + this->dirIp + " " + this->error + " ");
//}

ostream& operator<<(ostream& text, const Bitacora& bit)
{
	text << bit.month << " " << bit.day << " " << bit.hour << " " << bit.dirIp << " " << bit.error;
	return text;
}
