//
// Created by diego on 9/11/19.
//

#include "AdministradorDeDesplazables.h"
#include "Extra.h"
#include "Auto.h"

AdministradorDeDesplazables::AdministradorDeDesplazables(Renderizador &renderizador) : renderizador(renderizador) {}

void AdministradorDeDesplazables::ejecutarEventos(std::vector<std::string> &eventos) {
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

void AdministradorDeDesplazables::ejecutarMorir(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    eventos.erase(eventos.begin());
    if(it == desplazables.end()){ return; }
    it->second->morir();
}

void AdministradorDeDesplazables::ejecutarPosicionarExtra(std::vector<std::string> &eventos) {
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

void AdministradorDeDesplazables::ejecutarModificar(std::vector<std::string> &eventos) {
    auto it = desplazables.find(eventos[0]);
    eventos.erase(eventos.begin());
    if(it == desplazables.end()){ return; }
    it->second->modificar(eventos[0]);
    eventos.erase(eventos.begin());
}

void AdministradorDeDesplazables::setCamara(Camara &camara) {
    camara.setAuto(desplazables.begin()->second->getPosicion());
}

void AdministradorDeDesplazables::ejecutarPosicionarAuto(std::vector<std::string> &eventos) {
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
