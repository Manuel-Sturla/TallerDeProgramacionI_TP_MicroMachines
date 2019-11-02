//
// Created by manfer on 2/11/19.
//

#ifndef PROTOCOLO_ENVIARPOSICIONES_H
#define PROTOCOLO_ENVIARPOSICIONES_H


#include "Comando.h"
#include "../Protocolo.h"

class EnviarPosiciones: public Comando {
    Protocolo& protocolo;
    std::vector<std::string>& extras; //ESTO LUEGO SERA ALGUN CONTENEDOR DE LOS OBJETOS
    //opcion1: std::vector<Modificador> extras;
    //para los autos: std::vector<Carro> autos;  o pueden ser referencias (Carro&)
    std::vector<std::string>& autos; //ESTO LUEGO SERA ALGUN CONTENEDOR DE LOS OBJETOS
public:
    EnviarPosiciones(Protocolo& protocolo, std::vector<std::string>& extras,\
    std::vector<std::string>& autos);

    void ejecutar() override;
};


#endif //PROTOCOLO_ENVIARPOSICIONES_H
