#ifndef _INTERACTUABLE_H_
#define _INTERACTUABLE_H_

#include <string>

class Interactuable {
  protected:
    std::string id;
  public:
    virtual std::string darId() = 0;

    virtual void interactuar() = 0;
};

#endif
