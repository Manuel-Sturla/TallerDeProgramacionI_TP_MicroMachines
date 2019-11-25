//
// Created by diego on 23/10/19.
//

#ifndef OPENGLTEST_TEXTURA_H
#define OPENGLTEST_TEXTURA_H


#include <SDL2/SDL_system.h>
#include "Posicion.h"
#include "../Vista/Camara.h"
#include <string>

class Textura {
private:
    SDL_Texture* textura;
    Posicion* posicion;
    SDL_Surface* superficie;

public:
    Textura(SDL_Renderer* renderizador, const std::string& archivo, Posicion* pos);

    Textura(SDL_Texture *textura, Posicion *pos, SDL_Surface *superificie);

    Textura& operator=(const Textura& text);

    Textura(Textura&& text) noexcept;

    bool copiar(SDL_Renderer* renderizador, Camara& camara);

    void copiar(SDL_Renderer* renderizador);

    void destruir();

    virtual ~Textura();
};


#endif //OPENGLTEST_TEXTURA_H
