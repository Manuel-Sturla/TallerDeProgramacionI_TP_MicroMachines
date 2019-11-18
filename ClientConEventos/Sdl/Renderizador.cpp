//
// Created by diego on 22/10/19.
//

#include <SDL2/SDL_timer.h>
#include "Renderizador.h"
#include "../Excepciones/ExcepcionConPos.h"
#include <SDL2/SDL_ttf.h>

Renderizador::Renderizador(const char *titulo, int ancho, int altura, std::mutex &m) :\
ventana(titulo, ancho, altura), m(m), camara(1000, 100) {
    renderizador = ventana.crearRenderizador(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderizador == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude crear el renderizador");
    }
}

void Renderizador::imprimir(Uint32 tiempoMs) {
    SDL_RenderPresent(renderizador);
    SDL_Delay(tiempoMs);
}

void Renderizador::agregarAuto(const std::string &archivo, Posicion *pos, std::string &id) {
    autos.insert(std::pair<std::string, Textura> (id, Textura(renderizador, archivo, pos)));
}

size_t Renderizador::agregarTrecho(const std::string &archivo, Posicion* pos) {
    pista.emplace_back(renderizador, archivo, pos);
    return pista.size()-1;
}

void Renderizador::limpiar() {
    SDL_RenderClear(renderizador);
}

void Renderizador::copiarTodo() {
    std::unique_lock<std::mutex> lock(m);
    for(auto& trecho : pista){
        trecho.copiar(renderizador, camara);
    }
    for(auto& extra : extras){
        extra.second.copiar(renderizador, camara);
    }
    for(auto& autito : autos){
        autito.second.copiar(renderizador, camara);
    }
}

void Renderizador::configurarCamara(Posicion* posicion) {
    camara.setAuto(posicion);
}

size_t Renderizador::agregarTexto(const std::string &texto, Posicion *posicion, std::string &id) {
    TTF_Font* fuente = TTF_OpenFont("../fuente.ttf", 24);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* superficie = TTF_RenderText_Solid(fuente, texto.c_str(), color);
    SDL_Texture* mensaje = SDL_CreateTextureFromSurface(renderizador, superficie);
    extras.insert(std::pair<std::string, Textura> (id, Textura(mensaje, posicion)));
}

void Renderizador::agregarExtra(const std::string &archivo, Posicion *pos, std::string &id) {
    autos.insert(std::pair<std::string, Textura> (id, Textura(renderizador, archivo, pos)));
}

void Renderizador::borrarExtra(std::string id) {
    auto it = extras.find(id);
    if(it != extras.end()){
        it->second.destruir();
        extras.erase(it);
    }
}

void Renderizador::borrarAuto(std::string id) {
    auto it = autos.find(id);
    if(it != autos.end()){
        it->second.destruir();
        extras.erase(it);
    }
}

void Renderizador::borrarTrecho(size_t idTrecho){
    if(idTrecho >= 0 && idTrecho < pista.size()){
        pista.erase(pista.begin() + idTrecho);
    }
}

void Renderizador::borrarTodo() {
    camara.setAuto(nullptr);
    for(auto & extra : extras){
        extra.second.destruir();
    }
    for(auto & autito : extras){
        autito.second.destruir();
    }
    for(auto & trecho : pista){
        trecho.destruir();
    }
    extras.clear();
    autos.clear();
    pista.clear();
}

Renderizador::~Renderizador() {
    borrarTodo();
    if(renderizador != nullptr){
        SDL_DestroyRenderer(renderizador);
    }
}
