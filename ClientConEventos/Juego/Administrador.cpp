//
// Created by diego on 9/11/19.
//

#include <iostream>
#include "Administrador.h"
#include "Auto.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "../ComandosVisualizacion/ComandoMorir.h"
#include "../ComandosVisualizacion/ComandoPosicionarExtra.h"
#include "../ComandosVisualizacion/ComandoPosicionarAuto.h"
#include "../ComandosVisualizacion/ComandoEliminar.h"

Administrador::Administrador(Renderizador &renderizador, std::mutex& m, bool& keepTalking) : renderizador(renderizador),\
pista(renderizador), m(m), keepTalking(keepTalking), posTexto(0,200,100,1000,-90){
    comandos["morir"] = new ComandoMorir(desplazables, renderizador);
    comandos["posicionarExtra"] = new ComandoPosicionarExtra(desplazables, renderizador);
    comandos["posicionarAuto"] = new ComandoPosicionarAuto(desplazables, renderizador);
    comandos["eliminar"] = new ComandoEliminar(desplazables, renderizador);
    idTexto = -1;
}

void Administrador::ejecutarEventos(std::vector<std::string> &eventos) {
    std::unique_lock<std::mutex> lock(m);
    while(!eventos.empty() && keepTalking){
        auto it = comandos.find(eventos[0]);
        eventos.erase(eventos.begin());
        if(it != comandos.end()){
            it->second->ejecutar(eventos);
        }
    }
}

void Administrador::actualizarJugadores(std::vector<std::string> &evento) {
    renderizador.borrarTextura(idTexto);
    idTexto = renderizador.agregarTexto("Cantidad de jugadores: " + evento[0], &posTexto);
    evento.erase(evento.begin());
}

void Administrador::crearPista(std::vector<std::string> &planos) {
    renderizador.borrarTextura(idTexto);
    idTexto = -1;
    pista.crear(planos);
}

void Administrador::crearMiAuto(std::vector<std::string> &evento) {
    evento.erase(evento.begin());
    desplazables.emplace(evento[0], new Auto(renderizador, 1));
    auto it = desplazables.find(evento[0]);
    renderizador.configurarCamara(it->second->getPosicion());
}

Administrador::~Administrador() {
    for(auto & comando : comandos){
        delete(comando.second);
    }
}
