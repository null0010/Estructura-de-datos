#include "../includes/Ramo.hpp"
#include <iostream>

//Ramo::Ramo(): listaAlumnos(1) {}
/*
Ramo::Ramo(): 
	nombre(""),
	carrera(""),
	sala(0){}//,// {}*/
  //listaAlumnos(10) {}
	//listaAlumnos(100),
	//listaProfesores(100) {}

Ramo::Ramo(
	std::string &nombre, 
	std::string &carrera, 
	int sala):
		nombre(nombre),
		carrera(carrera),
		sala(sala),
    listaAlumnos(2) {}//,
		//listaAlumnos(100),
		//listaProfesores(100) {}

std::string Ramo::getNombre() 
{
	return this->nombre;
}

void Ramo::setNombre(std::string &nombre) 
{
	this->nombre = nombre;
}

std::string Ramo::getCarrera() 
{
	return this->carrera;
}

void Ramo::setCarrera(std::string &carrera) 
{
	this->carrera = carrera;
}

int Ramo::getSala() 
{
	return this->sala;
}

void Ramo::setSala(int sala)
{
	this->sala = sala;
}

std::string Ramo::toString() {
  std::string salida = "";
  salida += "Nombre: " + this->nombre + "\n";
  salida += "Carrera: " + this->carrera + "\n";
  salida += "Sala: " + std::to_string(this->sala) + "\n";

  
  //std::cout << "LISTAPERSONA: " << this->listaAlumnos.getMaximoPersonas() << std::endl;
 
  
  return salida;
}