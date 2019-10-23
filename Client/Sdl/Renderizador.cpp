//
// Created by diego on 22/10/19.
//

#include "Renderizador.h"
#include "../Excepciones/ExcepcionConPos.h"

#define anchoPorDefecto 640
#define largoPorDefecto 480

Renderizador::Renderizador() : ventana("ventana", anchoPorDefecto, largoPorDefecto) {
    renderizador = ventana.crearRenderizador(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderizador == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude crear el renderizador");
    }
}

Renderizador::Renderizador(Ventana &ventana) : ventana(ventana) {
    renderizador = ventana.crearRenderizador(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderizador == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude crear el renderizador");
    }
}

void Renderizador::imprimir() {
    SDL_RenderPresent(renderizador);
}

void Renderizador::agregarFondo(const std::string &archivo) {
    texturas.agregarTextura(renderizador, archivo, nullptr);
}

Renderizador::~Renderizador() {
    if(renderizador != nullptr){
        SDL_DestroyRenderer(renderizador);
    }
}

void Renderizador::agregarTextura(const std::string &archivo, SDL_Rect *pos) {
    texturas.agregarTextura(renderizador, archivo, pos);
}

