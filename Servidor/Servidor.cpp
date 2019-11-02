#include "Servidor.h"
#include "Partida.h"
#include <fstream>
#include <iostream>
#include <memory>

Servidor::Servidor() {
  levantarPistas();
}

void Servidor::levantarPistas() {
  std::ifstream pistas("Pistas.txt", std::ifstream::in);
  std::string linea;
  while (!pistas.eof()) {
    getline(pistas, linea);
    if (linea == "Nueva Pista") {
      std::string nombreDePista;
      getline(pistas, nombreDePista);
      planosDePistas.emplace(nombreDePista, new PlanoDePista());
      getline(pistas, linea);
      while (linea != "Fin Pista") {
        planosDePistas[nombreDePista] -> agregarSuelo(linea);
        getline(pistas, linea);
      }
    }
  }
}

Servidor::~Servidor() {
}

void Servidor::jugar() {
  b2Vec2 gravedad(0.0f, 0.0f);
  Partida partida(gravedad);
  //partida.crearPista(planosDePistas["Prueba 1"]);
  for (int32 i = 0; i < 5; ++i) {
    partida.simular();
  }
}
