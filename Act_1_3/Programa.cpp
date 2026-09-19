#include "Programa.h"

void Programa::app()
{
	vector<Bitacora> bitacoras;
	string fileName = "";

	Bitacora begin;
	string bMonth = "";
	string bDay = "";
	string bHour = "";

	Bitacora end;
	string eMonth = "";
	string eDay = "";
	string eHour = "";

	int option = 0;

	//Menu
	
	try {
		while (true) {

			cout << "1.- Seleccionar y ordenar bitacora " << "\n"
				<< "2.- Mostrar por rango de fechas" << "\n"
				<< "3.- Salir" << "\n" << "Seleccione una opcion: ";
			cin >> option;

			switch (option) {
				case 1:
				{
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
						string characteristic;

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
					// convertirNum para ordenarlos de mayor a menor

					Sorting::mergeSort(bitacoras, 0, bitacoras.size() - 1);

					//Crea un documento nuevo .txt ya ordenado según la fecha

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

					cout << "Ingrese la fecha de inicio: " << "\n" << "Mes (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): ";
					cin >> bMonth;
					cout << "Dia: ";
					cin >> bDay;
					cout << "Hora (formato: hh:mm:ss): ";
					cin >> bHour;
					if (bHour.size() != 8)
						throw "Formato invalido...";

					begin = Bitacora(bMonth, bDay, bHour, "", "");

					cout << "Ingrese la fecha final: " << "\n" << "Mes (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec): ";
					cin >> eMonth;
					cout << "Dia: ";
					cin >> eDay;
					cout << "Hora (formato: hh:mm:ss): ";
					cin >> eHour;
					if (eHour.size() != 8)
						throw "Formato invalido...";

					cout << "Rango de fechas (descendente) elegido: " << "\n";

					end = Bitacora(eMonth, eDay, eHour, "", "");

					for (int i = bitacoras.size() - 1; i >= 0;i--) {
						if (bitacoras[i].getTimeCompare() >= begin.getTimeCompare() && bitacoras[i].getTimeCompare() <= end.getTimeCompare()) {
							cout << bitacoras[i].imprimeBitacora() << "\n";
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
