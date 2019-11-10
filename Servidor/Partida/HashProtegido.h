//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_HASHPROTEGIDO_H
#define SERVIDOR_HASHPROTEGIDO_H


#include <mutex>
#include <map>
#include "Partida.h"

class HashProtegido {
    std::mutex mutex;
    std::map<std::string, std::shared_ptr<Partida>> partidas;
public:
    HashProtegido() = default;
    bool ubicar(const std::string& clave, Partida* partida);
    bool eliminar(const std::string& clave);
    std::shared_ptr<Partida> obtener(const std::string& clave);
    std::vector<std::string> obtenerClaves();
    bool contiene(const std::string& clave);
};


#endif //SERVIDOR_HASHPROTEGIDO_H
