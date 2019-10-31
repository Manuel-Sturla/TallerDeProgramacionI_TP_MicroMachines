//
// Created by diego on 22/10/19.
//

#ifndef OPENGLTEST_SERVIDOR_H
#define OPENGLTEST_SERVIDOR_H
#include <string>
#include <vector>

class Servidor {
private:
    int posX;
    int posY;
    int angulo;

public:
    Servidor(int posY, int posX);

    void enviar(const std::string& mensaje);

    std::vector<std::string> recibir();

    std::vector<std::string> iniciarPista();
};


#endif //OPENGLTEST_SERVIDOR_H
