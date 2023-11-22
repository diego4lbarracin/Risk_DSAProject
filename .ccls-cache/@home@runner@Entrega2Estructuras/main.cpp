/*
 * Proyecto RISK para Estructuras de Datos 2023-3
 * Autores:
 *   Giseth Villalobos
 *   Carlos D'Silvestri
 *   Diego Albarracin
 * Version: Entregable 2
 *
 */

#include "TAD.h"
#include "implementacionArbolHuffman.h"
#include <bits/stdc++.h>
//#include <windows.h>

using namespace std;

/* FIRMA DE LAS FUNCIONES */
// void imprimirLogoInicio();
void menu();
void ayuda();
bool inicializar(bool inicializer);
Territorio reclamarTerritorios();
bool ponerEjercitosAdicionales();
bool mostrar_unidades();
bool mostrar_sitios();
bool reclutar();
bool guardar(string nombreArchivoTexto);
void lanzarDados(string turno);
int imprimirDados(int caso);
void condicionesVictoria(vector<int> resultsDadoAtacante,
                         int resultDadoDefensor);
/* VARIABLES GLOBALES */
// Variables Globales para almacenar los 3 resultados de lanzar los
// dados del atacante y el resultado de la suma de los dados del defensor
void comprimirArhivoCodigoHuffman(string nombreArchivo);
void descomprimirArchivoHuffman(string nombreArchivo);

vector<int> resultsDadoAtacante;
int resultDadosDefensor;
list<Jugador>::iterator itJugador;
/*
 *
 *
 *
 *
 */

// Parte indispensable para iniciar el juego
// Crear una partida
Juego juego;
// Llenar la multi-lista con los paises y sus vecinos
Continentes mapa = juego.llenarMultilista();
list<Territorio> mundoSinVecinos = juego.llenarMundo(mapa);
list<Territorio> mundo = juego.llenarVecinos(mundoSinVecinos);
// Crear la lista de jugadores
list<Jugador> jugadores;
// Barajar las cartas
stack<Carta> mazo = juego.llenarBarajaCartas();

int main() {
  // int userInput: Variable para almacenar la entrada del usuario en el
  // menú de inicio del juego.
  int userInput;
  // bool inicializer: Variable usada para almacenar el retorna de la función
  // 'inicializer()' la cual se usura para determinar si el usuario quiere
  // iniciar el juego o no.
  bool inicializer = false;
  // int optionVerifier: Variable usada para almacenar la opcion seleccionada
  // por el usuario en el menu al que se ingresa si el usuario decide
  // inicializar el juego.
  int optionVerifier = 0;
  // verifica el turno del jugador actual
  int jugadorActual = 0;
  // turnos totales que se pueden hacer
  int totalTurnos = 10;
  do {

    if (inicializer == false) {
      // imprimirLogoInicio();
      cout << "RISK el juego para dominar el mundo :)" << endl;
      cout << endl;
      cout << "* Si deseas saber los comandos escribe 1 para recibir ayuda *"
           << endl;
      cout << endl;
      cout << "* Selecciona 2 para empezar a jugar" << endl;
      cout << "* Si deseas salir del juego escribe 0 para salir *";
      cout << endl;
      // Switch-case que recibe la opcion en userInput e inicializa
      // el caso correspondiente.
      cout << "$ ";
      cin >> userInput;
      switch (userInput) {
      case 1:
        // Llamado a la funcion 'ayuda()' la cual contiene
        // la descripcion de los comandos.
        ayuda();
        break;
      case 2:
        // Inicializacion del juego, al cambiar el valor de 'false' a 'true'
        // el programa entra el menu principal.
        inicializer = inicializar(inicializer);
        /*
        este código es para recorrer lo que retorna la funcion de
        llenarVecinos()
        */
        cout << inicializer;
        cout << endl;
        break;
      case 0:
        break;
      default:
        cout << endl;
        cout << "Ingrese una opcion correcta." << endl;
        cout << endl;
        break;
      }
    }

    if (inicializer == true) {

      for (int turno = 1; turno <= totalTurnos; ++turno) {
        for (itJugador = jugadores.begin(); itJugador != jugadores.end();
             ++itJugador) {
          menu();
          std::cout << "Turno " << turno
                    << " - Jugador: " << itJugador->getNombre() << std::endl;

          cout << "$ ";
          cin >> userInput;

          optionVerifier = userInput;
          // Switch-case con las opciones del juego.

          Territorio terrenoSel("", 0);
          Carta cartaNueva('0', "");
          string nombreArch;

          switch (userInput) {
          case 0:
            cout << "saliendo..." << endl;
            exit(0);
            break;
          case 1:
            ayuda();
            break;
          case 3:
            if (mostrar_unidades()) {
              cout << endl;
              cout << "Comando ejecutado con éxito" << endl;
              cout << endl;
            } else {
              cout << endl;
              cout << "Comando no ejecutado con éxito" << endl;
              cout << endl;
            }
            break;
          case 4:
            if (mostrar_sitios()) {
              cout << endl;
              cout << "Comando ejecutado con éxito" << endl;
              cout << endl;
            } else {
              cout << endl;
              cout << "Comando no ejecutado con éxito" << endl;
              cout << endl;
            }
            break;
          case 5:
            terrenoSel = reclamarTerritorios();
            cartaNueva = mazo.top();
            itJugador->tomarCarta(cartaNueva);
            if (itJugador->ocuparTerritorio(terrenoSel)) {
              cout << endl;
              cout << "Comando ejecutado con éxito" << endl;
              ponerEjercitosAdicionales();
              cout << endl;
            } else {
              cout << endl;
              cout << "Comando no ejecutado con éxito" << endl;
              cout << endl;
            }
            break;
            /*case 6:
              if (itJugador->atacarTerritorioVecino()) {

                cout << endl;
                cout << "Comando ejecutado con exito" << endl;
                cout << endl;
              } else {
                cout << endl;
                cout << "Comando no ejecutado con exito" << endl;
                cout << endl;
              }

              break;
            case 7:
              if (itJugador->obtenerNuevasUnidades()) {
                cout << endl;
                cout << "Comando ejecutado con exito" << endl;
                cout << endl;
              } else {
                cout << endl;
                cout << "Comando no ejecutado con exito" << endl;
                cout << endl;
              }

              break;
            case 8:
              if (itJugador->tomarCarta(mazo.top())) {
                cout << endl;
                cout << "Comando ejecutado con exito" << endl;
                cout << endl;
              } else {
                cout << endl;
                cout << "Comando no ejecutado con exito" << endl;
                cout << endl;
              }

              break;*/
          case 9:

            cout << "Ingrese el nombre del archivo de texto" << endl;
            cin >> nombreArch;
            if (guardar(nombreArch)) {
              cout << endl;
              cout << "Comando ejecutado con éxito" << endl;
              cout << endl;
            } else {
              cout << endl;
              cout << "Comando no ejecutado con éxito" << endl;
              cout << endl;
            }
            break;

          default:
            if (optionVerifier <= 0 || optionVerifier > 9) {
              cout << endl;
              cout << "Ingrese una opción correcta" << endl;
              cout << endl;
            }
            break;
          }

          // Aquí iría la lógica del juego para el jugador actual

          // Simulamos incrementar la puntuación del jugador
          // jugadores[jugadorActual].agregarPuntuacion(10);

          // Cambio al siguiente jugador
          jugadorActual = (jugadorActual + 1) % jugadores.size();
        }
      }
    }
    // Condicion para que el menu se repita mientras el usuario no haya
    // presionado la opcion salir.
  } while (userInput != 0);
  // system("Color 07");
  return 0;
}

void menu() {
  cout << endl;
  cout << "3. _-_ Mostrar Unidades _-_" << endl;
  cout << endl;
  cout << "4. _-_ Mostrar Sitios _-_" << endl;
  cout << endl;
  cout << "5. _-_ Ocupar Territorio _-_" << endl;
  cout << endl;
  cout << "6. _-_ Atacar Territorio Vecino _-_" << endl;
  cout << endl;
  cout << "7. _-_ Obtener Nuevas Unidades _-_" << endl;
  cout << endl;
  cout << "8. _-_ Tomar una carta _-_" << endl;
  cout << endl;
  cout << "9. _-_ guardar _-_" << endl;
  cout << endl;
  cout << "0. _-_ salir _-_" << endl;
  cout << endl;
}

void ayuda() {
  // La funcion 'ayuda()' imprime en pantalla una descripcion
  //  del funcionamiento de cada uno de los comandos mientras el
  // usuario no presione la opcion salir dentro del menu de 'ayuda()'.
  string userOption;
  string userDesition;
  cout << endl;
  cout << "Ha accedio al menu de ayuda, los comandos disponibles son los "
          "siguienes: "
       << endl;

  do {

    cout << endl;
    cout << "2. _-_ inicializar _-_" << endl;
    cout << endl;
    cout << " ** comandos que se activan una vez inicialzado el juego: "
         << endl;
    cout << "3. _-_ Mostrar Unidades _-_" << endl;
    cout << endl;
    cout << "4. _-_ Mostrar Sitios _-_" << endl;
    cout << endl;
    cout << "5. _-_ Ocupar Territorio _-_" << endl;
    cout << endl;
    cout << "6. _-_ Atacar Territorio Vecino _-_" << endl;
    cout << endl;
    cout << "7. _-_ Obtener Nuevas Unidades _-_" << endl;
    cout << endl;
    cout << "8. _-_ Tomar una carta _-_" << endl;
    cout << endl;
    cout << "9. _-_ guardar _-_" << endl;
    cout << endl;
    cout << "0. _-_ salir _-_" << endl;
    cout << endl;
    cout << endl;
    cout << "Si desea saber el funcionamiento de un comando en especifico solo "
            "escribe el comando para poder decirte como funciona, de lo "
            "contrario escribe salir: "
         << endl;
    cout << "$";
    cin >> userOption;

    if (userOption == "iniicalizar") {
      cout << endl;
      cout << "inicializar -----> Este comando sirve para poder iniciar el "
              "juego."
           << endl;
    } else if (userOption == "Mostrar Unidades") {
      cout << endl;
      cout << "Mostrar Unidades -----> Este comando sirve para mostrar las "
              "unidades de tus oponentes y las tuyas."
           << endl;
    } else if (userOption == "Mostrar Sitios") {
      cout << endl;
      cout << "Mostrar Sitios -----> este comando sirve para poder mostrar los "
              "sitios en general para poder ver el terreno que te falta por "
              "conquistar o que ya conquistaste"
           << endl;
    } else if (userOption == "Ocupar Territorio") {
      cout << endl;
      cout << "Ocupar Territorio -----> Este comando sirve para poder mover "
              "tus tropas en tus territorios"
           << endl;
    } else if (userOption == "Atacar Territorio Vecino") {
      cout << endl;
      cout << "Atacar Territorio Vecino -----> Este comando sirve para poder "
              "atacar los terriorios que todavia no has conquistado"
           << endl;
    } else if (userOption == "Obtener Nuevas Unidades") {
      cout << endl;
      cout << "Obtener Nuevas Unidades -----> este comando sirve para poder "
              "agregar mas tropas a tus territorios y asi poder atacar o "
              "defender"
           << endl;
    } else if (userOption == "pasar_turno") {
      cout << endl;
      cout << "Tomar una carta -----> Este comando sirve para poder pasar el "
              "turno de la ronda para que los demas jugadores puedan jugar"
           << endl;
    } else if (userOption == "guardar") {
      cout << endl;
      cout << "guardar -----> Este comando sirve para poder guardar la partida "
              "y tu progreso"
           << endl;
    } else if (userOption == "salir") {
      cout << endl;
      cout << "salir -----> este comando sirve para poder salir del juego (si "
              "no guardas antes, perderas todo tu progreso)"
           << endl;
      cout << "si deseas salir de ayuda escribe 'si', de lo contrario, escribe "
              "'no': "
           << endl;
      cout << endl;
      cout << "---------Escribe 'si' o 'no'---------" << endl;
      cout << endl;
      cout << "$";
      cin >> userDesition;

      if (userDesition == "si") {
        userOption = "salir";
      } else if (userDesition == "no") {
        userOption = "salir1";
      } else {
        cout << endl;
        cout << "Saliendo..." << endl;
        cout << endl;
      }

    } else {
      cout << endl;
      cout << "Opcion no encontrada" << endl;
      cout << endl;
    }
    cout << endl;
  } while (userOption != "salir");
}

// bool reclutar();
// bool pasar_turno();

bool inicializar(bool inicializer) {
  // Funcion Inicializar. Es la función que permite el funcionamiento
  // de los menus. Retorna true si el el usuario presiona la opcion
  // en donde se hace el llamado a la funcion.

  string nombreJugador;
  string colorJugador;

  int cantJugadores;
  int ejercitosPorJugador;
  if (!inicializer) {
    cout << "cuantos jugadores van a jugar? " << endl;
    cin >> cantJugadores;
    if (cantJugadores < 3) {
      cout << "la cantidad tiene que ser mayor a 3, vuela a inicializar el "
              "juego por favor"
           << endl;
      return false;
    } else {
      switch (cantJugadores) {
      case 3:
        ejercitosPorJugador = 35;
        break;
      case 4:
        ejercitosPorJugador = 30;
        break;
      case 5:
        ejercitosPorJugador = 25;
        break;
      case 6:
        ejercitosPorJugador = 20;
        break;
      }
    }

    for (int i = 0; i < cantJugadores; i++) {
      cout << "digite el nombre del jugador: ";
      cin >> nombreJugador;
      cout << endl;
      cout << "el color que desea utilizar: ";
      cin >> colorJugador;
      cout << endl;

      jugadores.push_back(
          Jugador(nombreJugador, colorJugador, ejercitosPorJugador));

      cout << "jugador agregado" << endl;
      cout << endl;
    }
    return true;
  } else {
    return false;
  }
  return false;
}

Territorio reclamarTerritorios() {
  string terrSelec;
  int counter = 0;
  cout << endl;
  while (counter < 42) {
    cout << "¿Qué territorio desea conquistar como punto de partida?" << endl;
    cin >> terrSelec;
    // Se busca el territorio escogido
    // Se añade a su lista de territorios
    // Se elimina de la lista de territorios global
    list<Territorio>::iterator itM = mundo.begin();
    for (; itM != mundo.end(); itM++) {
      if (terrSelec == itM->getNombre()) {
        mundo.erase(itM);
        return *itM;
      }
    }
    counter++;
  }
}

bool ponerEjercitosAdicionales() {
  int counter = 0;
  string terrSelec;
  while (counter < jugadores.size()) {
    for (; itJugador != jugadores.end(); itJugador++) {
      cout << "Jugador " << itJugador->getNombre()
           << ". ¿A qué territorio desea adicionarle un ejército?" << endl;
      cin >> terrSelec;
      list<Territorio>::iterator itM = itJugador->getTerritorios().begin();
      for (; itM != itJugador->getTerritorios().end(); itM++) {
        if (terrSelec == itM->getNombre()) {
          itJugador->agregarEjercitos(*itM);
        }
      }
      if (itJugador->getEjercitos() == 0) {
        counter++;
      }
    }
  }
  return true;
}

bool mostrar_unidades() {
  // Funcion para mostrar a las unidades.
  cout << endl;
  cout << "Comando para mostrar unidades" << endl;
  for (; itJugador != jugadores.end(); itJugador++) {
    cout << "Jugador: " << itJugador->getNombre() << endl;
    cout << "Cantidad de tropas: " << itJugador->getEjercitos() << endl;
  }
  cout << endl;
  return true;
}
bool mostrar_sitios() {
  // Funcion para mostrar sitios.
  cout << endl;
  cout << "Comando para mostrar sitios" << endl;
  for (; itJugador != jugadores.end(); itJugador++) {
    cout << "Jugador: " << itJugador->getNombre() << endl;
    cout << "Territorios" << endl;
    list<Territorio>::iterator itT = itJugador->getTerritorios().begin();
    for (; itT != itJugador->getTerritorios().end(); itT++) {
      cout << itT->getNombre() << endl;
    }
  }
  cout << endl;
  return true;
}

bool reclutar() {
  // La funcion reclutar permite reclutar a soldados para la tropa.
  cout << endl;
  cout << "Comando para reclutar unidades" << endl;

  cout << endl;
  return true;
}

/*
bool mover() {
  //La funcion mover permite al jugador en turno mover
  //a sus soldados.
    cout << endl;
    cout << "Comando para mover unidades" << endl;
    cout << endl;
    return true;
}
*/
/*
bool atacar() {
  //La funcion atacar permite al jugador en truno
  //atacar a sus oponentes.
    cout << endl;
    cout << "Comando para atacar oponentes" << endl;
    cout << endl;
    return true;
}
*/

/*
bool pasar_turno(){
  //La funcion pasar turno permite pasar el turno al siguiente jugador.
    cout << endl;
    cout << "Comando para pasar turno" << endl;
    cout << endl;
    return true;
}
*/
bool guardar(string nombreArchivoTexto) {
  // La funcion guardar se encarga de permitir guardar una partida.
  cout << endl;
  cout << "Comando para guardar la partida, se ejecuto con exito" << endl;
  // Crear y escribir en el archivo
  fstream archivo;
  archivo.open(nombreArchivoTexto.c_str(), ios::out);
  if (archivo.is_open()) {
    archivo << "Cantidad de Jugadores: " << jugadores.size() << "\n\n";
    for (; itJugador != jugadores.end(); itJugador++) {
      archivo << "Nombre: " << itJugador->getNombre() << "\n";
      archivo << "Color: " << itJugador->getColor() << "\n";
      archivo << "Cantidad de territorios que ocupa: "
              << itJugador->getTerritorios().size() << "\n";
      list<Territorio>::iterator itTerritorio =
          itJugador->getTerritorios().begin();
      for (; itTerritorio != itJugador->getTerritorios().end();
           itTerritorio++) {
        archivo << "Territorio: " << itTerritorio->getNombre()
                << " - CantEjercitos: " << itTerritorio->getEjercitos() << "\n";
      }
      archivo << "Cantidad de cartas que posee: "
              << itJugador->getCartas().size() << "\n";
      list<Carta>::iterator itCarta = itJugador->getCartas().begin();
      for (; itCarta != itJugador->getCartas().end(); itCarta++) {
        archivo << "Carta: " << itCarta->getTipo() << "\n";
      }
      archivo << "\n";
    }
    archivo.close();
    cout << "Archivo generado exitosamente: " << endl;
  } else {
    cerr << "No se pudo abrir el archivo para escritura." << endl;
  }
  cout << endl;
  string nombreArchivo;
  cout << "Ingrese el nombre del archivo a comprimir" << endl;
  cin >> nombreArchivo;
  comprimirArhivoCodigoHuffman(nombreArchivo);
  cout << "Ingrese el nombre del archivo a descomprimir" << endl;
  cin >> nombreArchivo;
  descomprimirArchivoHuffman(nombreArchivo);

  
  return true;

}

/*
void imprimirLogoInicio(){
    //system("Color 04") es para cambiar de color el texto de blanco a rojo.
    system("Color 03");
    //Indentacion para la impresión del logo del juego "RISK".
    cout<<setfill(' ')<<left<<setw(4)<<" "<<setw(20)<<" "<<setw(20)<<"
"<<setw(20)<<"         "<<setw(20)<<"       "<<endl;

    cout<<setfill('-')<<setw(80)<<'-'<<endl;
    cout<<setfill(' ')<<setw(32)<<" "<<"BIENVENIDO A: "<<endl;
    cout<<setfill('-')<<setw(80)<<'-'<<endl;
    cout<<setfill(' ')<<setw(18)<<"
"<<setw(14)<<"********"<<setw(6)<<"**"<<setw(14)<<"********"<<setw(7)<<"**"<<"*"<<endl;
    cout<<setfill(' ')<<setw(18)<<"
"<<setw(7)<<"**"<<setw(7)<<"*"<<setw(6)<<"**"<<setw(14)<<"**"<<setw(6)<<"**"<<"*"<<endl;
    cout<<setfill(' ')<<setw(18)<<"
"<<setw(7)<<"**"<<setw(7)<<"*"<<setw(6)<<"**"<<setw(14)<<"**"<<setw(5)<<"**"<<"*"<<endl;
    cout<<setfill(' ')<<setw(18)<<"
"<<setw(6)<<"**"<<setw(8)<<"*"<<setw(6)<<"**"<<setw(14)<<"**"<<setw(4)<<"**"<<"*"<<endl;
    cout<<setfill(' ')<<setw(18)<<"
"<<setw(5)<<"**"<<setw(9)<<"*"<<setw(6)<<"**"<<setw(14)<<"**"<<setw(3)<<"**"<<"*"<<endl;
    cout<<setfill(' ')<<setw(18)<<"
"<<setw(4)<<"**"<<setw(10)<<"*"<<setw(6)<<"**"<<setw(14)<<"********"<<setw(14)<<"***"<<endl;
    cout<<setfill(' ')<<setw(18)<<"
"<<setw(3)<<"**"<<setw(11)<<"*"<<setw(6)<<"**"<<setw(6)<<"
"<<setw(8)<<"**"<<setw(3)<<"**"<<"*"<<endl; cout<<setfill(' ')<<setw(18)<<"
"<<setw(14)<<"***"<<setw(6)<<"**"<<setw(6)<<"
"<<setw(8)<<"**"<<setw(4)<<"**"<<"*"<<endl; cout<<setfill(' ')<<setw(18)<<"
"<<setw(3)<<"**"<<setw(11)<<"*"<<setw(6)<<"**"<<setw(6)<<"
"<<setw(8)<<"**"<<setw(5)<<"**"<<"*"<<endl; cout<<setfill(' ')<<setw(18)<<"
"<<setw(4)<<"**"<<setw(10)<<"*"<<setw(6)<<"**"<<setw(6)<<"
"<<setw(8)<<"**"<<setw(6)<<"**"<<"*"<<endl; cout<<setfill(' ')<<setw(18)<<"
"<<setw(6)<<"**"<<setw(8)<<"**"<<setw(6)<<"**"<<setw(14)<<"********"<<setw(7)<<"**"<<"*"<<endl;

    cout<<setfill('-')<<setw(80)<<'-'<<endl;
    cout<<setfill('-')<<setw(80)<<'-'<<endl;
}
*/

void condicionesVictoria(vector<int> resultsDadoAtacante,
                         int resultDadoDefensor) {
  // Funcion para determinar las condiciones de victoria.
  // Se recibe como parametro un vector<int> resultsDadoAtacante con los tres
  // resultados del atacante y una variable int resultDadoDefensor. Con la
  // variables anteriores se podrá determinar el ganador y el perdedor.
  cout << "Los resultados de 3 dados lanzados por el atacante: " << endl;
  int dado1, dado2;
  for (int i : resultsDadoAtacante) {
    cout << "Dado: " << i << endl; // Imprmiendo los resultados de los dados
                                   // lanzados por el atacante.
  }
  cout << "Elija 2 dados para la comparacion: "
       << endl; // Solicitando que elija solo 2 de los 3 resultados.
  cout << "Dado 1: ";
  cin >> dado1;
  cout << "Dado 2: ";
  cin >> dado2;

  // WHILE loop para evitar que el programa continue si el usuario no elije un
  // valor correcto. Se hace uso de la funcion .find() para determinar si el
  // valor ingresado existe o no dentro de los vectores.
  while (find(resultsDadoAtacante.begin(), resultsDadoAtacante.end(), dado1) ==
             resultsDadoAtacante.end() ||
         find(resultsDadoAtacante.begin(), resultsDadoAtacante.end(), dado2) ==
             resultsDadoAtacante.end()) {
    cout << "El valor de los dados ingresados no existe" << endl;
    cout << "Ingrese nuevamente los valores: " << endl;
    cout << "Dado 1: ";
    cin >> dado1;
    cout << "Dado 2: ";
    cin >> dado2;
  }

  // Condicionales para determinar el ganador y que hacer. Al implementador de
  // estas funciones se le recomienda editarlas si es necesario de acuerdo a su
  // logica o lo que tenga planeado.
  if ((dado1 + dado2) > resultDadoDefensor) {
    cout << "ATACANTE: " << (dado1 + dado2) << endl;
    cout << "DEFENSOR: " << (resultDadoDefensor) << endl;
    cout << "El defensor ha perdido una unidad de ejercito en su territorio el "
            "cual esta siendo atacado"
         << endl;
  } else if ((dado1 + dado2) < resultDadoDefensor) {
    cout << "ATACANTE: " << (dado1 + dado2) << endl;
    cout << "DEFENSOR: " << (resultDadoDefensor) << endl;
    cout << "El atacante ha perdido una unidad de ejercito en su territorio "
            "desde donde esta atacando"
         << endl;
  } else {
    cout << "ATACANTE: " << (dado1 + dado2) << endl;
    cout << "DEFENSOR: " << (resultDadoDefensor) << endl;
    cout << "Hay un empate!" << endl;
    cout << "El defensor ha ganado y el atacante pierde una unidad de ejercito "
            "desde el territorio donde ataca"
         << endl;
  }
}

void comprimirArhivoCodigoHuffman(string nombreArchivo) {
  string data1;
  ifstream file(nombreArchivo); // replace "input.txt" with your file name
  if (file.is_open()) {
    getline(file, data1);
    file.close();
  }
  construrirArbol(data1);
}

void descomprimirArchivoHuffman(string nombreArchivo) {
  string data1;
  ifstream file(nombreArchivo); // replace "input.txt" with your file name
  if (file.is_open()) {
    getline(file, data1);
    file.close();
  }
  descomprimir(data1);
}