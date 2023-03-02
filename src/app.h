void app () {  
  int opcion = 0;

  while (true) {
    cout << "+----------------------------------+" << endl;
    cout << "|          nombre del grupo        |" << endl;
    cout << "+----------------------------------+" << endl << endl;
    cout << "1. Ver mis datos (requiere carnet y contraceña)" << endl;
    cout << "2. Inscribirme" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione (1-3): "; cin >> opcion;

    if (opcion > 3 | opcion < 1) {
      cout << "!Numero fuera de rango!" << endl;
    }

    if (opcion == 1) {
      string cn, contra;
      cout << "Carnet: "; cin >> cn;
      cout << "Contraceña: "; cin >> contra;

      control.consultar_usuario (cn, contra);

    }

    if (opcion == 2) {
      Estudiante estudiante;

      cout << "+-----------------------------------+" << endl;
      cout << "|    Ingreso de datos personales    |" << endl;
      cout << "+-----------------------------------+" << endl << endl;
      // cin.ignore();
      cout << "Ingresa tu nombre completo: "; getline(cin, estudiante.nombre_completo);

      cout << "Ingresa tu edad: "; cin >> estudiante.edad;

      cin.ignore();
      cout << "Ingresa tu estado civil: "; getline(cin, estudiante.e_civil);
      cout << "Ingresa tu direccion: "; getline(cin, estudiante.direccion);
      cout << "Ingresa tu email: "; getline(cin, estudiante.e_mail);

      Info informacion;

      cout << "+-----------------------------------+" << endl;
      cout << "|    Ingreso de datos academicos    |" << endl;
      cout << "+-----------------------------------+" << endl << endl;
      cout << "Ingresa el codigo de tu sede: "; getline(cin, informacion.sede);
      cout << "Ingresa tu carrera: "; getline(cin, informacion.carrera);
      cout << "Ingresa tu seccion: "; cin >> informacion.seccion;
      cout << "Ingresa cantidad de cursos que tienes: "; cin >> informacion.c_cursos;
      cin.ignore();

      informacion.cursos = new string[informacion.c_cursos];

      for (int i = 0; i<informacion.c_cursos; i++) {
        cout << "[" << i << "] -> curso: "; getline(cin, *(informacion.cursos+i));
      }
      
      if (control.sede_registrada(informacion.sede)) {
        control.registrar_usuario(estudiante, informacion);
      } else {
        cout << "La sede, no existe!" << endl;
      }

    }

    if (opcion == 3) break;

    continue;
  }

}
