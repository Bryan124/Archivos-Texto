
#include "Notas.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void Notas::registrarAlumnos() {
	ofstream archivoAlumno("alumnos.dat", ios::app);

	if (!archivoAlumno) {
		cout << "Error al intentar abrir el archivo .dat\n";
		return;
	}
	int cuenta, edad, cantidad;
	char nombre[50];

	cout << "\n\n *** I N G R E S O   D E   A L U M N O S ***\n\n";
	cout << "Cantidad de alumnos a ingresar: ";
	cin >> cantidad;
	for (int i = 0; i < cantidad; i++) {
		cout << "Ingrese numero de cuenta: ";
		cin >> cuenta;
		cout << "Ingrese nombre de alumno: ";
		cin >> nombre;
		cout << "Ingrese edad: ";
		cin >> edad;

		archivoAlumno << cuenta << ' ' << nombre << ' ' << edad << "\n";
	}

	archivoAlumno.close();
}

void Notas::consultarAlumnos() {
	ifstream archivoAlumnosIn("alumnos.dat", ios::in);
	if (!archivoAlumnosIn) {
		cout << "Error al intentar abrir el archivo .dat\n";
		return;
	}
	int cuenta, edad;
	char nombre[50];
	cout << "\n\n *** C O N S U L T A   D E   A L U M N O S ***\n\n";
	while (archivoAlumnosIn>>cuenta>>nombre>>edad) {
		cout << cuenta << ' ' << nombre << ' ' << edad << "\n";
	}
}

void Notas::registrarMaterias() {
	ofstream archivoMateriasOut("materias.dat", ios::app);
	if (!archivoMateriasOut) {
		cout << "Error al intentar abrir el archivo .dat\n";
		return;
	}
	int cantidad, codigoM;
	char nombre[30];
	cout << "\n\n *** I N G R E S O   D E   M A T E R I A S ***\n\n";
	cout << "Cantidad de materias a ingresar: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++) {
		cout << "Ingrese codigo: ";
		cin >> codigoM;
		cout << "Ingrese materia: ";
		cin >> nombre;

		archivoMateriasOut << codigoM << ' ' << nombre << "\n";
	}

	archivoMateriasOut.close();
}

void Notas::consultarMaterias() {
	ifstream archivoMateriasIn("materias.dat", ios::in);
	if (!archivoMateriasIn) {
		cout << "Error al intentar abrir el archivo .dat\n";
		return;
	}

	archivoMateriasIn.seekg(0, ios::beg);

	int codigoM;
	char nombre[30];
	cout << "\n\n *** C O N S U L T A   D E   M A T E R I A S ***\n\n";
	while (archivoMateriasIn >> codigoM >> nombre) {
		cout << codigoM << ' ' << nombre << "\n";
	}

}

void Notas::registrarNotas() {
	ofstream archivoNotasOut("notas.dat", ios::app);

	cout << "\n\n *** I N G R E S O   D E   N O T A S ***\n\n";

	if (!archivoNotasOut) {
		cout << "Error al intentar abrir el archivo notas.dat\n";
		return;
	}
	int opcion = 0;
	int nota;

	do {
		char nombreM[30];
		char nombreA[50];
		int codigoM, codigoA;

		do {
			cout << "Ingrese Materia: ";
			cin >> nombreM;
			codigoM = ObtenerCodigoMateria(nombreM);
		} while (codigoM == -1);
		do {
			cout << "Ingrese Alumno: ";
			cin >> nombreA;
			codigoA = ObtenerCodigoAlumno(nombreA);
		} while (codigoA == -1);

		cout << "Ingrese Nota: ";
		cin >> nota;

		archivoNotasOut << codigoM << ' ' << codigoA << ' ' << nota << "\n";
		cout << "Desea ingresar una nueva nota? -1 para salir. ";
		cin >> opcion;

	} while (opcion != -1);

	archivoNotasOut.close();

}

int Notas::ObtenerCodigoMateria(char * nombreM) {
	ifstream archivoMateria("materias.dat", ios::in);

	if (!archivoMateria) {
		cout << "Error al intentar abrir el archivo notas.dat\n";
		return -1;
	}

	archivoMateria.seekg(0, ios::beg);
	int codigo;
	char nombre[30];

	while (archivoMateria >> codigo >> nombre) {
		if (strcmp(nombre, nombreM) == 0) {
			return codigo;

		}
	}
	return -1;
}

/*char * Notas::obtenerNombreAlumno(const int codigoAlumno) {
	ifstream archivoAlumnos("alumnos.dat", ios::in);

	if (!archivoAlumnos) {
		cout << "Error al intentar abrir el archivo alumnos,dat";
		return NULL;
	}
	
	int codigo, edad;
	char nombre[50];
	archivoAlumnos.seekg(0, ios::beg);

	while (archivoAlumnos >> codigo >> nombre >> edad) {
		if (codigoAlumno == codigo) {
			char *retorno = new char[strlen(nombre)];
			strcpy(retorno, nombre);
			retorno[strlen(nombre)] = '\0';
			archivoAlumnos.close();
			return retorno;
		}
	}

	archivoAlumnos.close();
	return NULL;

}*/

/*char * Notas::obtenerNombreMateria(const int codigoMateria) {
	ifstream archivoMaterias("materias.dat", ios::in);

	if (!archivoMaterias) {
		cout << "Error al intentar abrir el archivo alumnos.dat";
		return NULL;
	}

	int codigo, edad;
	char nombre[30];

	archivoMaterias.seekg(0, ios::beg);
	while (archivoMaterias >> codigo >> nombre >> edad) {
		if (codigoMateria == codigo) {
			char *retorno = new char[strlen(nombre)];
			strcpy(retorno, nombre);
			retorno[strlen(nombre)] = '\0';
			archivoMaterias.close();
			return retorno;
		}
	}

	archivoMaterias.close();
	return NULL;

}*/

/*void Notas::consultarNotas() {
	ifstream archivoNotas("notas.dat", ios::in);

	if (!archivoNotas) {
		cout << "Error al intentar abrir el archivo notas.dat";
		return;
	}
	cout << "\n\n *** C O N S U L T A   D E   N O T A S ***\n\n";
	
	int codigoM, codigoA, nota;

	archivoNotas.seekg(0, ios::beg);

	while (archivoNotas >> codigoM >> codigoA >> nota) {
		cout << obtenerNombreMateria(codigoM) << ' ' <<
			obtenerNombreAlumno(codigoA) << ' ' << nota << '\n';
	}
}*/

int Notas::ObtenerCodigoAlumno(char * nombreA) {
	ifstream archivoAlumnos("alumnos.dat", ios::in);

	if (!archivoAlumnos) {
		cout << "Error al intentar abrir el archivo notas.dat\n";
		return -1;
	}

	archivoAlumnos.seekg(0, ios::beg);
	int codigo, edad;
	char nombre[30];

	while (archivoAlumnos >> codigo >> nombre >> edad) {
		if (strcmp(nombre, nombreA) == 0) {
			return codigo;

		}
	}
	
	return -1;
}

void Notas::PromedioAlumno() {
	ifstream archivoNotasProm("notas.dat", ios::in);

	if (!archivoNotasProm) {
		cout << "Error al intentar abrir el archivo notas.dat\n";
		return;
	}
	archivoNotasProm.seekg(0, ios::beg);
	char nombreA[50];
	int codigoM, codigoA;
	int nota;
	int codigoNom;
	double promedio = 0 , total = 0, cant = 0;

	cout << "\n\n *** C O N S U L T A   D E   P R O M E D I O   A L U M N O ***\n\n";

	cout << "Ingrese Alumno: ";
	cin >> nombreA;
	codigoNom = ObtenerCodigoAlumno(nombreA);

	while (archivoNotasProm >> codigoM >> codigoA >> nota) {
		if (codigoNom == codigoA) {
			total = total + nota;
			cant++;
		}
	}
	promedio = total / cant;
	cout << "El promedio del Alumno " << nombreA << " es de: " << promedio;
}

void Notas::PromedioMateria() {
	ifstream archivoNotasMateriaProm("notas.dat", ios::in);
	if (!archivoNotasMateriaProm) {
		cout << "Error al intentar abrir el archivo notas.dat\n";
		return;
	}
	archivoNotasMateriaProm.seekg(0, ios::beg);
	char nombreM[30];
	int codigoM, codigoA;
	int nota;
	int codigoMat;
	double promedio = 0, total = 0, cant = 0;

	cout << "\n\n *** C O N S U L T A   D E   P R O M E D I O   M A T E R I A ***\n\n";

	cout << "Ingrese Materia: ";
	cin >> nombreM;
	codigoMat = ObtenerCodigoMateria(nombreM);

	while (archivoNotasMateriaProm >> codigoM >> codigoA >> nota) {
		if (codigoMat == codigoM) {
			total = total + nota;
			cant++;
		}
	}
	promedio = total / cant;
	cout << "El promedio en la materia " << nombreM << " es de: " << promedio;
}