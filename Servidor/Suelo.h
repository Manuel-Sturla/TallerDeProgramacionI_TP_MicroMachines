#ifndef _SUELO_H_
#define _SUELO_H_

#include "Interactuable.h"

class Suelo: public Interactuable {
  public:
    Suelo();

    bool esValido();

    ~Suelo();
};

#endif
