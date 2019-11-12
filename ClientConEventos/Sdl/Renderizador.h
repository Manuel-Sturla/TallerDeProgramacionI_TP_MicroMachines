//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_RENDERIZADOR_H
#define OPENGLTEST_RENDERIZADOR_H

#include <SDL2/SDL_system.h>
#include <vector>
#include <map>
#include "Ventana.h"
#include "Posicion.h"
#include "Textura.h"

class Renderizador {
private:
    std::mutex& m;
    SDL_Renderer* renderizador;
    Ventana ventana;
    std::vector<Textura> texturas;
    std::vector<Textura> pista;
    std::map<int, Textura> textIdentificables;
    Camara camara;

public:
    Renderizador(const char *titulo, int ancho, int altura, std::mutex &m);

    unsigned long agregarTextura(const std::string &archivo, Posicion* pos);

    void agregarTrecho(const std::string &archivo, Posicion* pos);

    void agregarTexto(const std::string &texto, Posicion *posicion);

    void borrarTextura(unsigned long idTextura);

    void imprimir(Uint32 tiempoMs);

    void limpiar();

    void copiarTodo();

    void configurarCamara(Posicion* posicion);

    virtual ~Renderizador();
};

#endif //OPENGLTEST_RENDERIZADOR_H
