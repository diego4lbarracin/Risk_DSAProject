#include "TAD.h"

std::vector<Territorio> EstrategiaDeJuego::calcularConquista(Territorio origen, Territorio destino) {
  return origen.calcularRuta(destino);
}