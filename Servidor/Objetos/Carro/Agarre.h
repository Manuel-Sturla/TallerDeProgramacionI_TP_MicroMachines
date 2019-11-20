#ifndef _AGARRE_H_
#define _AGARRE_H_


#include <Box2D/Dynamics/b2Body.h>
#include "../../Mods/Implementaciones/CarroDTO.h"

class Agarre {
  private:
    float agarreBase;
    bool agarreReducido;
    int duracion;

    void actualizarAgarreReducido();
  public:
    Agarre(float agarre);

    void actualizar(b2Body& cuerpo);

    void reducirAgarre();

    ~Agarre();

    void obtenerDatos(CarroDTO &dto);

    void actualizarDatos(CarroDTO_t &dto);
};


#endif
