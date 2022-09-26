#include "../includes/Profesor.hpp"

Profesor::Profesor(std::string &nombre, std::string &apellido)
    : inherited(nombre, apellido), listaRamos(5) {}

std::string Profesor::toString() {
  std::string salida = "[PROFESOR]\n";
  salida += Persona::toString();
  return salida;
}