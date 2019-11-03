//
// Created by manfer on 31/10/19.
//

#ifndef PROTOCOLO_PROTOCOLO_H
#define PROTOCOLO_PROTOCOLO_H


#include "SocketAmigo.h"
#include <vector>
#include <string>

class Protocolo {
    SocketAmigo socket;
public:
    explicit Protocolo(SocketAmigo socketAmigo);
    Protocolo(Protocolo&& otro) noexcept;
    Protocolo& operator=(Protocolo&& otro);
    void enviar(const std::string &mensaje);
    std::string recibir();

    void terminarConexion();
};

#endif
