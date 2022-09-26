#include "../includes/ListaRamos.hpp"
#include <iostream>

ListaRamos::ListaRamos(int max)
{
	this->max = max;
	//this->lista = new Ramo[max];
  this->lista = (Ramo*)malloc(sizeof(Ramo) * max);
}

bool ListaRamos::agregarRamo(Ramo &ramo)
{
	if (this->contador < this->max) {
    //std::cout << this->contador << std::endl;
		//*(this->lista + this->contador) = ramo;
    this->lista[this->contador] = ramo;
		this->contador++;
		return true;
	}

	return false;
}

bool ListaRamos::eliminarRamo(std::string &nombre, std::string &carrera){
    Ramo* ramo;
    bool encontrado = false;
    int i;
    for(i = 0; i < this->contador  && !encontrado; i++){
      ramo = &this->lista[i];
      std::string tempNombre = ramo->getNombre();
      std::string tempCarrera = ramo->getCarrera();
      bool nombreEncontrado = tempNombre == nombre;
      bool carreraEncontrada = tempCarrera == carrera;
      encontrado = nombreEncontrado && carreraEncontrada;
    }
  
    if (encontrado) {
      for (int j = i; j < this->contador - 1; j++) {
        lista[j] = lista[j + 1];
      }

      this->contador--;
      return true;
    }
    
    return false;
  }


Ramo* ListaRamos::buscarRamo(
	std::string &nombre,
  std::string &carrera) 

{
	Ramo* ramo;
  bool encontrado = false;
	for (int i = 0; i < this->contador && !encontrado; i++) {
		ramo = &this->lista[i];
		std::string tempNombre = ramo->getNombre();
    std::string tempCarrera = ramo->getCarrera();
		bool nombreEncontrado = tempNombre == nombre;
    bool carreraEncontrada =  tempCarrera == carrera;
    encontrado = nombreEncontrado && carreraEncontrada;
	}

	if (encontrado) {
		return ramo;
	}

	return nullptr;
}


Ramo* ListaRamos::getRamoI(int indice) {
	Ramo* ramo = nullptr;
	if (indice >= 0 && indice < this->contador) {
		ramo = &this->lista[indice];
	}

	return ramo;
}


int ListaRamos::getCantidadRamos()
{
	return this->contador;
}


ListaRamos::~ListaRamos()
{
	free(this->lista);
}