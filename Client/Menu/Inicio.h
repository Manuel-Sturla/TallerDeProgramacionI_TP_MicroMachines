//
// Created by diego on 6/11/19.
//

#ifndef CLIENT_INICIO_H
#define CLIENT_INICIO_H


#include <string>
#include <QtWidgets/QWidget>
#include "ui_inicio.h"

class Inicio : public QWidget {
private:
    std::string& host;
    std::string& servicio;

public:
    Inicio(std::string &host, std::string& servicio, QWidget* parent = 0);

    void leerPantalla();

    void conectar();
};


#endif //CLIENT_INICIO_H
