#include "../includes/ListaPersonas.hpp"
#include <iostream>

ListaPersonas::ListaPersonas(int max) {
  this->max = max;
  this->lista = new Persona*[max];
  //this->lista = (Persona*)malloc(sizeof(Persona) * max);
}

bool ListaPersonas::agregarPersona(Persona* persona) {
  if (this->contador < this->max) {
    //std::cout << this->contador << std::endl;
    //*(this->lista + this->contador) = persona;
    this->lista[this->contador] = persona;
    this->contador++;
    return true;
  }

  return false;
}

Persona* ListaPersonas::buscarPersona(
  std::string &nombre,
  std::string &apellido) 
{
  Persona* persona;
  bool encontrada = false;
  for (int i = 0; i < this->contador && !encontrada; i++) {
    persona = this->lista[i];
    std::string tempNombre = persona->getNombre();
    std::string tempApellido = persona->getApellido();
    bool nombreEncontrado = tempNombre == nombre;
    bool apellidoEncontrado = tempApellido == apellido;
    encontrada = nombreEncontrado && apellidoEncontrado;
    
  }

  if (encontrada) {
    return persona;
  }

  return nullptr;
}

bool ListaPersonas::eliminarPersona(
  std::string &nombre,
  std::string &apellido) 
{
  Persona* persona;
  bool encontrada = false;
  int i;
  for (i = 0; i < this->contador && !encontrada; i++) {
    persona = this->lista[i];
    std::string tempNombre = persona->getNombre();
    std::string tempApellido = persona->getApellido();
    bool nombreEncontrado = tempNombre == nombre;
    bool apellidoEncontrado = tempApellido == apellido;
    encontrada = nombreEncontrado && apellidoEncontrado;
 
  }

  if (encontrada) {
    delete lista[i];
    for (int j = i; j < this->contador - 1; j++) {
      lista[j] = lista[j + 1];
    }

    this->contador--;
    return true;
  }

  return false;
}

Persona *ListaPersonas::getPersonaI(int indice) {
  Persona *persona = nullptr;
  if (indice >= 0 && indice < this->contador) {
    persona = this->lista[indice];
  }

  return persona;
}



int ListaPersonas::getCantidadPersonas() { return this->contador; }

int ListaPersonas::getMaximoPersonas() { return this->max; }

ListaPersonas::~ListaPersonas() { 
  for(int i = 0; i < this->max; i++)
  {
    delete this->lista[i];
  }

  delete[] this->lista;
}