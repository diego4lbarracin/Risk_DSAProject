#include "TAD.h"
#include "implementacionArbolHuffman.h"
#include <bits/stdc++.h>
//#include <windows.h>

using namespace std;

// Proyecto RISK para Estructuras de Datos 2023-3
// Autores
// Giseth Villalobos
// Carlos D'Silvestri
// Diego Albarracin
// Vesion: Entregable 0

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

// Variables Globales para almacenar los 3 resultados de lanzar los
// dados del atacante y el resultado de la suma de los dados del defensor
void comprimirArhivoCodigoHuffman(string nombreArchivo);
void descomprimirArchivoHuffman(string nombreArchivo);

vector<int> resultsDadoAtacante;
int resultDadosDefensor;
list<Jugador>::iterator itJugador;
unordered_map<std::string, Territorio *> mapaTerritorios;
/*
 *
 *
 *
 *
 */

// Parte indispensable para iniciar el juego
// Crear una partida
Juego juego;
/*= {
        Jugador{"Jugador 1", "rojo", 10},
        Jugador{"Jugador 2", "azul", 10},

    };
    */
Territorio territorio = Territorio("madagascar", 0);

vector<Carta> cartas = {Carta('C', "Madagascar"), Carta('S', "San Diego")};

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
        for (it = jugadores.begin(); it != jugadores.end(); ++it) {
          menu();
          std::cout << "Turno " << turno << " - Jugador: " << it->getNombre()
                    << std::endl;

          cout << "$ ";
          cin >> userInput;

          optionVerifier = userInput;
          // Switch-case con las opciones del juego.
          switch (userInput) {
          case 1:
            ayuda();
            break;
          case 3:
            if (mostrar_unidades()) {
              cout << endl;
              cout << "Comando ejecutado con exito" << endl;
              cout << endl;
            } else {
              cout << endl;
              cout << "Comando no ejecutado con exito" << endl;
              cout << endl;
            }
            break;
          case 4:
            if (mostrar_sitios()) {
              cout << endl;
              cout << "Comando ejecutado con exito" << endl;
              cout << endl;
            } else {
              cout << endl;
              cout << "Comando no ejecutado con exito" << endl;
              cout << endl;
            }

            break;
          case 5:
            if (it->ocuparTerritorio(&territorio)) {
              cout << endl;
              cout << "Comando ejecutado con exito" << endl;
              cout << endl;
            } else {
              cout << endl;
              cout << "Comando no ejecutado con exito" << endl;
              cout << endl;
            }

            break;
          case 6:
            if (it->atacarTerritorioVecino()) {

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
            if (it->obtenerNuevasUnidades()) {
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
            if (it->tomarCarta(&cartas[0])) {
              cout << endl;
              cout << "Comando ejecutado con exito" << endl;
              cout << endl;
            } else {
              cout << endl;
              cout << "Comando no ejecutado con exito" << endl;
              cout << endl;
            }

            break;
          case 9:
            if (guardar()) {
              cout << endl;
              cout << "comando ejecutado con exito" << endl;
              cout << endl;
            } else {
              cout << endl;
              cout << "comando no ejecutado con exito" << endl;
              cout << endl;
            }

            break;
          case 0:
            cout << "saliendo..." << endl;
            break;
          default:
            if (optionVerifier <= 0 || optionVerifier > 9) {
              cout << endl;
              cout << "Ingrese una opcion correcta" << endl;
              cout << endl;
            }

            break;
          }

          // Aquí iría la lógica del juego para el jugador actual

          // Simulamos incrementar la puntuación del jugador
          jugadores[jugadorActual].agregarPuntuacion(10);

          // Cambio al siguiente jugador
          jugadorActual = (jugadorActual + 1) % jugadores.size();
        }
      }
    }
    // Condicion para que el menu se repita mientras el usuario no haya
    // presionado la opcion salir.
  } while (userInput != 0);
  system("Color 07");
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
    } 
    
    
    else if (userOption == "calcular_ruta") {
      std::string origen, destino;
      std::cout << "Ingresa el nombre del territorio de origen: ";
      std::cin >> origen;
      std::cout << "Ingresa el nombre del territorio de destino: ";
      std::cin >> destino;

      Territorio *territorioOrigen = mapaTerritorios[origen];
      Territorio *territorioDestino = mapaTerritorios[destino];

      if (territorioOrigen && territorioDestino) {
        std::vector<Territorio *> ruta =
            territorioOrigen->calcularRuta(territorioDestino);
        std::cout << "Ruta: ";
        for (auto &territorio : ruta) {
          std::cout << territorio->getNombre() << " -> ";
        }
        std::cout << "\n";
      } else {
        std::cout << "Territorios no encontrados.\n";
      }
    } 
    
    
    else if (userOption == "guardar") {
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
  int ejercitosJugador = 10;

  int cantidad;
  if (!inicializer) {
    cout << "cuantos jugadores van a jugar? " << endl;
    cin >> cantidad;
    if (cantidad < 3) {
      cout << "la cantidad tiene que ser mayor a 3, vuela a inicializar el "
              "juego por favor"
           << endl;
      return false;
    } else {
      juego.calcularInfanteria(&jugadores);
    }

    for (int i = 0; i < cantidad; i++) {
      cout << "digite el nombre del jugador: ";
      cin >> nombreJugador;
      cout << endl;
      cout << "el color que desea utilizar: ";
      cin >> colorJugador;
      cout << endl;

      jugadores.push_back(
          Jugador(nombreJugador, colorJugador, ejercitosJugador));

      cout << "jugador agregado" << endl;
      cout << endl;
      jugadores[i].setTerritorio(&territorio);
      jugadores[i].colocarEjercitos(jugadores[i]);
    }
    return true;
  } else {
    return false;
  }
  return false;
}

bool mostrar_unidades() {
  // Funcion para mostrar a las unidades.
  cout << endl;
  cout << "Comando para mostrar unidades" << endl;
  cout << endl;
  return true;
}
bool mostrar_sitios() {
  // Funcion para mostrar sitios.
  cout << endl;
  cout << "Comando para mostrar sitios" << endl;
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