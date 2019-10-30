//
// Created by diego on 22/10/19.
//

#include <SDL2/SDL_timer.h>
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

void Renderizador::agregarTextura(const std::string &archivo, Posicion* pos) {
    texturas.emplace_back(renderizador, archivo, pos);
}

void Renderizador::agregarTrecho(const std::string &archivo, Posicion* pos) {
    pista.emplace_back(renderizador, archivo, pos);
}

void Renderizador::limpiar() {
    SDL_RenderClear(renderizador);
}

void Renderizador::copiarTodo(Camara& camara) {
    for(auto & trecho : pista){
        trecho.copiar(renderizador, camara);
    }
    for(auto & textura : texturas){
        textura.copiar(renderizador, camara);
    }
}

void Renderizador::agregarFondo(const std::string& archivo) {
    pista.emplace(pista.begin(), renderizador, archivo);
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
