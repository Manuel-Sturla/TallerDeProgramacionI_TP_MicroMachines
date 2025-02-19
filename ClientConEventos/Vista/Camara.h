//
// Created by diego on 29/10/19.
//

#ifndef OPENGLTEST_CAMARA_H
#define OPENGLTEST_CAMARA_H


#include "../Sdl/Posicion.h"

class Camara {
private:
    Posicion* posAuto;
    int anchoPantalla;
    int alturaPantalla;
    int aumento;
    void amplificarValores(pos_t &pos);

public:
    explicit Camara(int anchoPantalla, int alturaPantalla, int aumento);

    void setAuto(Posicion *pos);

    SDL_Rect obtenerPosImpresion(pos_t posTextura);

    int obtenerAngulo(int angulo);

    bool estaEnRango(pos_t posTextura);
};


#endif //OPENGLTEST_CAMARA_H
