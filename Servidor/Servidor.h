#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include <unordered_map>
#include <string>
#include <memory>
#include "Planos/PlanoDePista.h"

class Servidor {
  private:
    std::unordered_map<std::string, std::shared_ptr<PlanoDePista>> planosDePistas;
    void levantarPistas();

  public:
    Servidor();

    void jugar();

    ~Servidor();

};

#endif
