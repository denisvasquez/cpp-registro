#include <string>

using namespace std;

struct Info {
  string sede;
  string carrera;
  string curso;
  string seccion;
};

struct Student : Info {
  int edad;
  string nombre_completo;
  string e_civil;
  string direccion;
  string e_mail;
  
  Student () {};

  Student (string nombre, int edad, string ecivil, string direccion, string email) {
    this->nombre_completo = nombre;
    this->edad = edad;
    this->e_civil = ecivil;
    this->direccion = direccion;
    this->e_mail = email;
  }

  string name (string nombre = "") {
    if (nombre.length() == 0) {
      return this->nombre_completo;
    }

    return this->nombre_completo = nombre;
  }
};
