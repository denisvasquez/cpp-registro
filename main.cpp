#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;


bool logged = false;

struct Info {
  string carnet;
  string contra;
  string sede;
  string carrera;
  string seccion;
  int c_cursos;
  string *cursos;
};


struct Estudiante {
  int edad;
  string nombre_completo;
  string e_civil;
  string direccion;
  string e_mail;
};

struct Control {
  protected:
  fstream archivo;

  void abrir (string nombre_archivo) {
    if (nombre_archivo != "") {
      return this->archivo.open(nombre_archivo, std::ios_base::app | std::ios_base::in);
    }
  }

  public:
  void escribir (Estudiante estudiante, Info informacion) {

    this->abrir("src/sedes/sede_"+informacion.sede+".csv");
    
    srand(time(NULL));
    informacion.carnet.append(informacion.sede+"-");
 
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%y", now);

    informacion.carnet.append(buffer);
    informacion.carnet.append("-"+to_string(1000+rand() % (9999)));
    cout << informacion.carnet << endl;

    string abc = "accdefghijklmnopqrstuvwxyz";
    string Abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string nums = "1234567890";
    string signos = "~$-/[{&#=}]%!";
    string todo_junto = abc.append(nums).append(Abc).append(signos);

    for (int i = 0; i<6; i++) {
      int pos = 1+rand()%(todo_junto.length()-1);
      informacion.contra += todo_junto[pos];
    }

    this->archivo << informacion.carnet << ",";
    this->archivo << informacion.contra << ",";
    this->archivo << estudiante.nombre_completo << ",";
    this->archivo << estudiante.edad << ",";
    this->archivo << estudiante.e_civil << ",";
    this->archivo << estudiante.direccion << ",";
    this->archivo << estudiante.e_mail << ",";
    this->archivo << informacion.carrera << ",";
    this->archivo << informacion.sede << ",";
    this->archivo << informacion.seccion << ",";
    for (int i = 0; i<informacion.c_cursos; i++) {
      this->archivo << *(informacion.cursos+i) <<"," ;
    }
    this->archivo << endl;

    this->archivo.close();

  }

  bool sede_registrada (string sede) {
    this->abrir("src/sedes_registradas.csv");

    string linea;
    while (getline(this->archivo, linea)) {
      if (linea == sede) {
        this->archivo.close();
        return true;
      }
    }

    this->archivo.close();
    return false;
  }

};

int main () {
  int opcion = 0;

  while (true) {
    if (!logged) {
      cout << "+----------------------------------+" << endl;
      cout << "|          nombre del grupo        |" << endl;
      cout << "+----------------------------------+" << endl << endl;
      cout << "1. Iniciar sesion" << endl;
      cout << "2. Inscribirme" << endl;
      cout << "3. Salir" << endl;
      cout << "Seleccione (1-3): "; cin >> opcion;

      if (opcion > 3 | opcion < 1) {
        cout << "!Numero fuera de rango!" << endl;
      }

      if (opcion == 2) {
        Estudiante estudiante;

        cout << "+-----------------------------------+" << endl;
        cout << "|    Ingreso de datos personales    |" << endl;
        cout << "+-----------------------------------+" << endl << endl;
        cout << "Ingresa tu nombre completo: "; cin >> estudiante.nombre_completo;
        cout << "Ingresa tu edad: "; cin >> estudiante.edad;
        cout << "Ingresa tu estado civil: "; cin >> estudiante.e_civil;
        cout << "Ingresa tu direccion: "; cin >> estudiante.direccion;
        cout << "Ingresa tu email: "; cin >> estudiante.e_mail;

        Info informacion;

        cout << "+-----------------------------------+" << endl;
        cout << "|    Ingreso de datos academicos    |" << endl;
        cout << "+-----------------------------------+" << endl << endl;
        cout << "Ingresa el codigo de tu sede: "; cin >> informacion.sede;
        cout << "Ingresa tu carrera: "; cin >> informacion.carrera;
        cout << "Ingresa tu seccion: "; cin >> informacion.seccion;
        cout << "Ingresa cantidad de cursos que tienes: "; cin >> informacion.c_cursos;

        informacion.cursos = new string[informacion.c_cursos];

        for (int i = 0; i<informacion.c_cursos; i++) {
          cout << "[" << i << "] -> curso: "; cin >> *(informacion.cursos+i);
        }
        
        Control control;

        if (control.sede_registrada(informacion.sede)) {
          control.escribir(estudiante, informacion);
        } else {
          cout << "La sede, no existe!" << endl;
        }

      }

      if (opcion == 3) break;

      continue;
    }

    cout << "1. Mostrar mi información" << endl;
    cout << "2. Cerrar sesion" << endl;
    cout << "Seleccione (1-2): "; cin >> opcion;

    if (opcion == 2) logged = false;

  }

  return 0;
}
