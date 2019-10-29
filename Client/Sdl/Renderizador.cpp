//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "Renderizador.h"
#include "../Excepciones/ExcepcionConPos.h"

Renderizador::Renderizador(const char* titulo, int ancho, int altura) : ventana(titulo, ancho, altura) {
    renderizador = ventana.crearRenderizador(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderizador == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude crear el renderizador");
    }
}

void Renderizador::imprimir(Uint32 tiempoMs) {
    SDL_RenderPresent(renderizador);
    SDL_Delay(tiempoMs);
}

void Renderizador::agregarTextura(const std::string &archivo, Posicion* pos, int angulo) {
    texturas.emplace_back(renderizador, archivo, pos, angulo);
}

void Renderizador::limpiar() {
    SDL_RenderClear(renderizador);
}

void Renderizador::copiarTodo() {
    for(auto & trecho : pista){
        trecho.copiar(renderizador);
    }
    for(auto & textura : texturas){
        textura.copiar(renderizador);
    }
}

Renderizador::~Renderizador() {
    if(renderizador != nullptr){
        SDL_DestroyRenderer(renderizador);
    }
}

void Renderizador::agregarTrecho(const std::string &archivo, Posicion* pos, int angulo) {
    pista.emplace_back(renderizador, archivo, pos, angulo);
}

std::vector<Textura> &Renderizador::getPista() {
    return pista;
}
