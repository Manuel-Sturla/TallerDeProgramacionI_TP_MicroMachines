//
// Created by diego on 23/11/19.
//

#ifndef MENUQT20_MENU_H
#define MENUQT20_MENU_H


#include <QtWidgets/QStackedWidget>
#include "Inicio.h"
#include "CrearPartida.h"
#include "ElegirJugador.h"

class Menu {
private:
    ServidorProxy& servidor;
    QStackedWidget etapas;
    CrearPartida crearPartida;
    Lobby lobby;
    Inicio inicio;
    ElegirJugador elegirJugador;

public:
    explicit Menu(ServidorProxy &servidor, bool &esCpu);

    void ejecutarMenu();
};


#endif //MENUQT20_MENU_H
