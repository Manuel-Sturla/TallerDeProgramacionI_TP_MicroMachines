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
    void crearPartida(const std::string& nombre, const std::string& cantJugadores);
    std::vector<std::string> obtenerPartidas();
    std::vector<std::string> obtenerEventos();
    std::vector<std::string> obtenerMapa();
    void terminarConexion();
};


#endif //PROTOCOLO_SERVIDORPROXY_H

