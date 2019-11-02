//
// Created by manfer on 31/10/19.
//

#ifndef PROTOCOLO_SERVIDORPROXY_H
#define PROTOCOLO_SERVIDORPROXY_H


#include <string>
#include <vector>
#include "Protocolo.h"

class ServidorProxy {
    Protocolo protocolo;
public:
    ServidorProxy(const std::string& host, const std::string& servicio);
    void ejecutarMovimiento(const std::string& comando);
    void elegirPartida(const std::string& nombre);
    void crearPartida(const std::string& nombre, const int& cantJugadores);
    bool creePartida();
    std::vector<std::string> obtenerPartidas();
    void obtenerPosiciones(std::vector<std::string> &extras, std::vector<std::string> &autos);
    std::vector<std::string> obtenerMapa();
};


#endif //PROTOCOLO_SERVIDORPROXY_H

