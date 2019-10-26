#ifndef _ASFALTO_H_
#define _ASFALTO_H_

#include "Material.h"

class Asfalto: public Material {
  public:
    Asfalto();

    std::string darId();

    void interactuar();

    ~Asfalto();

};


#endif
