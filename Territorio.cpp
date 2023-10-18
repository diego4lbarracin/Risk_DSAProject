#include "TAD.h"

void Territorio::recopilarVecinos(Continentes vecinos) {

  Continentes::iterator it = vecinos.begin();
  for( ; it != vecinos.end(); it++)
  {
    if(*it->begin() == this->getNombre())
    {
      this->setVecinos(*it);
    }
  }
}

void Territorio::mostrarVecinos() const {
  cout << "Territorio: " << nombre << endl;
  cout << "Vecinos: ";
  for (auto vecino : vecinos) {
    cout << vecino << " ";
  }
  cout << endl;
}

void Territorio::setVecinos(list<string> vecinosN) {
  this->vecinos = vecinosN;
}

list<string> Territorio::getVecinos()
{
  return this->vecinos;
}

string Territorio::getNombre() { return this->nombre; }

int Territorio::getEjercitos() { return this->ejercitos; }

void Territorio::agregarEjercitos(int cantidad)
{
  this->ejercitos += cantidad;
}