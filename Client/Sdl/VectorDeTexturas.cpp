//
// Created by diego on 23/10/19.
//

#include "VectorDeTexturas.h"

VectorDeTexturas::VectorDeTexturas(SDL_Renderer *renderizador, std::vector<std::string>& archivos) {
/*    for(auto & archivo : archivos){
        texturas.emplace_back(renderizador, archivo);
    }*/
}

void VectorDeTexturas::agregarTextura(SDL_Renderer *renderizador, const std::string &archivo, SDL_Rect* pos) {
    texturas.emplace_back(renderizador, archivo, pos);
}
