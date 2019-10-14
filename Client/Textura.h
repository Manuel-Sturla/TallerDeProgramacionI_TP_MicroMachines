//
// Created by diego on 12/10/19.
//

#ifndef OPENGLTEST_TEXTURA_H
#define OPENGLTEST_TEXTURA_H

#include <string>
#include <SDL2/SDL_render.h>
#include <vector>

class Textura {
private:
    std::vector<SDL_Texture*> texturas;
    SDL_Renderer* renderizador;
    unsigned long agregarTextura(const std::string& archivo);

public:
    Textura(const std::string& archivo, SDL_Renderer* rd);

    void renderizarTextura(const std::string& archivo);

    void renderizarTextura(const std::string& archivo, int posX, int posY);

    void mostrar(int tiempoMs);

    virtual ~Textura();
};


#endif
