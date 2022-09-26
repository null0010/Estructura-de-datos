#include "../includes/AppGestion.hpp"
#include "../includes/Estudiante.hpp"
#include "../includes/Profesor.hpp"
#include <iostream>

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

AppGestion::AppGestion() : listaRamos(10), listaPersonas(1000) {}

bool AppGestion::ingresarEstudiante(std::string &nombre, std::string &apellido,
                                    int edad, int semestre) {
  Estudiante *estudiante = new Estudiante(nombre, apellido, edad, semestre);
  return this->listaPersonas.agregarPersona(estudiante);
}

bool AppGestion::ingresarProfesor(std::string &nombre, std::string &apellido) {
  Profesor *profesor = new Profesor(nombre, apellido);
  return this->listaPersonas.agregarPersona(profesor);
}

bool AppGestion::ingresarRamo(std::string &nombre, std::string &carrera,
                              int sala) {
  Ramo ramo(nombre, carrera, sala);
  return this->listaRamos.agregarRamo(ramo);
}

bool AppGestion::eliminarRamo(std::string &nombre, std::string &carrera) {
  return this->listaRamos.eliminarRamo(nombre, carrera);
}

bool AppGestion::eliminarPersona(std::string &nombre, std::string &apellido) {
  return this->listaPersonas.eliminarPersona(nombre, apellido);
}



std::string AppGestion::obtenerDatosPersona(std::string &nombre,
                                            std::string &apellido) {
  std::string salida = "";
  Persona *persona = this->listaPersonas.buscarPersona(nombre, apellido);
  salida = persona->toString();
  return salida;
}

std::string AppGestion::obtenerDatosRamo(std::string &nombre,
                                         std::string &carrera) {
  std::string salida = "Ramo no existe.\n";
  Ramo *ramo = this->listaRamos.buscarRamo(nombre, carrera);
  if (ramo != nullptr) {
    salida = ramo->toString();
  }

  return salida;
}

bool AppGestion::existeRamo(std::string &nombre, std::string &carrera) {
  Ramo *ramo = listaRamos.buscarRamo(nombre, carrera);
  return ramo != nullptr;
}

void AppGestion::setRamo(std::string &nombre, std::string &carrera, std::string &nuevoNombre, std::string &nuevaCarrera, int nuevaSala) {
  Ramo* ramo = listaRamos.buscarRamo(nombre, carrera);
  ramo->setNombre(nuevoNombre);
  ramo->setCarrera(nuevaCarrera);
  ramo->setSala(nuevaSala);
}

bool AppGestion::existeEstudiante(std::string &nombre, std::string &apellido) {
  Persona *persona = listaPersonas.buscarPersona(nombre, apellido);
  return persona != nullptr && instanceof<Estudiante>(persona);
}


bool AppGestion::existeProfesor(std::string &nombre, std::string &apellido) {
  Persona *persona = listaPersonas.buscarPersona(nombre, apellido);
  return persona != nullptr && instanceof<Profesor>(persona);
}


void AppGestion::setEstudiante(std::string &nombre, std::string &apellido,
                               std::string &nuevoNombre,
                               std::string &nuevoApellido, int nuevaEdad,
                               int nuevoSemestre) {
  Persona* persona = listaPersonas.buscarPersona(nombre, apellido);
  persona->setNombre(nuevoNombre);
  persona->setApellido(nuevoApellido);
  Estudiante* estudiante = static_cast<Estudiante*>(persona);
  estudiante->setEdad(nuevaEdad);
  estudiante->setSemestre(nuevoSemestre);
}


void AppGestion::setProfesor(std::string &nombre, std::string &apellido,
                               std::string &nuevoNombre,
                               std::string &nuevoApellido) {
  
  Persona* persona = listaPersonas.buscarPersona(nombre, apellido);
  persona->setNombre(nuevoNombre);
  persona->setApellido(nuevoApellido);
}


std::string AppGestion::getMenuPrincipal() {
  std::string salida = "";
  salida += "\n";
  salida += "[OPCIONES DISPONIBLES]\n";
  salida += "\n";
  salida += "1) Consultar (Estudiante/Profesor/Ramo)\n";
  salida += "2) Agregar (Estudiante/Profesor/Ramo)\n";
  salida += "3) Modificar (Estudiante/Profesor/Ramo)\n";
  salida += "4) Eliminar (Estudiante/Profesor/Ramo)\n";
  salida += "5) Salir\n";
  return salida;
}

std::string AppGestion::getSubMenuPrincipal() {
  std::string salida = "";
  salida += "\n";
  salida += "[SUB-OPCIONES DISPONIBLES]\n";
  salida += "\n";
  salida += "1) Estudiante\n";
  salida += "2) Profesor\n";
  salida += "3) Ramo\n";
  salida += "4) Retroceder\n";
  return salida;
}
/*
std::string AppGestion::getSubMenuModificar() {
  std::string salida = "";
  salida += "\n";
  salida += "[SUB-OPCIONES DISPONIBLES]\n";
  salida += "\n";
  salida += "1) MODIFICAR\n";
  salida += "2) ELIMINAR\n";
  return salida;
}

*/