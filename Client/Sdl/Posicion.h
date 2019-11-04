//
// Created by diego on 24/10/19.
//

#ifndef OPENGLTEST_POSICION_H
#define OPENGLTEST_POSICION_H

#include <SDL2/SDL_rect.h>
#include <mutex>
#include <vector>

typedef struct{
  float x;
  float y;
  float w;
  float h;
}pos_t;

class Posicion {
private:
    pos_t posicion;
    int angulo;
    std::mutex mutex;

public:
    Posicion(float posX, float posY, float ancho, float altura, int angulo);

    pos_t getPosicion();

    void moverA(float posX, float posY);

    void rotar(int angulo);

    int getAngulo();

//    bool estaEnRango(int ancho, int largo);
};


#endif //OPENGLTEST_POSICION_H
