//
// Created by diego on 23/11/19.
//

#ifndef MENUQT20_MENU_H
#define MENUQT20_MENU_H


#include <QtWidgets/QStackedWidget>
#include "Inicio.h"
#include "CrearPartida.h"

class Menu {
private:
    ServidorProxy& servidor;
    QStackedWidget etapas;
    Lobby lobby;
    Inicio inicio;
    CrearPartida crearPartida;

public:
    explicit Menu(ServidorProxy &servidor);

    void ejecutarMenu();
};


#endif //MENUQT20_MENU_H
