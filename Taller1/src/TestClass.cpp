#include "../includes/TestClass.hpp"
#include "../includes/Estudiante.hpp"
#include "../includes/Persona.hpp"
#include "../includes/ListaPersonas.hpp"
//#include 
/*
#include "../includes/TestClass.hpp"
#include "../includes/AppGestion.hpp"
#include "../includes/Estudiante.hpp"
#include "../includes/ListaPersonas.hpp"
#include <iostream>
#include <limits>

enum OPCIONES_MENUPRINCIPALES {
  CONSULTAR = 0,
  AGREGAR = 1,
  MODIFICAR = 2,
  SALIR = 3
};

enum OPCIONES_SUBMENUPRINCIPALES {
  ESTUDIANTE = 0,
  PROFESOR = 1,
  RAMO = 2,
  RETROCEDER = 3
};


void stringToLower(std::string &string1) {
  int i = 0;
  while (string1[i] != '\0') {
    string1[i] = std::tolower(string1[i]);
    i++;
  }
}


void clearCin() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


bool isRespuestaAfirmativa() {
  std::string respuesta = "";
  std::cout << "Ingrese su respuesta: (SI/NO): ";
  std::cin >> respuesta;
  stringToLower(respuesta);
  while (respuesta != "si" && respuesta != "no") {
    clearCin();
    std::cout << "Ingrese su respuesta: (SI/NO): ";
    std::cin >> respuesta;
    stringToLower(respuesta);
  }

  return respuesta == "si";
}


bool startWithNumbers(std::string &string1) {
  bool success = false;
  try {
    std::stoi(string1);
    success = true;
  } catch (const std::invalid_argument &ia) {
    success = false;
  }

  return success;
}

int getOpcionNumero(std::string rutaOpciones) {
  int opcionNumber = -1;
  do {
    std::cout << "Ingrese una opción (numero) \n";
    std::cout << rutaOpciones + "] > ";
    std::string opcion = "";
    std::cin >> opcion;
    std::cout << std::endl;
    while (!startWithNumbers(opcion)) {
      clearCin();
      std::cout << "Ingrese una opción (numero) \n";
      std::cout << rutaOpciones + "] > ";
      std::cin >> opcion;
      std::cout << std::endl;
    }

    opcionNumber = std::stoi(opcion);
  } while (opcionNumber < 1 || opcionNumber > 4);

  opcionNumber--;
  return opcionNumber;
}
*/
void TestClass::start() {
  std::string nombre = "Jose";
  std::string apellido = "Rodriguez";

  ListaPersonas listaPersonas(100);
  Estudiante *estudiante = new Estudiante(nombre, apellido, 2, 16);
  listaPersonas.agregarPersona(estudiante);
  Persona* persona = listaPersonas.buscarPersona(nombre, apellido);
  std::cout << persona->toString();

  
 // Persona* lista = new Persona[100];
  /*
  Persona** lista = new Persona*[5];
  Estudiante *estudiante = new Estudiante(nombre, apellido, 2, 16);
  lista[0] = estudiante;
  std::cout << lista[0]->toString();
*/
  /*
  //NO FUNCIONA CON ARREGLO
  Persona lista[100];
  lista[0] = estudiante;

  
  //NO FUNCIONA CON ARREGLO
  persona = &lista[0];
  std::cout << persona->toString();

  //FUNCIONA DIRECTO
  persona = &estudiante;
  std::cout << persona->toString();
  //delete persona;
  */
}
