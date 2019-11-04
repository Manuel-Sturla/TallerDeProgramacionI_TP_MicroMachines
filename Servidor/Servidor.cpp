#include "Servidor.h"
#include "Partida/Partida.h"
#include "Comunicacion/ClienteProxy.h"
#include <fstream>
#include <iostream>
#include <memory>

Servidor::Servidor(SocketPasivo *unSocketPasivo) {
  levantarPistas();
  socketPasivo = unSocketPasivo;
  //HARDCODEAR SERVICIOOOOOOOOOOOOOOOOOO
  socketPasivo ->unirse("7777");
  socketPasivo -> escuchar();
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
  std::unordered_map<std::string, PlanoDePista*>::iterator it;
  for (it = planosDePistas.begin(); it != planosDePistas.end(); it++) {
    delete it -> second;
  }
}

void Servidor::run() {
  Partida partida;
  SocketAmigo socketAmigo = std::move(socketPasivo -> aceptarCliente());
  ClienteProxy clienteProxy(std::move(socketAmigo), partida);
  partida.crearPista(planosDePistas["Prueba 1"]);
  partida.actualizar();
  clienteProxy.ejecutarComando();
  while (clienteProxy.estaConectado()){
    clienteProxy.recibirAccion();
    clienteProxy.ejecutarAccion(partida.getCarro());
    partida.simular();
    partida.actualizar();
    clienteProxy.ejecutarComando();
  }
}
