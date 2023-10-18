#include "TAD.h"
#include <fstream>
#include <string.h>
#include <algorithm>
#include <list>

void Juego::llenarJugadores() {
  bool inicio = true;
}

Continentes Juego::llenarMultilista() {
Continentes mundo;
    ifstream myFile;
    myFile.open("world.txt");

    if(!myFile.is_open())
    {
        //cout << "no se pudo abrir" << endl;
    }
  
    list<string> myList;
    while(!myFile.eof())
    { 
      string line;
      getline(myFile, line);
      int size = line.size();
      char str[size];
      strcpy(str, line.c_str());

      myList.clear();
      char* token = strtok(str, "\t");
      int i = 1;
      
      while (token != NULL)
      {
        myList.push_back(token);
        token = strtok(NULL, "\t");
        i++;
      }
      mundo.push_back(myList);
    }

return mundo;
}

list<Territorio> Juego::llenarMundo(Continentes mundo) {
  list<Territorio> territorios;
  Continentes::iterator itMundo = mundo.begin();
  for( ; itMundo != mundo.end(); itMundo++)
    {
      Paises::iterator itPais = itMundo->begin();
      itPais++;
      for( ; itPais != itMundo->end(); itPais++)
        {
          //cout << "Pais: " << *itPais << endl;
          Territorio t = Territorio(*itPais, 0);
          territorios.push_back(t);
        }
  }  
  return territorios;
}

stack<Carta> Juego::llenarBarajaCartas() {
  ifstream myFile;
  myFile.open("world.txt");

  if(!myFile.is_open())
  {
      //cout << "no se pudo abrir" << endl;
  }
  vector<string> myVector;
  while(!myFile.eof())
  { 
    string line;
    getline(myFile, line);
    int size = line.size();
    char str[size];
    strcpy(str, line.c_str());

    char* token = strtok(str, "\t");
    
    while (token != NULL)
    {
      myVector.push_back(token);
      token = strtok(NULL, "\t");
    }
  }

  random_shuffle(myVector.begin(), myVector.end());
  
  vector<char> tipos = {'I', 'C', 'A'};
  char tipo;
  string territorio;

  vector<Carta> cartas;
  
  for(int i = 0; i < 42; i++)
    {
      tipo = tipos[i % tipos.size()];
      territorio = myVector[i];
      Carta carta = Carta(tipo, territorio);

      cartas.push_back(carta);
    }

  for(int k = 0; k < 12; k++)
    {
      Carta carta = Carta('M', "N/A");
      cartas.push_back(carta);
    }

  Carta carta = Carta('J', "N/A");
  cartas.push_back(carta);
  cartas.push_back(carta);

  random_shuffle(cartas.begin(), cartas.end());

  stack<Carta> baraja;
  for(Carta c : cartas)
    {
      baraja.push(c);
    }

  return baraja;
}

int Juego::calcularInfanteria(int cantidad){
  int totalEjercitos = 0;
  switch (cantidad) {
  case 3:
    totalEjercitos = 35;
    break;
  case 4:
    totalEjercitos = 30;
    break;
  case 5:
    totalEjercitos = 25;
    break;
  case 6:
    totalEjercitos = 20;
    break;
  }
  return totalEjercitos;
}

bool Juego::validarEnCurso(vector<Jugador> jugadores) {
  string ganador;
  vector<Jugador>::iterator it = jugadores.begin();
  for( ; it != jugadores.end(); it++)
  {
    if(it->getTerritorios().size() == 42)
    {
      ganador = it->getNombre();
      return true;
    }
  }
  return false;
}

void Juego::establecerTurnos(vector<Jugador> jugadores) {
  vector<Jugador>::iterator it = jugadores.begin();
  for( ; it != jugadores.end(); it++)
    {
      cout << "Turno de: " << it->getNombre() << endl;
    }
}

list<Territorio> Juego::llenarVecinos(list<Territorio> territorios)
{
  Continentes vecinos;
    ifstream myFile;
    myFile.open("neighbours.txt");

    if(!myFile.is_open())
    {
        cout << "no se pudo abrir" << endl;
    }

    list<string> myList;
    while(!myFile.eof())
    { 
      string line;
      getline(myFile, line);
      int size = line.size();
      char str[size];
      strcpy(str, line.c_str());

      myList.clear();
      char* token = strtok(str, "\t");
      int i = 1;

      while (token != NULL)
      {
        myList.push_back(token);
        token = strtok(NULL, "\t");
        i++;
      }
      vecinos.push_back(myList);
    }

  Continentes::iterator itVec = vecinos.begin();
  for( ; itVec != vecinos.end(); itVec++)
    {
      list<Territorio>::iterator itT = territorios.begin();
      for( ; itT != territorios.end(); itT++)
        {
          if(*(itVec)->begin() == itT->getNombre())
          {
            (*(itVec)).pop_back();
            itT->setVecinos(*(itVec));
            //cout << "\nMi name is: " << itT->getNombre() << endl;
            //cout << "\nmi lenght is: " << itT->getVecinos().size() << endl;
          }
        }
    }
  return territorios;
}
