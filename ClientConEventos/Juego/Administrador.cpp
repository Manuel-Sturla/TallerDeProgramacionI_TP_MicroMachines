//
// Created by diego on 9/11/19.
//

#include <iostream>
#include "Administrador.h"
#include "Extra.h"
#include "Auto.h"
#include "../Excepciones/ExcepcionConPos.h"

Administrador::Administrador(Renderizador &renderizador, std::mutex& m) :\
renderizador(renderizador), pista(renderizador), m(m),\
posTexto(0,200,100,1000,-90){}

void Administrador::ejecutarEventos(std::vector<std::string> &eventos) {
    std::unique_lock<std::mutex> lock(m);
    while(!eventos.empty()){
        if(eventos[0] == "morir" && eventos.size() >= 2){
            eventos.erase(eventos.begin());
            ejecutarMorir(eventos);
        } else if(eventos[0] == "posicionarExtra" && eventos.size() >= 4){
            eventos.erase(eventos.begin());
            ejecutarPosicionarExtra(eventos);
        } else if(eventos[0] == "posicionarAuto" && eventos.size() >= 5){
            eventos.erase(eventos.begin());
            ejecutarPosicionarAuto(eventos);
        }else if(eventos[0] == "modificar" && eventos.size() >= 2){
            eventos.erase(eventos.begin());
            ejecutarModificar(eventos);
        } else if(eventos[0] == "eliminarAuto"){
            eventos.erase(eventos.begin());
            ejecutarDestruirAuto(eventos);
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
        desplazables.emplace(eventos[0], new Extra(renderizador, 1, eventos[1]));
        it = desplazables.find(eventos[0]);
        eventos.erase(eventos.begin());
    } else {
        eventos.erase(eventos.begin());
    }
    eventos.erase(eventos.begin());
    it->second->mover(std::stof(eventos[0]), (-1)*std::stof(eventos[1]), 0);
    //Hardcodeo un 0 porque el extra no tiene angulo, lo podria recibir igual pero depende de que me manden.
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
        desplazables.emplace(eventos[0], new Auto(renderizador, 1)); //hardcodeo el tam xq falta hacer en el servidor
        it = desplazables.find(eventos[0]);
//        eventos.erase(eventos.begin());
    }
    eventos.erase(eventos.begin());
    it->second->mover(std::stof(eventos[0]), (-1)*std::stof(eventos[1]), std::stoi(eventos[2]));
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
    eventos.erase(eventos.begin());
}

void Administrador::actualizarJugadores(std::vector<std::string> &evento) {
    renderizador.borrarTextura(idTexto);
    idTexto = renderizador.agregarTexto("Cantidad de jugadores: " + evento[0], &posTexto);
}

void Administrador::crearPista(std::vector<std::string> &planos) {
    renderizador.borrarTextura(idTexto);
    pista.crear(planos);
}

void Administrador::crearMiAuto(std::vector<std::string> &evento) {
    evento.erase(evento.begin());
    desplazables.emplace(evento[0], new Auto(renderizador, 1));
    auto it = desplazables.find(evento[0]);
    renderizador.configurarCamara(it->second->getPosicion());
}

void Administrador::ejecutarDestruirAuto(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    if(it == desplazables.end()){
        throw ExcepcionConPos(__FILE__, __LINE__, "Error: borrar auto invalido: auto no encontrado");
    }
    eventos.erase(eventos.begin());
    it->second->eliminar();
    delete(it->second);
    desplazables.erase(it);
}
