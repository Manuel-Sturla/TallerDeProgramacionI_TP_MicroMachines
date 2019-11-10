//
// Created by diego on 9/11/19.
//

#include "Administrador.h"
#include "Extra.h"
#include "Auto.h"

Administrador::Administrador(Renderizador &renderizador) : renderizador(renderizador), pista(renderizador),\
posTexto(0,0,50,50,0){
    cantJugadores = 1;
}

void Administrador::ejecutarEventos(std::vector<std::string> &eventos) {
    while(!eventos.empty()){
        if(eventos[0] == "morir" && eventos.size() >= 2){
            eventos.erase(eventos.begin());
            ejecutarMorir(eventos);
        } else if(eventos[0] == "posicionarExtra" && eventos.size() >= 5){
            eventos.erase(eventos.begin());
            ejecutarPosicionarExtra(eventos);
        } else if(eventos[0] == "posicionarAuto" && eventos.size() >= 5){
            eventos.erase(eventos.begin());
            ejecutarPosicionarAuto(eventos);
        }else if(eventos[0] == "modificar" && eventos.size() >= 2){
            eventos.erase(eventos.begin());
            ejecutarModificar(eventos);
        } else {
            eventos.erase(eventos.begin());
        }
    }
}

void Administrador::ejecutarMorir(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    eventos.erase(eventos.begin());
    if(it == desplazables.end()){ return; }
    it->second->morir();
}

void Administrador::ejecutarPosicionarExtra(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    if(it == desplazables.end()){
        desplazables.emplace(eventos[0], new Extra(renderizador, std::stoi(eventos[1]), std::__cxx11::string()));
        it = desplazables.find(eventos[0]);
        eventos.erase(eventos.begin());
    }
    eventos.erase(eventos.begin());
    it->second->mover(std::stof(eventos[0]), std::stof(eventos[1]), 0);
    //Hardcodeo un 0 porque el extra no tiene angulo, lo podria recibir igual pero depende de que me manden.
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
}

void Administrador::ejecutarModificar(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    eventos.erase(eventos.begin());
    if(it == desplazables.end()){ return; }
    it->second->modificar(eventos[0]);
    eventos.erase(eventos.begin());
}

void Administrador::ejecutarPosicionarAuto(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    if(it == desplazables.end()){
        desplazables.emplace(eventos[0], new Auto(renderizador, std::stoi(eventos[1])));
        it = desplazables.find(eventos[0]);
        eventos.erase(eventos.begin());
    }
    eventos.erase(eventos.begin());
    it->second->mover(std::stof(eventos[0]), std::stof(eventos[1]), std::stoi(eventos[2]));
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
}

void Administrador::actualizarJugadores(std::vector<std::string> &evento) {
    posTexto.invalidar();
    renderizador.agregarTexto("Cantidad de jugadores: " + evento[0], &posTexto);
}

void Administrador::crearPista(std::vector<std::string> &planos) {
    pista.crear(planos);
}

void Administrador::crearMiAuto(std::vector<std::string> &evento) {
    evento.erase(evento.begin());
    desplazables.emplace(evento[0], new Auto(renderizador, std::stoi(evento[1])));
    auto it = desplazables.find(evento[0]);
    renderizador.configurarCamara(it->second->getPosicion());
}
