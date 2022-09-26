#pragma once
#include "Ramo.hpp"
#include <string.h>

class ListaRamos {
	private:
		int contador = 0;
		int max = 0;
		//Ramo* lista = nullptr;
    Ramo* lista = nullptr;


	public:
		ListaRamos(int max);

		bool agregarRamo(Ramo &ramo);

    bool eliminarRamo(std::string &nombre, std::string &carrera);
		Ramo* buscarRamo(
			std::string &nombre,
      std::string &carrera
		);
  
		Ramo* getRamoI(int indice);

		int getCantidadRamos();

		~ListaRamos();
};