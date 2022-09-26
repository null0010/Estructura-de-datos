#pragma once
#include "Persona.hpp"
#include "ListaRamos.hpp"

class Profesor : public Persona {
	private:
    ListaRamos listaRamos;
    typedef Persona inherited;

	public:
    Profesor();

		Profesor(
			std::string &nombre, 
			std::string &apellido
		);

    std::string toString();
};

