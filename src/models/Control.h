struct Control {
  protected:
  fstream archivo;

  void abrir (string nombre_archivo) {
    if (nombre_archivo != "") {
      return this->archivo.open(nombre_archivo, std::ios_base::app | std::ios_base::in);
    }
  }

  public:
  string generar_contra () {
    string contra;
    
    string abc = "accdefghijklmnopqrstuvwxyz";
    string Abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string nums = "1234567890";
    string signos = "~$-/[{&#=}]%!";
    string todo_junto = abc.append(nums).append(Abc).append(signos);

    for (int i = 0; i<6; i++) {
      int pos = 1+rand()%(todo_junto.length()-1);
      contra += todo_junto[pos];
    }

    return contra;
  }

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

    informacion.contra = this->generar_contra();

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
