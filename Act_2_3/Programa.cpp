#include "Programa.h"

void Programa::app()
{
	vector<Bitacora> bitacoras;
	string fileName = "";

	Bitacora begin;
	string bIp = "";

	Bitacora end;
	string eIp = "";

	int option = 0;

	//Menu

	try {
		while (true) {

			cout << "1.- Seleccionar y ordenar bitacora " << "\n"
				<< "2.- Mostrar por rango de IP's" << "\n"
				<< "3.- Salir" << "\n" << "Seleccione una opcion: ";
			cin >> option;

			switch (option) {
			case 1:
			{
				bitacoras.clear(); //elimina los elementos del vector para evitar registros duplicados

				cout << "Ingresa el nombre de la bitacora que quieras ordenar (eg. bitacora.txt): ";
				cin >> fileName;

				ifstream fileData(fileName);
				string textLine;

				if (!fileData.is_open()) {
					throw "Falla al abrir el archivo...";
				}

				while (getline(fileData, textLine)) { //este while termina cuando ya no hay mas lineas por las que pasar, traduce el texto 
					//a un vector con objetos bitacoras de acuerdo al contenido del .txt
					stringstream separator(textLine);

					string month;
					string day;
					string hour;
					string dirIp;
					string error;

					getline(separator, month, ' ');
					getline(separator, day, ' ');
					getline(separator, hour, ' ');
					getline(separator, dirIp, ' ');
					getline(separator, error); //Se quita el ' ', para que lea lo que queda de la linea

					bitacoras.push_back(Bitacora(month, day, hour, dirIp, error));
				}
				fileData.close();

				// Esta parte del codigo se encargara de ordenar el vector de bitacoras usando la funcion
				// calculeIpCompare para ordenarlos de menor a mayor

				Sorting::mergeSort(bitacoras, 0, bitacoras.size() - 1);

				//Crea un documento nuevo .txt ya ordenado según el IP

				ofstream outfile("bitacora_ordenada.txt");

				for (int i = 0; i < bitacoras.size(); i++) {
					outfile << bitacoras[i].getMonth() << " " << bitacoras[i].getDay() << " "
						<< bitacoras[i].getHour() << " " << bitacoras[i].getDirIp() << " "
						<< bitacoras[i].getError();
					if (i != (bitacoras.size() - 1))
						outfile << "\n";
				}

				outfile.close();

				cout << "Se creo la bitacora_ordenada.txt de manera correcta..." << "\n";
				break;
			}
			case 2:
			{
				//Checa que exista un vector que ver
				if (bitacoras.empty())
					throw "No hay vector en el cual buscar...";
				
				try {
					cout << "Ingrese el IP de inicio (sin puerto): ";
					cin >> bIp;

					begin = Bitacora("", "", "", bIp, "");

					cout << "Ingrese el IP final (sin puerto): ";
					cin >> eIp;

					end = Bitacora("", "", "", eIp, "");
				}
				catch (const invalid_argument&) { //checa si la conversion de los ips se puede realizar con el constructor, si el formato no es el correcto lanza excepción
					cout << "Ingrese la IP de manera correcta\n";
					break;
				}

				cout << "Rango de IP's (descendente) elegido: " << "\n";

				for (int i = bitacoras.size() - 1; i >= 0;i--) {
					if (bitacoras[i].getIpCompare() >= begin.getIpCompare() && bitacoras[i].getIpCompare() <= end.getIpCompare()) {
						cout << bitacoras[i] << "\n";
					}
				}

				cout << "\n";

				break;
			}
			case 3:
			{
				cout << "Saliendo...";
				return;
			}
			default:
			{
				cout << "Opcion invalida..." << "\n";
				break;
			}
			}
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}
