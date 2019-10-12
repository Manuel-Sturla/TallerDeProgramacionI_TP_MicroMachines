#include <SDL2/SDL.h>
#include "Textura.h"
#include <stdexcept>
#define S1(x) #x
#define S2(x) S1(x)
#define POSICION __FILE__ " : " S2(__LINE__)

Textura::Textura(const std::string &archivo, SDL_Renderer *rd) {
    renderizador = rd;
    SDL_Surface *bmp = SDL_LoadBMP(archivo.c_str());
    if (bmp == nullptr){
        std::string error("Error: ");
        error.append(POSICION);
        throw std::runtime_error(error+std::string(" ") + SDL_GetError());
    }
    textura = SDL_CreateTextureFromSurface(rd, bmp);
    SDL_FreeSurface(bmp);
    if(textura == nullptr){
        std::string error("Error: ");
        error.append(POSICION);
        throw std::runtime_error(error+std::string(" ") + SDL_GetError());
    }
}

Textura::~Textura() {
    SDL_DestroyTexture(textura);
}

void Textura::mostrar(int tiempoMs) {
    SDL_RenderClear(renderizador);
    SDL_RenderCopy(renderizador, textura, nullptr, nullptr);
    SDL_RenderPresent(renderizador);
    SDL_Delay(tiempoMs);
}
