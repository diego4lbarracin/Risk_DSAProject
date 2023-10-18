#ifndef TAD_H
#define TAD_H

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <list>
using namespace std;

typedef list<string> Paises;
typedef list<Paises> Continentes;

// Clase Territorio y Carta
class Territorio {
public:
  Territorio(const string &nombre, int ejercitos)
      : nombre(nombre), ejercitos(ejercitos) {}

  //Getters
  string getNombre();
  int getEjercitos();
  list<string> getVecinos();

  //Setters
  void recopilarVecinos(list<list<string>> vecinos);

  void setVecinos(list<string> vecinos);

  void mostrarVecinos() const;

  void agregarEjercitos(int cantidad);

private:
  string nombre;
  int ejercitos;
  list<string> vecinos;
};

class Carta {
public:
  Carta(char tipo, const string &territorio)
      : tipo(tipo), territorio(territorio) {}

  void mostrarContenido() const;

  char getTipo();

  string getTerritorio();

private:
  char tipo;
  string territorio;
};
class Jugador {
public:
  Jugador(const string &nombre, const string &color, int ejercitos);

//Getters
  string getNombre() const;
  string getColor() const;
  int getEjercitos() const;
  list<Territorio> getTerritorios() const;
  list<Carta> getCartas() const;

//Modifiers
  bool ocuparTerritorio(Territorio territorio);
  void agregarEjercitos(Territorio territorio);
  bool tomarCarta(Carta carta);
  bool obtenerNuevasUnidades(Continentes mapa);
  bool atacarTerritorioVecino();
  void agregarPuntuacion(int puntuacion);
  void colocarEjercitos(Jugador &jugador);
  void setTerritorio(Territorio territorio);
  void lanzarDados(string turno);

private:
  string nombreJugador;
  string colorJugador;
  int ejercitosJugador;
  int puntuacion;
  list<Territorio> territorios;
  list<Carta> cartas;
};



class Juego {
public:

  void llenarJugadores();

  Continentes llenarMultilista();

  list<Territorio> llenarMundo(Continentes mundo);

  stack<Carta> llenarBarajaCartas();

  int calcularInfanteria(int cantidad);

  bool validarEnCurso(vector<Jugador> jugadores);

  void establecerTurnos(vector<Jugador> jugadores);

  list<Territorio> llenarVecinos(list<Territorio> territorios);

private:
  vector<Jugador> jugadores;
  Continentes mundo;
  stack<Carta> cartas;
  int intercambios;
};

// Implementa más métodos según sea necesario
#endif
