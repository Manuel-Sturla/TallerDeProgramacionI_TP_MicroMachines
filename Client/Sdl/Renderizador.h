//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_RENDERIZADOR_H
#define OPENGLTEST_RENDERIZADOR_H


#include "Ventana.h"
#include "Textura.h"
#include <SDL2/SDL.h>
#include <vector>

class Renderizador {
private:
    SDL_Renderer* renderizador;
    Ventana ventana;
    std::vector<Textura> texturas;
    std::vector<Textura> pista;

public:
    Renderizador(const char* titulo, int ancho, int altura);

    void agregarTextura(const std::string &archivo, Posicion* pos, int angulo);

    void agregarTrecho(const std::string &archivo, Posicion* pos, int angulo);

    void imprimir(Uint32 tiempoMs);

    std::vector<Textura>& getPista();

    void limpiar();

    void copiarTodo();

    virtual ~Renderizador();
};


#endif //OPENGLTEST_RENDERIZADOR_H
