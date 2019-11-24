//
// Created by manfer on 14/11/19.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "JugadorCPU.h"
#include "Lua/ParametrosLua/CadenaLua.h"
#include "Lua/ParametrosLua/EnteroLua.h"

#define FUNC_NUEVA_ACCION "obtenerNuevaAccion"
#define FUNC_NUEVO_MAPA "crearMapa"

JugadorCPU::JugadorCPU(const std::string &rutaScript) : Jugador(true), interprete(rutaScript){
}

int JugadorCPU::obtenerComando(AdministradorComandosTeclado &comandos) {
    comandos.desapretar(SDLK_LEFT);
    comandos.desapretar(SDLK_RIGHT);
    comandos.desapretar(SDLK_DOWN);
    comandos.desapretar(SDLK_UP);
    //Hace un sleep para que tarde en dar una nueva accion
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    //Si todavia no se seteo mi auto devuelvo 0
    if (!miAuto){
        return 0;
    }
    SDL_Event evento;
    if(SDL_PollEvent(&evento)){
        if(evento.type == SDL_QUIT){
            return -1;
        }
    }
    std::vector<std::unique_ptr<ParametroLua>> params;
    Posicion* pos = miAuto->getPosicion();
    params.emplace_back(new CadenaLua (std::to_string(std::floor(pos->getPosicion().x)) + "," + std::to_string(std::floor(pos->getPosicion().y))));
    params.emplace_back(new EnteroLua(pos->getAngulo()));
    std::vector<std::unique_ptr<ParametroLua>> ret = interprete.ejecutarFuncion(FUNC_NUEVA_ACCION, params);
    std::string valor = ret[0]->obtenerValor().cadena;
    if ( valor == "A"){
        comandos.apretar(SDLK_LEFT);
    }else if (valor == "D"){
        comandos.apretar(SDLK_RIGHT);
    }else if (valor == "S"){
        comandos.apretar(SDLK_DOWN);
    }else if (valor == "W"){
        comandos.apretar(SDLK_UP);
    }
    return 0;
}

void JugadorCPU::ponerMapa(std::vector<std::string> &comando) {
    //comando.erase(comando.begin());
    for (auto& c : comando){
        std::cout << c << "; ";
    }
    std::cout << std::endl;
    std::string nombreTabla = "tablaAuxiliar";
    for (size_t i = 1; i <= comando.size(); i++) {
        CadenaLua posicion(comando[i-1]);
        EnteroLua indice(i);
        interprete.agregarElementoTabla(nombreTabla, indice, posicion);
    }
    std::vector<std::string> vars = {nombreTabla};
    interprete.ejecutarFuncion(FUNC_NUEVO_MAPA, vars);
    //interprete.ejecutarFuncion("MostrarMapa");
}

void JugadorCPU::ponerAuto(Desplazable* unAuto) {
    miAuto = unAuto;
}

