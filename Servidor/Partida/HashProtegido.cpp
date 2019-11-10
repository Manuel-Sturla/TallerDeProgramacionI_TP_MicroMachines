//
// Created by manfer on 10/11/19.
//

#include <shared_mutex>
#include "HashProtegido.h"

bool HashProtegido::ubicar(const std::string &clave, Partida *partida) {
    std::unique_lock<std::mutex> lock(mutex);
    return partidas.emplace(clave, partida).second;
}

bool HashProtegido::eliminar(const std::string &clave) {
    std::unique_lock<std::mutex> lock(mutex);
    return partidas.erase(clave) != 0;
}

std::shared_ptr<Partida> HashProtegido::obtener(const std::string &clave) {
    return partidas.at(clave);
}

std::vector<std::string> HashProtegido::obtenerClaves() {
    std::vector<std::string> claves;
    claves.reserve(partidas.size());
    std::unique_lock<std::mutex> lock(mutex);
    for(auto& partida : partidas){
        claves.push_back(partida.first);
    }
    return claves;
}

bool HashProtegido::contiene(const std::string& clave) {
    return partidas.find(clave) != partidas.end();
}
