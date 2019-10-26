//
// Created by diego on 22/10/19.
//

#include "Renderizador.h"
#include "../Excepciones/ExcepcionConPos.h"

Renderizador::Renderizador(const char* titulo, int ancho, int altura) : ventana(titulo, ancho, altura) {
    renderizador = ventana.crearRenderizador(-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderizador == nullptr){
        throw ExcepcionConPos(__FILE__, __LINE__, "No pude crear el renderizador");
    }
}

void Renderizador::imprimir(Uint32 tiempoMs) {
    SDL_RenderPresent(renderizador);
    SDL_Delay(tiempoMs);
}

Renderizador::~Renderizador() {
    if(renderizador != nullptr){
        SDL_DestroyRenderer(renderizador);
    }
}

void Renderizador::agregarTextura(const std::string &archivo, Posicion& pos, int angulo, const std::string& nombre) {
    texturas.emplace(std::piecewise_construct, std::forward_as_tuple(nombre), std::forward_as_tuple(renderizador, archivo, pos, angulo));
}

void Renderizador::limpiar() {
    SDL_RenderClear(renderizador);
}

void Renderizador::mover(const std::string &nombre, int posX, int posY) {
    auto it = texturas.find(nombre);
    if(it == texturas.end()){
        throw ExcepcionConPos(__FILE__, __LINE__, "Intento actualizar textura no valida: "+nombre);
    }
    it->second.moverA(renderizador, posX, posY);
}

void Renderizador::copiar(const std::string &nombre) {
    auto it = texturas.find(nombre);
    if(it == texturas.end()){
        throw ExcepcionConPos(__FILE__, __LINE__, "Intento actualizar textura no valida: "+nombre);
    }
    it->second.copiar(renderizador);
}

void Renderizador::rotar(const std::string& nombre, int angulo) {
    auto it = texturas.find(nombre);
    if(it == texturas.end()){
        throw ExcepcionConPos(__FILE__, __LINE__, "Intento actualizar textura no valida: "+nombre);
    }
    it->second.rotar(renderizador, angulo);
}


