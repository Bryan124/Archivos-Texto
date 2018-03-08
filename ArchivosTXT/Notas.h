#pragma once
#ifndef NOTAS_H

#define NOTAS_H

class Notas {
public:
	static void registrarAlumnos();
	static void consultarAlumnos();
	static void registrarMaterias();
	static void consultarMaterias();
	static void registrarNotas();
	static void consultarNotas();
	static int ObtenerCodigoAlumno(char *);
	static int ObtenerCodigoMateria(char *);
	static char * obtenerNombreAlumno(const int);
	static char * obtenerNombreMateria(const int);
	static void PromedioAlumno();
	static void PromedioMateria();
};

#endif // !NOTAS_H