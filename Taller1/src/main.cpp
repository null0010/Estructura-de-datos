//#include "../includes/TestClass.hpp"
#include "../includes/AppGestion.hpp"
#include "../includes/Estudiante.hpp"
#include "../includes/ListaPersonas.hpp"
#include <iostream>
#include <limits>

enum OPCIONES_MENUPRINCIPALES {
  CONSULTAR = 0,
  AGREGAR = 1,
  MODIFICAR = 2,
  ELIMINAR  = 3,
  SALIR = 4
};

enum TIPOS_SUB_MENUPRINCIPALES {
  ESTUDIANTE = 0,
  PROFESOR = 1,
  RAMO = 2,
  RETROCEDER = 3
};


void clearCin() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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


int getOpcionNumero(std::string rutaOpciones, int limiteIzquierda, int limiteDerecha) {
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
  } while (opcionNumber < limiteIzquierda || opcionNumber > limiteDerecha);

  opcionNumber--;
  return opcionNumber;
}

int main() {
  // TestClass test;
  // test.start();

  AppGestion app;
  bool running = true;
  while (running) {
    int opcionNumber;
    int opcionMenuPrincipal;
    int opcionSubMenuPrincipal;
    std::string rutaOpciones = "[";
    std::cout << app.getMenuPrincipal() << std::endl;
    opcionNumber = getOpcionNumero(rutaOpciones, 1, 5);
    opcionMenuPrincipal = opcionNumber;
    if (opcionMenuPrincipal != SALIR) {
      std::string opcionesMenuPrincipal[] = {"Consultar", "Agregar",
                                             "Modificar", "Eliminar"};
      rutaOpciones += opcionesMenuPrincipal[opcionNumber];
      std::cout << app.getSubMenuPrincipal() << std::endl;
      opcionNumber = getOpcionNumero(rutaOpciones, 1, 4);
      if (opcionNumber == RETROCEDER) {
        continue;
      }

      opcionSubMenuPrincipal = opcionNumber;
      std::string opcionesSubMenuPrincipal[] = {"Estudiante", "Profesor",
                                                "Ramo"};
      std::string tipo = opcionesSubMenuPrincipal[opcionNumber];
      bool ingresado = false;
      bool eliminado = false;
      switch (opcionMenuPrincipal) {
      case CONSULTAR:
        if (opcionSubMenuPrincipal == RAMO) {
          std::cout << "[Consultar Ramo]" << std::endl;
          std::cout << "Ingrese nombre del ramo: ";
          std::string nombreRamo;
          std::cin >> nombreRamo;
          std::cout << "Ingrese carrera del ramo: ";
          std::string carreraRamo;
          std::cin >> carreraRamo;
          std::string salida = app.obtenerDatosRamo(nombreRamo, carreraRamo);
          std::cout << salida << std::endl;
        } else {
          std::cout << "Ingrese nombre del " + tipo + ": ";
          std::string nombre;
          std::cin >> nombre;
          std::cout << "Ingrese apellido del " + tipo + ": ";
          std::string apellido;
          std::cin >> apellido;

          if (opcionSubMenuPrincipal == ESTUDIANTE 
            && !app.existeEstudiante(nombre, apellido)) {
            std::cout << "Estudiante no existe.\n" << std::endl;
            continue;
          }
          else if (opcionSubMenuPrincipal == PROFESOR
            && !app.existeProfesor(nombre, apellido)) {
            std::cout << "Profesor no existe.\n" << std::endl;
            continue;
          }
          
          std::string salida = app.obtenerDatosPersona(nombre, apellido);
          std::cout << salida << std::endl;
        }

        break;

      case AGREGAR:
        if (opcionSubMenuPrincipal == RAMO) {
          std::cout << "[Agregar Ramo]\n" << std::endl;
          std::cout << "Ingrese nombre del ramo: ";
          std::string nombreRamo;
          std::cin >> nombreRamo;
          std::cout << "Ingrese carrera del ramo: ";
          std::string carreraRamo;
          std::cin >> carreraRamo;
          std::cout << "Ingrese sala del ramo: ";
          int salaRamo;
          std::cin >> salaRamo;
          clearCin();
          ingresado = app.ingresarRamo(nombreRamo, carreraRamo, salaRamo);

        } else if (opcionSubMenuPrincipal == ESTUDIANTE) {
      
          // crear variables, guiarse por el ingresar ramo
          std::cout << "[Agregar Estudiante]\n" << std::endl;
          std::cout << "Ingrese nombre del Estudiante: ";
          std::string nombre;
          std::cin >> nombre;
          std::cout << "Ingrese apellido del Estudiante: ";
          std::string apellido;
          std::cin >> apellido;
          int edad;
          std::cout << "Ingrese edad del Estudiante: ";
          std::cin >> edad;
          int semestre;
          std::cout << "Ingrese semestre del Estudiante: ";
          std::cin >> semestre;
          clearCin();
          ingresado = app.ingresarEstudiante(nombre, apellido, edad, semestre);
          //INGRESAR RAMOS ESTUDIANTE, VERIFICAR QUE HAYAN ALMENOS UN RAMO 

        } else if (opcionSubMenuPrincipal == PROFESOR) {
          std::cout << "[Agregar Profesor]\n" << std::endl;
          std::cout << "Ingrese nombre del Profesor: ";
          std::string nombre;
          std::cin >> nombre;
          std::cout << "Ingrese apellido del Profesor: ";
          std::string apellido;
          std::cin >> apellido;
          clearCin();
          ingresado = app.ingresarProfesor(nombre, apellido);
           //INGRESAR RAMOS ESTUDIANTE
        }

        if (ingresado) {
          std::cout << tipo + " ingresado.";
        } else {
          std::cout << tipo + " no fue ingresado.";
        }

        break;

      case MODIFICAR:
        if (opcionSubMenuPrincipal == RAMO) {
          std::cout << "Ingrese nombre del ramo: ";
          std::string nombreRamo;
          std::cin >> nombreRamo;
          std::cout << "Ingrese carrera del ramo: ";
          std::string carreraRamo;
          std::cin >> carreraRamo;
          if (app.existeRamo(nombreRamo, carreraRamo)) {
            std::cout << "Ingrese nuevo nombre del Ramo: ";
            std::string nuevoRamo;
            std::cin >> nuevoRamo;
            std::cout << "Ingrese nueva carrera del Ramo: ";
            std::string nuevaCarrera;
            std::cin >> nuevaCarrera;
            std::cout << "Ingrese nueva sala del Ramo: ";
            int nuevaSala;
            std::cin >> nuevaSala;
            clearCin();
            if (!app.existeRamo(nuevoRamo, nuevaCarrera)) {
              app.setRamo(nombreRamo, carreraRamo, nuevoRamo, nuevaCarrera, nuevaSala);
              std::cout << "Ramo modificado exitosamente.\n" << std::endl;
            } else {
              std::cout << "Ya existe un Ramo con esos datos\n" << std::endl;
            }
          }
          else{
            std::cout << "Ramo no existe\n" << std::endl;
          }
        }
        else if (opcionSubMenuPrincipal == ESTUDIANTE) {  
            std::cout << "Ingrese nombre del Estudiante: ";
            std::string nombre;
            std::cin >> nombre;
            std::cout << "Ingrese apellido del Estudiante: ";
            std::string apellido;
            std::cin >> apellido;
            if (app.existeEstudiante(nombre, apellido)) { 
                std::cout << "Ingrese nuevo nombre del Estudiante: ";
                std::string nuevoNombre;
                std::cin >> nuevoNombre;
                std::cout << "Ingrese nuevo apellido del Estudiante: ";
                std::string nuevoApellido;
                std::cin >> nuevoApellido;
                if (app.existeEstudiante(nuevoNombre, nuevoApellido)) {
                  std::cout << "Ya existe un estudiante con esos nombres.\n" << std::endl;
                  continue;
                }
              
                std::cout << "Ingrese nueva edad del Estudiante: ";
                int nuevaEdad;
                std::cin >> nuevaEdad;
                int nuevoSemestre;
                std::cout << "Ingrese nuevo semestre del Estudiante: ";
                std::cin >> nuevoSemestre;
                clearCin();
                app.setEstudiante(nombre, apellido, nuevoNombre, nuevoApellido,
                                      nuevaEdad, nuevoSemestre);
                std::cout << "Estudiante modificado exitosamente.\n" << std::endl;
            }
            else {
              std::cout << "Estudiante no existe\n" << std::endl;
            }
        }
        else if (opcionSubMenuPrincipal == PROFESOR) {
          std::cout << "Ingrese nombre del Profesor: ";
          std::string nombre;
          std::cin >> nombre;
          std::cout << "Ingrese apellido del Profesor: ";
          std::string apellido;
          std::cin >> apellido;
          if (app.existeProfesor(nombre, apellido)) {          
            std::cout << "Ingrese nuevo nombre del Profesor: ";
            std::string nuevoNombre;
            std::cin >> nuevoNombre;
            std::cout << "Ingrese nuevo apellido del Profesor: ";
            std::string nuevoApellido;
            std::cin >> nuevoApellido;
            clearCin();
            if (app.existeProfesor(nuevoNombre, nuevoApellido)) {
              std::cout << "Ya existe un profesor con esos nombres.\n" << std::endl;
              continue;
            }

            app.setProfesor(nombre, apellido, nuevoNombre, nuevoApellido);
            std::cout << "Profesor modificado exitosamente.\n" << std::endl;
          }
          else {
            std::cout << "Profesor no existe\n" << std::endl;
          }
        }
        break;
   
        case ELIMINAR:
          if (opcionSubMenuPrincipal == RAMO) {
            std::cout << "Ingrese nombre del ramo: ";
            std::string nombreRamo;
            std::cin >> nombreRamo;
            std::cout << "Ingrese carrera del ramo: ";
            std::string carreraRamo;
            std::cin >> carreraRamo;
            clearCin();
            //if (app.existeRamo(nombreRamo, carreraRamo)) {
            eliminado = app.eliminarRamo(nombreRamo, carreraRamo);
            if(eliminado) {
              std::cout << "\nRamo eliminado exitosamente\n" << std::endl;
            } else {
                std::cout << "\nRamo no pudo ser eliminado exitosamente.\n" << std::endl;
            }
            //}
          }
          else {  
            std::cout << "Ingrese nombre del " + tipo + ": ";
            std::string nombre;
            std::cin >> nombre;
            std::cout << "Ingrese apellido del " + tipo + ": ";
            std::string apellido;
            std::cin >> apellido;
            clearCin();
            if (opcionSubMenuPrincipal == ESTUDIANTE 
            && !app.existeEstudiante(nombre, apellido)) {
              std::cout << "Estudiante no existe.\n" << std::endl;
              continue;
            }
            else if (opcionSubMenuPrincipal == PROFESOR
              && !app.existeProfesor(nombre, apellido)) {
              std::cout << "Profesor no existe.\n" << std::endl;
              continue;
            }
            
            eliminado = app.eliminarPersona(nombre, apellido);
            if (eliminado) {
              std::cout <<"\n" << tipo << " eliminado exitosamente\n" << std::endl;
            }
            else {
              std::cout<<"\n" << tipo << " no pudo ser eliminado exitosamente.\n" << std::endl;
            }
          }
          
          break;
        }
    } 
    else {
      running = false;
    }
  }

  return 0;
}