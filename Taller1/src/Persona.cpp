#include "../includes/Persona.hpp"

Persona::Persona() : nombre(""), apellido("") {}

Persona::Persona(std::string &nombre, std::string &apellido)
    : nombre(nombre), apellido(apellido) {}

std::string Persona::getNombre() { return this->nombre; }

void Persona::setNombre(std::string &nombre) { this->nombre = nombre; }

std::string Persona::getApellido() { return this->apellido; }

void Persona::setApellido(std::string &apellido) { this->apellido = apellido; }

std::string Persona::toString() { 
  std::string salida = "";
  salida += "Nombre: " + this->nombre + "\n";
  salida += "Apellido: " + this->apellido + "\n";
  return salida; 
}