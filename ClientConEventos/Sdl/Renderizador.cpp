//
// Created by diego on 22/10/19.
//

#include <SDL2/SDL_timer.h>
#include "Renderizador.h"
#include "../Excepciones/ExcepcionConPos.h"
#include <SDL2/SDL_ttf.h>

Renderizador::Renderizador(const char* titulo, int ancho, int altura) : ventana(titulo, ancho, altura),\
camara(1000, 100) {
    renderizador = ventana.crearRenderizador(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderizador == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude crear el renderizador");
    }
}

void Renderizador::imprimir(Uint32 tiempoMs) {
    SDL_RenderPresent(renderizador);
    SDL_Delay(tiempoMs);
}

void Renderizador::agregarTextura(const std::string &archivo, Posicion* pos) {
    texturas.emplace_back(renderizador, archivo, pos);
}

void Renderizador::agregarTrecho(const std::string &archivo, Posicion* pos) {
    pista.emplace_back(renderizador, archivo, pos);
}

void Renderizador::limpiar() {
    SDL_RenderClear(renderizador);
}

void Renderizador::copiarTodo() {
    int i = 0;
    while(i < pista.size()){
        if(!pista[i].copiar(renderizador, camara)){
            std::iter_swap(pista.begin()+i, pista.end()-1);
            pista.pop_back();
        } else {
            i++;
        }
    }
    i = 0;
    while(i < texturas.size()){
        if(!texturas[i].copiar(renderizador, camara)){
            std::iter_swap(texturas.begin()+i, texturas.end()-1);
            texturas.pop_back();
        } else {
            i++;
        }
    }
}

void Renderizador::configurarCamara(Posicion* posicion) {
    camara.setAuto(posicion);
}

void Renderizador::agregarTexto(const std::string &texto, Posicion *posicion) {
    TTF_Font* fuente = TTF_OpenFont("../fuente.ttf", 24);
    SDL_Color color = {255, 255, 255};
    SDL_Surface* superficie = TTF_RenderText_Solid(fuente, texto.c_str(), color);
    SDL_Texture* mensaje = SDL_CreateTextureFromSurface(renderizador, superficie);
    texturas.emplace_back(mensaje, posicion);
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
