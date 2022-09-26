#include "../includes/Estudiante.hpp"

Estudiante::Estudiante(std::string &nombre, std::string &apellido,
                       int edad, int semestre)
    : inherited(nombre, apellido), edad(edad), semestre(semestre),
      listaRamos(5) {}

int Estudiante::getEdad() { return this->edad; }

void Estudiante::setEdad(int edad) { this->edad = edad; }

int Estudiante::getSemestre() { return this->semestre; }

void Estudiante::setSemestre(int semestre) { this->semestre = semestre; }

std::string Estudiante::toString() {
  std::string salida = "[ESTUDIANTE]\n";
  salida += Persona::toString();
  salida += "Edad: " + std::to_string(this->edad) + "\n";
  salida += "Semestre: " + std::to_string(this->semestre) + "\n";
  return salida;
}