#include "TAD.h"

void Carta::mostrarContenido() const {
  cout << "Tipo: " << tipo << endl;
  cout << "Territorio: " << territorio << endl;
}

char Carta::getTipo() {
  return this->tipo;
}

string Carta::getTerritorio() {
  return this->territorio;
}