//
// Created by manfer on 2/11/19.
//

#ifndef PROTOCOLO_PARTIDA_H
#define PROTOCOLO_PARTIDA_H


#include <string>
#include <vector>

class Partida {
    std::vector<std::string> extras = {"Caja de salud", "La mama de diego", "Y que se yo que mas"};
    std::vector<std::string> autos = {"Triciclo", "patineta", "Fitito"};
public:
    Partida() = default;
    std::vector<std::string>& obtenerExtras(){
        return extras;
    }
    std::vector<std::string>& obtenerAutos(){
        return autos;
    }
};


#endif //PROTOCOLO_PARTIDA_H
