#ifndef _CONFIGURACIONSERVIDOR_H_
#define _CONFIGURACIONSERVIDOR_H_

#include <unordered_map>
#include <string>
#include "Planos/PlanoDePista.h"
#include "Planos/PlanoDeCarro.h"

class ConfiguracionServidor {
private:
    std::unordered_map<std::string, PlanoDePista*> planosDePistas;
    std::unordered_map<std::string, PlanoDeCarro*> planosDeCarros;

    void levantarPistas();
    void levantarCarros();
public:
    ConfiguracionServidor();

    PlanoDePista* darPlanoDePista(std::string planoBuscado);

    PlanoDeCarro* darPlanoDeCarro(std::string planoBuscado);

    ~ConfiguracionServidor();
};


#endif