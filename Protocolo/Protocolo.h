//
// Created by manfer on 31/10/19.
//

#ifndef PROTOCOLO_PROTOCOLO_H
#define PROTOCOLO_PROTOCOLO_H


#include <SocketAmigo.h>
#include <vector>

class Protocolo {
    SocketAmigo socket; //Posiblemente luego no guarde una referencia
public:
    explicit Protocolo(SocketAmigo& socketAmigo);
    void enviar(std::vector<std::string> elementos);
    void enviar(const std::string &mensaje);
    std::string recibir();
};


#endif //PROTOCOLO_PROTOCOLO_H
