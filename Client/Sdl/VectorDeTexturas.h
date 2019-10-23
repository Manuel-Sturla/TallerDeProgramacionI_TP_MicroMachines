//
// Created by diego on 23/10/19.
//

#ifndef OPENGLTEST_VECTORDETEXTURAS_H
#define OPENGLTEST_VECTORDETEXTURAS_H


#include <vector>
#include "Textura.h"

class VectorDeTexturas {
private:
    std::vector<Textura> texturas;

public:
    VectorDeTexturas() = default;

    VectorDeTexturas(SDL_Renderer* renderizador, std::vector<std::string>& archivos);

    void agregarTextura(SDL_Renderer* renderizador, const std::string& archivo, SDL_Rect* pos);
};


#endif //OPENGLTEST_VECTORDETEXTURAS_H
