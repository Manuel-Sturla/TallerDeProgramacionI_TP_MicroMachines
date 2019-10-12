#include <stdexcept>
#include <SDL2/SDL_timer.h>
#include "Ventana.h"
#define S1(x) #x
#define S2(x) S1(x)
#define POSICION __FILE__ " : " S2(__LINE__)

Ventana::Ventana(int ancho, int altura) {
    ventana = nullptr;
    renderizador = nullptr;
    int err = SDL_CreateWindowAndRenderer(ancho, altura, 0, &ventana, &renderizador);
    if(err != 0){
        std::string error("Error: ");
        error.append(POSICION);
        throw std::runtime_error(error +std::string(" ")+ SDL_GetError());
    }
}

Ventana::~Ventana() {
    if(renderizador){
        SDL_DestroyRenderer(renderizador);
        renderizador = nullptr;
    }
    if(ventana){
        SDL_DestroyWindow(ventana);
        ventana = nullptr;
    }
}

SDL_Renderer *Ventana::getRenderizador() {
    if(renderizador == nullptr){
        std::string error("Error el renderizador no existe: ");
        error.append(POSICION);
        throw std::runtime_error(error);
    }
    return renderizador;
}
