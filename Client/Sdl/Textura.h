//
// Created by diego on 23/10/19.
//

#ifndef OPENGLTEST_TEXTURA_H
#define OPENGLTEST_TEXTURA_H


#include <SDL2/SDL_render.h>
#include <string>

class Textura {
private:
    SDL_Texture* textura;
    SDL_Rect* posicion;

public:
    Textura(SDL_Renderer* renderizador, const std::string& archivo, SDL_Rect* pos);

    void moverA(int posX, int posY);

    virtual ~Textura();
};


#endif //OPENGLTEST_TEXTURA_H
