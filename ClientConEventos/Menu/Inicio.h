//
// Created by diego on 6/11/19.
//

#ifndef CLIENT_INICIO_H
#define CLIENT_INICIO_H


#include <string>
#include <QtWidgets/QWidget>
#include <QtWidgets/QStackedWidget>
#include "ui_inicio.h"
#include "Lobby.h"

class Inicio : public QWidget {
private:
    QStackedWidget* menu;
    ServidorProxy& servidor;
    Lobby& lobby;

public:
    explicit Inicio(QStackedWidget *menu, ServidorProxy &servidor,Lobby& lobby, QWidget *parent = nullptr);

    void leerPantalla();

    void conectar();
};


#endif //CLIENT_INICIO_H
