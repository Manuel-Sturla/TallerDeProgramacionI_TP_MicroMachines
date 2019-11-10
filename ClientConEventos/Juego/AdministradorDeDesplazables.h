//
// Created by diego on 9/11/19.
//

#ifndef CLIENT_ADMINISTRADORDEDESPLAZABLES_H
#define CLIENT_ADMINISTRADORDEDESPLAZABLES_H


#include <map>
#include "Desplazable.h"

class AdministradorDeDesplazables {
private:
    Renderizador& renderizador;
    std::map<std::string, Desplazable*> desplazables;

    void ejecutarMorir(std::vector<std::string> &eventos);
    void ejecutarPosicionarExtra(std::vector<std::string> &eventos);
    void ejecutarModificar(std::vector<std::string> &eventos);
    void ejecutarPosicionarAuto(std::vector<std::string> &vector);

public:
    explicit AdministradorDeDesplazables(Renderizador& renderizador);

    void ejecutarEventos(std::vector<std::string>& eventos);

    void setCamara(Camara &camara);
};


#endif //CLIENT_ADMINISTRADORDEDESPLAZABLES_H
