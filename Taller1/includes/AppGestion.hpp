#pragma once
#include <string>
#include "ListaRamos.hpp"

class AppGestion {
  private:
    ListaRamos listaRamos;
    ListaPersonas listaPersonas;

  public:
    AppGestion();

    bool ingresarEstudiante(
      std::string &nombre,
      std::string &apellido,
      int edad,
      int semestre
    );

    bool ingresarProfesor(
      std::string &nombre,
      std::string &apellido
    );

    bool ingresarRamo(
      std::string &nombre,
      std::string &carrera,
      int sala
    );

    bool eliminarRamo(std::string &nombre, std::string &carrera);

    bool eliminarPersona(std::string &nombre, std::string &apellido);

    std::string obtenerDatosPersona(std::string &nombre, std::string &apellido);

    std::string obtenerDatosRamo(std::string &nombre, std::string &carrera);

    std::string getMenuPrincipal();

    std::string getSubMenuPrincipal();

    //std::string getSubMenuModificar();

    bool existeEstudiante(std::string &nombre, std::string &apellido);

    bool existeProfesor(std::string &nombre, std::string &apellido);

    bool existeRamo(std::string &nombre, std::string &carrera); 

    void setEstudiante(std::string &nombre, std::string &apellido, std::string &nuevoNombre, std::string &nuevoApellido, int nuevaEdad, int nuevoSemestre);

    void setProfesor(std::string &nombre, std::string &apellido, std::string &nuevoNombre, std::string &nuevoApellido);
    
    void setRamo(std::string &nombre, std::string &carrera, std::string &nuevoNombre, std::string &nuevaCarrera, int nuevaSala);

    
};