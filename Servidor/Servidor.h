#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include <unordered_map>
#include <string>
#include <memory>
#include "Planos/PlanoDePista.h"
#include "../Protocolo/Socket/SocketPasivo.h"

class Servidor {
  private:
    std::unordered_map<std::string, PlanoDePista*> planosDePistas;
    SocketPasivo *socketPasivo;
    void levantarPistas();

  public:
    Servidor(SocketPasivo *unSocketPasivo);

    void run();

    void jugar();

    ~Servidor();

};

#endif
