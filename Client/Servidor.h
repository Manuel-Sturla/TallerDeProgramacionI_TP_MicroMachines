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

public:
    Servidor(int posY, int posX);

    void enviar(const std::string& mensaje);

    std::vector<int> recibir();
};


#endif //OPENGLTEST_SERVIDOR_H
