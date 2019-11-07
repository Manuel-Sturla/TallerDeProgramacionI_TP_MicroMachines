//
// Created by diego on 6/11/19.
//

#ifndef CLIENT_LOBBY_H
#define CLIENT_LOBBY_H


#include "ui_lobby.h"
#include "../Sockets/ServidorProxy.h"

class Lobby : public QWidget {
private:
    ServidorProxy& servidor;

public:
    Lobby(ServidorProxy &servidor);

    void conectar();

    void crearPartida();

    void copiarPistas(std::vector<std::string> &vector);

    void unirPartida();
};


#endif //CLIENT_LOBBY_H
