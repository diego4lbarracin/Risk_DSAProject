#include "TAD.h"
#include <bits/stdc++.h>

using namespace std;

void llenarJaja()
{
Juego juego = Juego();
// Llenar la multi-lista con la información de los países y su organización en continentes
Continentes mundo = juego.llenarMundo();
// Crear la lista de jugadores
list<Jugador> jugadores;
// Llenar la multi-lista con la información de los países y sus respectivos vecinos
// Crear la lista de territorios totales y llenarla
list<Territorio> territorios;

Continentes::iterator itMundo = mundo.begin();
for( ; itMundo != mundo.end(); itMundo++)
    {
      Paises::iterator itPais = itMundo->begin();
      itPais++;
      for( ; itPais != itMundo->end(); itPais++)
        {
          cout << "ja: " << *itPais << endl;
          Territorio t = Territorio(*itPais, 0);
          territorios.push_back(t);
        }

    }

// Barajar las cartas
stack<Carta> mazo = juego.llenarBarajaCartas();

}

int main()
{
  llenarJaja();
  return 0;
}
