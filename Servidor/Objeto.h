#ifndef _OBJETO_H_
#define _OBJETO_H_

#include <vector>
#include <string>
#include <Box2D/Dynamics/b2Body.h>

class Objeto {
  protected:
    std::string id;
    b2Body *cuerpo;

    void empaquetarPosicion(std::vector<std::string> *destino);
    void empaquetarAngulo(std::vector<std::string> *destino);
  public:
    virtual std::string darId() = 0;

    virtual bool esValido() = 0;

    virtual void empaquetar(std::vector<std::string> *destino) = 0;


};

#endif
