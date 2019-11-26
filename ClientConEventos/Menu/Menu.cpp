//
// Created by diego on 23/11/19.
//

#include "Menu.h"
#include <iostream>

Menu::Menu(ServidorProxy &servidor, bool &esCpu)
        : servidor(servidor), crearPartida(etapas, servidor),\
        lobby(etapas, servidor, crearPartida), inicio(&etapas, servidor, lobby),\
  elegirJugador(etapas, esCpu) {
    etapas.addWidget(&inicio);
    etapas.addWidget(&elegirJugador);
    etapas.addWidget(&lobby);
    etapas.addWidget(&crearPartida);
	etapas.setFixedSize(500,500);
}

void Menu::ejecutarMenu() {
	    etapas.show();
}
