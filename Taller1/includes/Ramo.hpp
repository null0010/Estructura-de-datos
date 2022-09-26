#pragma once
#include <string>
#include "ListaPersonas.hpp"

class Ramo {
	private:
		std::string nombre = "";
		std::string carrera = "";
		int sala = 0;
		ListaPersonas listaAlumnos;
		//ListaPersonas listaProfesores;
	
	public:
		//Ramo();

		Ramo(
			std::string &nombre, 
			std::string &carrera, 
			int sala
		);

		std::string getNombre();

		void setNombre(std::string &nombre);

		std::string getCarrera();

		void setCarrera(std::string &carrera);

		int getSala();

		void setSala(int sala);

    std::string toString();

		//crear getAlumnoI

		//crear getProfesorI

		//buscarAlumno()

		//buscarProfesor
};