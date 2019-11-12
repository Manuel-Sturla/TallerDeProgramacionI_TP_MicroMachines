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

public:
    Posicion(float posX, float posY, float ancho, float altura, int angulo);

    pos_t getPosicion();

    void moverA(float posX, float posY);

    void rotar(int angulo);

    int getAngulo();
};


#endif //OPENGLTEST_POSICION_H
