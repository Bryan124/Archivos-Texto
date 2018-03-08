#include <iostream>
#include "Notas.h"
using namespace std;

int main() {

	int opcion;

	do {
		cout << "1.Registrar Alumnos\n" << "2.Consultar Alumnos\n" << "3.Registrar Materias\n" << "4.Consultar Materias\n" << "5.Registrar Notas\n"
			<< "6.Consultar Notas\n" << "7.Promedio Alumnos\n" << "8.Promedio Materias\n" << "9.Salir\n";
		cin >> opcion;
		switch (opcion) {
		case 1:{
			Notas::registrarAlumnos();
			cout << endl;
			break;
			}
		case 2: {
			Notas::consultarAlumnos();
			cout << endl;
			break;
		}
		case 3: {
			Notas::registrarMaterias();
			cout << endl;
			break;
		}
		case 4: {
			Notas::consultarMaterias();
			cout << endl;
			break;
		}
		case 5: {
			Notas::registrarNotas();
			cout << endl;
			break;
		}
		case 6: {

		}
		case 7: {
			Notas::PromedioAlumno();
			cout << endl;
			break;
		}
		case 8: {
			Notas::PromedioMateria();
			cout << endl;
			break;
		}
			
		}

	} while (opcion != 9);

	system("pause>nul");
}