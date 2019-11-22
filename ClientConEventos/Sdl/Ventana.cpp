//
// Created by diego on 22/10/19.
//

#include "Ventana.h"
#include "../Excepciones/ExcepcionConPos.h"

Ventana::Ventana(const char* titulo, int ancho, int altura) {
    ventana = SDL_CreateWindow(titulo, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ancho, altura, SDL_WINDOW_OPENGL); // NOLINT(hicpp-signed-bitwise)
    if(ventana == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude abrir la ventana");
    }
    this->altura = altura;
    this->ancho = ancho;
}

Ventana::~Ventana() {
    if(ventana != nullptr){
        SDL_DestroyWindow(ventana);
    }
}

SDL_Renderer *Ventana::crearRenderizador(int indice, Uint32 flags) {
    return SDL_CreateRenderer(ventana, indice, flags);
}

int Ventana::obtenerAltura() {
    return altura;
}

int Ventana::obtenerAncho() {
    return ancho;
}
