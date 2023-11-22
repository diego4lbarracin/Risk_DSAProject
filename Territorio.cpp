#include "TAD.h"


Territorio::Territorio(const string &nombre) {
  this->nombre = nombre;
  // También podrías inicializar otros miembros de la clase aquí si es necesario
}

void Territorio::recopilarVecinos(Continentes vecinos) {

  Continentes::iterator it = vecinos.begin();
  for (; it != vecinos.end(); it++) {
    if (*it->begin() == this->getNombre()) {
      this->setVecinos(*it);
    }
  }
}

void Territorio::mostrarVecinos() const {
  cout << "Territorio: " << nombre << endl;
  cout << "Vecinos: ";
  for (string vecino : vecinos) {
    if(vecino != this->nombre)
    {
      cout << vecino << " ";
    }
  }
  cout << endl;
}

void Territorio::setNombre(string nombre) { this->nombre = nombre; }

void Territorio::setVecinos(list<string> vecinosN) { this->vecinos = vecinosN; }

list<string> Territorio::getVecinos() { return this->vecinos; }

string Territorio::getNombre() { return this->nombre; }

list<Ejercito> Territorio::getEjercitos() { return this->ejercitos; }

void Territorio::agregarEjercitos(Ejercito tropa) { this->ejercitos.push_back(tropa); }

vector<Territorio> Territorio::calcularRuta(Territorio destino) {};