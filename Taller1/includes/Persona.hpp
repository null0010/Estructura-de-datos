#pragma once
#include <string>

class Persona {
	protected:
		std::string nombre = "";
		std::string apellido = "";

	public:
    //PREGUNTAR AL PROFESOR SOBRE EL VIRTUAL
		Persona();

		Persona(std::string &nombre, std::string &apellido);

		std::string getNombre();

		void setNombre(std::string &nombre);

		std::string getApellido();

		void setApellido(std::string &apellido);

    //PREGUNTAR AL PROFESOR SOBRE VIRTUAL = 0;
    virtual std::string toString();
};