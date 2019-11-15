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
            int numero = rectasInfo["numero"].as<int>();
            planosDePistas[nombre] -> agregarRecta(material, x, y, tipo, numero);
        }
        YAML::Node curvas = configuracion[i]["curvas"];
        for (auto &&curvasInfo : curvas) {
            int x = curvasInfo["x"].as<int>();
            int y = curvasInfo["y"].as<int>();
            int tipo = curvasInfo["tipo"].as<int>();
            int numero = curvasInfo["numero"].as<int>();
            planosDePistas[nombre] -> agregarCurva(x, y, tipo, numero);
        }
        YAML::Node posicionesInicio = configuracion[i]["posicionesInicio"];
        for (auto &&posicionesInfo : posicionesInicio) {
            int x = posicionesInfo["x"].as<int>();
            int y = posicionesInfo["y"].as<int>();
            planosDePistas[nombre] -> agregarPosicionDeInicio(x, y);
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
        int velocidadMax = autoInfo["velocidad_max"].as<float32 >();
        float32 aceleracion = autoInfo["aceleracion"].as<float32 >();
        float32 anguloDeGiro = autoInfo["angulo_de_giro"].as<float32 >();
        int agarre = autoInfo ["agarre"].as<float32>();
        planosDeCarros.emplace(nombreDeCarro, new PlanoDeCarro(velocidadMax, aceleracion, anguloDeGiro, agarre));
    }
}

PlanoDePista *ConfiguracionServidor::darPlanoDePista(std::string planoBuscado) {
    return planosDePistas[planoBuscado];
}

PlanoDeCarro *ConfiguracionServidor::darPlanoDeCarro(std::string planoBuscado) {
    return planosDeCarros[planoBuscado];
}

std::vector<std::string> ConfiguracionServidor::obtenerNombresPlanos() {
    std::vector<std::string> nombres;
    for (auto it = planosDePistas.begin(); it != planosDePistas.end(); it ++){
        nombres.push_back(it->first);
    }
    return nombres;
}

std::vector<std::string> ConfiguracionServidor::obtenerNombresCarros() {
    std::vector<std::string> nombres;
    for (auto it = planosDePistas.begin(); it != planosDePistas.end(); it ++){
        nombres.push_back(it->first);
    }
    return nombres;
}
