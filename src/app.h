
void app () {  
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
  
}
