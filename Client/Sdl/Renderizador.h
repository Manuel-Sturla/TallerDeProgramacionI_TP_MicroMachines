//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_RENDERIZADOR_H
#define OPENGLTEST_RENDERIZADOR_H


#include "Ventana.h"
#include "Textura.h"
#include <SDL2/SDL.h>
#include <map>

class Renderizador {
private:
    SDL_Renderer* renderizador;
    Ventana ventana;
    std::map<std::string, Textura> texturas;

public:
    Renderizador(const char* titulo, int ancho, int altura);

    void agregarTextura(const std::string& archivo, Posicion& pos, const std::string& nombre);

    void imprimir(Uint32 tiempoMs);

    void limpiar();

    void mover(const std::string& nombre, int posX, int posY);

    virtual ~Renderizador();

    void copiar(const std::string &nombre);
};


#endif //OPENGLTEST_RENDERIZADOR_H
