//
// Created by manfer on 2/11/19.
//

#ifndef PROTOCOLO_ENVIARMAPA_H
#define PROTOCOLO_ENVIARMAPA_H


#include "../Protocolo.h"
#include "Comando.h"

class EnviarMapa: public Comando {
    Protocolo& protocolo;
    //Este sería una referencia al mapa de verdad? y despues se parsea
    std::vector<std::string> posMapa = {"Asfalto, 2-1", "..."};
public:
    EnviarMapa(Protocolo& protocolo); //Falta que reciba el mapa
    void ejecutar() override;
};


#endif //PROTOCOLO_ENVIARMAPA_H
