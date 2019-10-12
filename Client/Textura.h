//
// Created by diego on 12/10/19.
//

#ifndef OPENGLTEST_TEXTURA_H
#define OPENGLTEST_TEXTURA_H

#include <string>
#include <SDL2/SDL_render.h>

class Textura {
private:
    SDL_Texture* textura;
    SDL_Renderer* renderizador;

public:
    Textura(const std::string& archivo, SDL_Renderer* rd);

    virtual ~Textura();

    void mostrar(int tiempoMs);
};


#endif //OPENGLTEST_TEXTURA_H
