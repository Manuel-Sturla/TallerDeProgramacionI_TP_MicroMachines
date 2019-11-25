#ifndef _CONFIGURACIONSERVIDOR_H_
#define _CONFIGURACIONSERVIDOR_H_

#include <unordered_map>
#include <string>
#include "Planos/PlanoDePista.h"
#include "Planos/PlanoDeCarro.h"
#include "yaml-cpp/node/node.h"
#include "Mods/Mod.h"

class ConfiguracionServidor {
private:
    std::unordered_map<std::string, PlanoDePista*> planosDePistas;
    std::unordered_map<std::string, PlanoDeCarro*> planosDeCarros;
    std::vector<std::unique_ptr<Mod>> mods;


    void levantarPistas();
    void levantarCarros();
    void levantarMods();
public:

    ConfiguracionServidor();

    PlanoDePista* darPlanoDePista(std::string planoBuscado);
    PlanoDeCarro* darPlanoDeCarro(std::string planoBuscado);
    std::vector<std::string> obtenerNombresPlanos();
    std::vector<std::string> obtenerNombresCarros();
    std::vector<std::unique_ptr<Mod>>& obtenerMods();

    ~ConfiguracionServidor();
};


#endif