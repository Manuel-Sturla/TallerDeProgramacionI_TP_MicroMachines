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

public:
    Textura(SDL_Renderer* renderizador, const std::string& archivo, Posicion* pos);

    Textura(SDL_Texture* textura, Posicion* pos);

    Textura& operator=(const Textura& text);

    Textura(Textura&& text) noexcept;

    bool copiar(SDL_Renderer* renderizador, Camara& camara);

    void destruir();

    virtual ~Textura();
};


#endif //OPENGLTEST_TEXTURA_H
