#pragma once
#include "Persona.hpp"
#include <string>

class ListaPersonas {
	private:
		int contador = 0;
		int max = 0;
		Persona** lista = nullptr;
    //Persona* lista{0} = new Persona[100];


	public:

		ListaPersonas(int max);

		//bool agregarPersona(Persona &persona);
    bool agregarPersona(Persona* persona);
    //&

		Persona* buscarPersona(
			std::string &nombre, 
			std::string &apellido
		);

    bool eliminarPersona(
      std::string &nombre, 
      std::string &apellido
    );

		Persona* getPersonaI(int indice);

		int getCantidadPersonas();

    int getMaximoPersonas();

		~ListaPersonas();
};