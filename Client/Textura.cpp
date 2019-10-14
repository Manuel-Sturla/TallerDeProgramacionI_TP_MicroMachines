#include <SDL2/SDL.h>
#include "Textura.h"
#include <stdexcept>
#define S1(x) #x
#define S2(x) S1(x)
#define POSICION __FILE__ " : " S2(__LINE__)

Textura::Textura(const std::string &archivo, SDL_Renderer *rd) {
    renderizador = rd;
    renderizarTextura(archivo);
}

void Textura::mostrar(int tiempoMs) {
    SDL_RenderPresent(renderizador);
    SDL_Delay(tiempoMs);
}

Textura::~Textura() {
    for(auto textura : texturas){
        SDL_DestroyTexture(textura);
    }
}

unsigned long Textura::agregarTextura(const std::string& archivo) {
    SDL_Surface *bmp = SDL_LoadBMP(archivo.c_str());
    if (bmp == nullptr){
        std::string error("Error: ");
        error.append(POSICION);
        throw std::runtime_error(error+std::string(" ") + SDL_GetError());
    }
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderizador, bmp);
    SDL_FreeSurface(bmp);
    if(textura == nullptr){
        std::string error("Error: ");
        error.append(POSICION);
        throw std::runtime_error(error+std::string(" ") + SDL_GetError());
    }
    texturas.push_back(textura);
    return texturas.size()-1;
}

void Textura::renderizarTextura(const std::string& archivo, int posX, int posY) {
    unsigned long textura = agregarTextura(archivo);
    SDL_Rect dst;
    dst.x = posX;
    dst.y = posY;
    SDL_QueryTexture(texturas[textura], nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(renderizador, texturas[textura], nullptr, &dst);
}

void Textura::renderizarTextura(const std::string &archivo) {
    unsigned long textura = agregarTextura(archivo);
    SDL_RenderCopy(renderizador, texturas[textura], nullptr, nullptr);
}
