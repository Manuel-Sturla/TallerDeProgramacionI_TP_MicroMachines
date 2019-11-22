//
// Created by diego on 22/10/19.
//

#include <SDL2/SDL_timer.h>
#include "Renderizador.h"
#include "../Excepciones/ExcepcionConPos.h"
#include <SDL2/SDL_ttf.h>

Renderizador::Renderizador(const char *titulo, int ancho, int altura, std::mutex &m, int aumentoCamara) :\
ventana(titulo, ancho, altura), m(m), camara(ancho, altura, aumentoCamara) {
    renderizador = ventana.crearRenderizador(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderizador == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude crear el renderizador");
    }
    fuente = TTF_OpenFont("../fuente.ttf", 24);
    if(fuente == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, TTF_GetError());
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
    for(auto& texto : otros){
        texto.second.copiar(renderizador);
    }
}

void Renderizador::configurarCamara(Posicion* posicion) {
    camara.setAuto(posicion);
}

size_t Renderizador::agregarTexto(const std::string &texto, Posicion *posicion, std::string &id, Uint8 r, Uint8 g, Uint8 b) {
    SDL_Color color = {r, g, b};
    SDL_Surface* superficie = TTF_RenderText_Solid(fuente, texto.c_str(), color);
    if(superficie == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, TTF_GetError());
    }
    SDL_Texture* mensaje = SDL_CreateTextureFromSurface(renderizador, superficie);
    if(mensaje == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, SDL_GetError());
    }
    otros.insert(std::pair<std::string, Textura> (id, Textura(mensaje, posicion, nullptr)));
}

void Renderizador::agregarExtra(const std::string &archivo, Posicion *pos, std::string &id) {
    autos.insert(std::pair<std::string, Textura> (id, Textura(renderizador, archivo, pos)));
}

void Renderizador::agregarTextura(const std::string &archivo, Posicion *pos, std::string &id) {
    otros.insert(std::pair<std::string, Textura> (id, Textura(renderizador, archivo, pos)));
}

void Renderizador::borrarExtra(const std::string& id) {
    auto it = extras.find(id);
    if(it != extras.end()){
        it->second.destruir();
        extras.erase(it);
    }
}

void Renderizador::borrarAuto(const std::string& id) {
    auto it = autos.find(id);
    if(it != autos.end()){
        it->second.destruir();
        autos.erase(it);
    }
}

void Renderizador::borrarTexto(std::string &id) {
    auto it = otros.find(id);
    if(it != otros.end()){
        it->second.destruir();
        otros.erase(it);
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
    for(auto & texto : otros){
        texto.second.destruir();
    }
    extras.clear();
    autos.clear();
    pista.clear();
    otros.clear();
}

Renderizador::~Renderizador() {
    borrarTodo();
    TTF_CloseFont(fuente);
    if(renderizador != nullptr){
        SDL_DestroyRenderer(renderizador);
    }
}

int Renderizador::obtenerAltura() {
    return ventana.obtenerAltura();
}

int Renderizador::obtenerAncho() {
    return ventana.obtenerAncho();
}
