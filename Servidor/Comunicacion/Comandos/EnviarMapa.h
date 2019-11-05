#ifndef PROTOCOLO_ENVIARMAPA_H
#define PROTOCOLO_ENVIARMAPA_H


#include "../Protocolo.h"
#include "Comando.h"

class EnviarMapa: public Comando {
    Protocolo& protocolo;
    //Este sería una referencia al pista de verdad? y despues se parsea
    std::vector<std::string>& posMapa;
public:
    EnviarMapa(Protocolo& protocolo, std::vector<std::string>& mapa); //Falta que reciba el pista
    void ejecutar() override;

};

#endif
