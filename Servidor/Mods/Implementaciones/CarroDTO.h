//
// Created by manfer on 20/11/19.
//

#ifndef SERVIDOR_CARRODTO_H
#define SERVIDOR_CARRODTO_H


typedef struct CarroDTO{
    const char* idConductor;
    int vida;
    bool visibilidadReducida;
    int duracionBarro;
    float velocidadMax;
    bool boost;
    float agarreBase;
    bool agarreReducido;
    int duracionAgarreReducido;
    //Podria tener el numero de vueltas
    float anguloDeGiro;
    float coeficienteDeRozamiento;
}CarroDTO_t;
#endif //SERVIDOR_CARRODTO_H
