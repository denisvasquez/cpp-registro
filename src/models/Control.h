struct Control {
  protected: // private
  fstream archivo;

  void abrir (string nombre_archivo) {
    if (nombre_archivo != "") {
      return this->archivo.open(nombre_archivo, std::ios_base::app | std::ios_base::in);
    }
  }

  public:

  //Function that generate a randow password
  string generar_contra () {

    string contra;
    
    string abc = "abcdefghijklmnopqrstuvwxyz";
    string Abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string nums = "1234567890";
    string signos = "~$-/[{&#=}]%!";
    string todo_junto = abc.append(nums).append(Abc).append(signos);

    for (int i = 0; i<6; i++) {
      int pos = 1+rand()%(todo_junto.length()-1);
      contra += todo_junto[pos];
    }
    //return the password for the student
    return contra;
  }

  string find (string texto, string sp, string parecido = "") {
    size_t pos = 0;
    string token;
    while ((pos = texto.find(sp)) != string::npos) {
      token = texto.substr(0, pos);

      if (parecido == "") {
        return token;
      }

      if (token == parecido) {
        return token;
      }
      
      texto.erase(0, pos + sp.length());
    }

    return token;
  }

  string mostrar_informacion (string texto, string sp) {
    string vector[] = {};
    size_t pos = 0;
    int pos_v = 0;
    string token;
    while ((pos = texto.find(sp)) != string::npos) {
      token = texto.substr(0, pos);

      vector[pos_v++] = token;
      
      texto.erase(0, pos + sp.length());
    }

    return vector;
  }



  void consultar_usuario (string cn, string contra) {
    string prefijo = cn.substr(0, cn.find("-"));
    this->abrir("src/sedes/sede_"+prefijo+".csv");
    string linea;

    while (getline(this->archivo, linea)) {
      string new_cn = this->find(linea, ",", cn);
      if (new_cn != cn) continue;

      if (new_cn == cn) {
        string new_contra = this->find(linea, ",", contra);

        if (new_contra != contra) continue;

        if (new_contra == contra) {
          // string asdf = this->mostrar_informacion(linea, ",");
          // cout << asdf[1] << endl;
        }
        
      }
    }

    this->archivo.close();

  }
  //Writing the data in the file 
  void registrar_usuario (Estudiante estudiante, Info informacion) {

    this->abrir("src/sedes/sede_"+informacion.sede+".csv");
    //Generating student code 
    srand(time(NULL));
    informacion.carnet.append(informacion.sede+"-");

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%y", now);

    informacion.carnet.append(buffer);
    informacion.carnet.append("-"+to_string(1000+rand() % (9999)));

    informacion.contra = this->generar_contra();

    this->archivo << informacion.carnet << ",";
    this->archivo << informacion.contra << ",";
    this->archivo << estudiante.nombre_completo << ",";
    this->archivo << estudiante.edad << ",";
    this->archivo << estudiante.e_civil << ",";
    this->archivo << estudiante.direccion << ",";
    this->archivo << estudiante.e_mail << ",";
    this->archivo << informacion.carrera << ",";
    this->archivo << informacion.seccion << ",";
    this->archivo << "cursos:,";
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
