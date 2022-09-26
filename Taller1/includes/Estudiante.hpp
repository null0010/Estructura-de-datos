#pragma once
#include <string>
#include "Persona.hpp"
#include "ListaRamos.hpp"

class Estudiante : public Persona {
	private:
    int edad = 0;
		int semestre = 0;
		ListaRamos listaRamos;
    typedef Persona inherited;

	public:
    //Estudiante();

		Estudiante(
			std::string &nombre, 
			std::string &apellido, 
			int edad,
      int semestre
		);

		int getEdad();

		void setEdad(int edad);

    int getSemestre();

		void setSemestre(int semestre);

    std::string toString();
};