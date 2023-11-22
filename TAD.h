#ifndef TAD_H
#define TAD_H

#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef list<string> Paises;
typedef list<Paises> Continentes;

struct Ejercito{
  char tipo;
  string colorEj;
};

// Clase Territorio y Carta
class Territorio {
public:
  Territorio(const string &nombre);

  // Getters
  string getNombre();
  list<Ejercito> getEjercitos();
  list<string> getVecinos();

  // Setters

  void setNombre(string nombre);

  void setEjercitos(Ejercito ejercitoNuevo);

  void recopilarVecinos(list<list<string>> vecinos);

  void setVecinos(list<string> vecinos);

  void mostrarVecinos() const;

  void agregarEjercitos(Ejercito tropa);

  vector<Territorio> calcularRuta(Territorio destino);

private:
  string nombre;
  list<Ejercito> ejercitos;
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
  Jugador(const string &nombre, const string &colorJ, int cantEjercitos);

  // Getters
  string getNombre() const;
  string getColor() const;
  int getCantEjercitos() const;
  list<Territorio> getTerritorios() const;
  list<Carta> getCartas() const;

  //Setters
  void setNombre(string nombre);
  void setColor(string color);

  // Modifiers
  bool ocuparTerritorio(Territorio territorio);
  void agregarEjercitos(Territorio territorio, Ejercito tropaNueva);
  void tomarCarta(Carta carta);
  bool obtenerNuevasUnidades(Continentes mapa);
  bool atacarTerritorioVecino();
  void agregarPuntuacion(int puntuacion);
  void colocarEjercitos(Jugador &jugador);
  void setTerritorio(Territorio territorio);
  void lanzarDados(string turno);

private:
  string nombreJugador;
  string color;
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

  vector<Carta> llenarBarajaCartas();

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

class EstrategiaDeJuego {
  public:
  vector<Territorio> calcularConquista(Territorio origen, Territorio destino);
  

  private:


};

// Implementa más métodos según sea necesario
#endif
