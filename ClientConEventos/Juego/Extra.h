//
// Created by diego on 9/11/19.
//

#ifndef CLIENT_EXTRA_H
#define CLIENT_EXTRA_H


#include "Desplazable.h"

class Extra : public Desplazable {
public:
    Extra(Renderizador &renderizador, int tam, const std::string& tipo, std::string id);

    void mover(float posX, float posY, int angulo) override;

    void morir() override;

    void modificar(std::string &mensaje) override;

    void eliminar() override;
};


#endif //CLIENT_EXTRA_H
