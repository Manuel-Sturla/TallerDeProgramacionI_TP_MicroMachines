//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_RENDERIZADOR_H
#define OPENGLTEST_RENDERIZADOR_H

#include <SDL2/SDL_system.h>
#include <vector>
#include <map>
#include <SDL2/SDL_ttf.h>
#include "Ventana.h"
#include "Posicion.h"
#include "Textura.h"

class Renderizador {
private:
    std::mutex& m;
    SDL_Renderer* renderizador;
    Ventana ventana;
    std::map<std::string, Textura> autos;
    std::map<std::string, Textura> extras;
    std::map<std::string, Textura> otros;
    std::vector<Textura> pista;
    TTF_Font* fuente;
    Camara camara;

public:
    Renderizador(const char *titulo, int ancho, int altura, std::mutex &m);

    void agregarAuto(const std::string &archivo, Posicion *pos, std::string &id);

    void agregarExtra(const std::string &archivo, Posicion *pos, std::string &id);

    size_t agregarTrecho(const std::string &archivo, Posicion* pos);

    size_t agregarTexto(const std::string &texto, Posicion *posicion, std::string &id, Uint8 r, Uint8 g, Uint8 b);

    void agregarTextura(const std::string &archivo, Posicion *pos, std::string &id);

    void borrarExtra(const std::string& id);

    void imprimir(Uint32 tiempoMs);

    void limpiar();

    void copiarTodo();

    void configurarCamara(Posicion* posicion);

    ~Renderizador();

    void borrarTodo();

    void borrarAuto(const std::string& id);

    void borrarTexto(std::string& id);
};

#endif //OPENGLTEST_RENDERIZADOR_H
