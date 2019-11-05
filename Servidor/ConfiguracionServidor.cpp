#include <fstream>
#include "ConfiguracionServidor.h"

ConfiguracionServidor::ConfiguracionServidor() {
    levantarPistas();
    levantarCarros();
}

void ConfiguracionServidor::levantarPistas() {
    std::ifstream pistas("Pistas.txt", std::ifstream::in);
    std::string linea;
    while (!pistas.eof()) {
        getline(pistas, linea);
        if (linea == "Nueva Pista") {
            std::string nombreDePista;
            getline(pistas, nombreDePista);
            planosDePistas.emplace(nombreDePista, new PlanoDePista());
            getline(pistas, linea);
            while (linea != "Fin Pista") {
                planosDePistas[nombreDePista] -> agregarSuelo(linea);
                getline(pistas, linea);
            }
        }
    }
}

ConfiguracionServidor::~ConfiguracionServidor() {
    std::unordered_map<std::string, PlanoDePista*>::iterator itPistas;
    for (itPistas = planosDePistas.begin(); itPistas != planosDePistas.end(); itPistas++) {
        delete itPistas -> second;
    }
    std::unordered_map<std::string, PlanoDeCarro*>::iterator itCarros;
    for (itCarros = planosDeCarros.begin(); itCarros != planosDeCarros.end(); itCarros++) {
        delete itCarros -> second;
    }
}

void ConfiguracionServidor::levantarCarros() {
    std::ifstream carros("Carros.txt", std::ifstream::in);
    std::string linea;
    while (!carros.eof()) {
        getline(carros, linea);
        if (linea == "Nuevo Carro") {
            std::string nombreDeCarro;
            getline(carros, nombreDeCarro);
            std::cout << nombreDeCarro << std::endl;
            getline(carros, linea);
            planosDeCarros.emplace(nombreDeCarro, new PlanoDeCarro(linea));
        }
    }
}

PlanoDePista *ConfiguracionServidor::darPlanoDePista(std::string planoBuscado) {
    return planosDePistas[planoBuscado];
}

PlanoDeCarro *ConfiguracionServidor::darPlanoDeCarro(std::string planoBuscado) {
    return planosDeCarros[planoBuscado];
}
