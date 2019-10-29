//
// Created by manfer on 28/10/19.
//

#ifndef BIBLIOTECASLOCAS_CARRO_H
#define BIBLIOTECASLOCAS_CARRO_H


class Carro {
    float velMax;
public:
    Carro(float velocidad);
    void actualizarVelocidadMax(float velocidad);
    float obtenerVelicidadMax();
};


#endif //BIBLIOTECASLOCAS_CARRO_H
