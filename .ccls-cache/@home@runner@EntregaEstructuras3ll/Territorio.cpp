#include "TAD.h"
#include <queue>
#include <unordered_map>
#include <vector>

void Territorio::recopilarVecinos(Continentes continentes, std::unordered_map<std::string, Territorio*>& mapaTerritorios) {
    for (const auto& listaPaises : continentes) {
        if (listaPaises.front() == this->getNombre()) {
            for (const auto& nombreVecino : listaPaises) {
                if (nombreVecino != this->getNombre()) {
                    Territorio* vecino = mapaTerritorios[nombreVecino];
                    if (vecino) {
                        this->agregarVecino(vecino);
                    }
                }
            }
            break;
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

const std::vector<Territorio *> &Territorio::getVecinos() const {
  return vecinos;
}

void Territorio::setVecinos(const std::vector<Territorio *> &nuevosVecinos) {
  vecinos = nuevosVecinos;
}

void Territorio::agregarVecino(Territorio *vecino) {
  vecinos.push_back(vecino);
}

string Territorio::getNombre() { return this->nombre; }

int Territorio::getEjercitos() { return this->ejercitos; }

void Territorio::agregarEjercitos(int cantidad) { this->ejercitos += cantidad; }

std::vector<Territorio *> Territorio::calcularRuta(Territorio *destino) {
  std::queue<Territorio *> cola;
  std::unordered_map<Territorio *, Territorio *> previo;
  std::vector<Territorio *> ruta;

  cola.push(this);
  previo[this] = nullptr;

  while (!cola.empty()) {
    Territorio *actual = cola.front();
    cola.pop();

    if (actual == destino) {
      while (actual != nullptr) {
        ruta.insert(ruta.begin(), actual);
        actual = previo[actual];
      }
      return ruta;
    }

    for (auto vecino : actual->vecinos) {
      if (previo.find(vecino) == previo.end()) {
        cola.push(vecino);
        previo[vecino] = actual;
      }
    }
  }

  // Retorna una lista vacía si no hay ruta
  return ruta;
}