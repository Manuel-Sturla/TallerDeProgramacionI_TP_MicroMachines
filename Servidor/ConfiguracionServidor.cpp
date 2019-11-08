#include <fstream>
#include "ConfiguracionServidor.h"
#include "ServidorException.h"
#include "yaml-cpp/yaml.h"
#include "yaml-cpp/node/node.h"

ConfiguracionServidor::ConfiguracionServidor() {
    levantarPistas();
    levantarCarros();
}

void ConfiguracionServidor::levantarPistas() {
    YAML::Node configuracion = YAML::LoadFile("../pistas.yaml");
    //lanzar excepcion si no logro abrir el arhivo
    for (unsigned i = 0; i < configuracion.size(); i++) {
        std::string nombre = configuracion[i]["nombre"].as<std::string>();
        planosDePistas.emplace(nombre, new PlanoDePista());
        YAML::Node rectas = configuracion[i]["rectas"];
        for (auto &&rectasInfo : rectas) {
            std::string material = rectasInfo["material"].as<std::string>();
            int x = rectasInfo["x"].as<int>();
            int y = rectasInfo["y"].as<int>();
            int tipo = rectasInfo["tipo"].as<int>();
            planosDePistas[nombre] -> agregarRecta(material, x, y, tipo);
        }
        YAML::Node curvas = configuracion[i]["curvas"];
        for (auto &&curvasInfo : curvas) {
            int x = curvasInfo["x"].as<int>();
            int y = curvasInfo["y"].as<int>();
            int tipo = curvasInfo["tipo"].as<int>();
            planosDePistas[nombre] -> agregarCurva(x, y, tipo);
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
    YAML::Node configuracion = YAML::LoadFile("../configuracion.yaml");
    YAML::Node autos = configuracion["carros"];
    //Tirar excepcion si el archivo no se abrio
    for (auto &&autoInfo : autos) {
        std::string nombreDeCarro = autoInfo["nombre"].as<std::string>();
        int velocidadMax = autoInfo["velocidad_max"].as<int>();
        float32 anguloDeGiro = autoInfo["angulo_de_giro"].as<float32 >();
        int agarre = autoInfo ["agarre"].as<int>();
        std::cout << nombreDeCarro << std::endl;
        planosDeCarros.emplace(nombreDeCarro, new PlanoDeCarro(velocidadMax, anguloDeGiro, agarre));
    }
}

PlanoDePista *ConfiguracionServidor::darPlanoDePista(std::string planoBuscado) {
    return planosDePistas[planoBuscado];
}

PlanoDeCarro *ConfiguracionServidor::darPlanoDeCarro(std::string planoBuscado) {
    return planosDeCarros[planoBuscado];
}
