//
// Created by diego on 6/11/19.
//

#ifndef CLIENT_LOBBY_H
#define CLIENT_LOBBY_H


#include "ui_lobby.h"
#include "../Sockets/ServidorProxy.h"
#include "CrearPartida.h"
#include <QtWidgets/QStackedWidget>

class Lobby : public QWidget {
private:
    ServidorProxy& servidor;
    QStackedWidget& menu;
    CrearPartida& crear;

public:
    Lobby(QStackedWidget &menu, ServidorProxy &servidor, CrearPartida &crear, QWidget *parent = nullptr);

    void conectar();

    void crearPartida();

    void copiarPartidas();

    void unirPartida();
};


#endif //CLIENT_LOBBY_H
