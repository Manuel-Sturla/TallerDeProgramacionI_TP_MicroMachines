
#ifndef SERVIDOR_ENVIARMAPA_H
#define SERVIDOR_ENVIARMAPA_H


#include <map>
#include "Comando.h"
#include "../../Partida/Partida.h"

class EnviarMapa: public Comando {
    std::map<std::string, std::shared_ptr<Partida>>& partidas;
public:
    void ejecutar(ClienteProxy &cliente) override;

    explicit EnviarMapa(std::map<std::string, std::shared_ptr<Partida>>& partidas);

};


#endif //SERVIDOR_ENVIARMAPA_H
