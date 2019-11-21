//
// Created by diego on 22/10/19.
//

#include "Ventana.h"
#include "../Excepciones/ExcepcionConPos.h"

Ventana::Ventana(const char* titulo, int ancho, int largo) {
    ventana = SDL_CreateWindow(titulo, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ancho, largo, SDL_WINDOW_OPENGL); // NOLINT(hicpp-signed-bitwise)
    if(ventana == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude abrir la ventana");
    }
}

Ventana::~Ventana() {
    if(ventana != nullptr){
        SDL_DestroyWindow(ventana);
    }
}

SDL_Renderer *Ventana::crearRenderizador(int indice, Uint32 flags) {
    return SDL_CreateRenderer(ventana, indice, flags);
}
