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

unsigned long Renderizador::agregarTextura(const std::string &archivo, Posicion* pos) {
    texturas.emplace_back(renderizador, archivo, pos);
    return texturas.size()-1;
}

void Renderizador::agregarTrecho(const std::string &archivo, Posicion* pos) {
    pista.emplace_back(renderizador, archivo, pos);
}

void Renderizador::limpiar() {
    SDL_RenderClear(renderizador);
}

void Renderizador::copiarTodo() {
    int i = 0;
    for(auto& trecho : pista){
        trecho.copiar(renderizador, camara);
    }
    for(auto& textura : texturas){
        textura.copiar(renderizador, camara);
    }
}

void Renderizador::configurarCamara(Posicion* posicion) {
    camara.setAuto(posicion);
}

size_t Renderizador::agregarTexto(const std::string &texto, Posicion *posicion) {
    TTF_Font* fuente = TTF_OpenFont("../fuente.ttf", 24);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* superficie = TTF_RenderText_Solid(fuente, texto.c_str(), color);
    SDL_Texture* mensaje = SDL_CreateTextureFromSurface(renderizador, superficie);
    texturas.emplace_back(mensaje, posicion);
    return texturas.size()-1;
}

Renderizador::~Renderizador() {
    for(auto & texura : texturas){
        texura.destruir();
    }
    for(auto & trecho : pista){
        trecho.destruir();
    }
    if(renderizador != nullptr){
        SDL_DestroyRenderer(renderizador);
    }
}

void Renderizador::borrarTextura(unsigned long idTextura) {
    if(idTextura >= 0 && idTextura < texturas.size()){
        texturas.erase(texturas.begin() + idTextura);
    }
}