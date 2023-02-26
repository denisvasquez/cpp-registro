#include <iostream>
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

  Student (string n, int e, string ec, string d, string em) {
    this->nombre_completo = n;
    this->edad = e; 
    this->e_civil = ec;
    this->direccion = d;
    this->e_mail = em;
    this->carrera = "cualquier cosa";
  }
};

int main () {
  Student students[1];
  Student student;
  cout << "Ingresa tu nombre completo: "; cin >> student.nombre_completo;

  cout << student.nombre_completo << endl;

  return 0;
}
