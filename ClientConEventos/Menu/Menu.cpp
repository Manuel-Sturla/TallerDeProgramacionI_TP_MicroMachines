//
// Created by diego on 23/11/19.
//

#include "Menu.h"
#include <iostream>

Menu::Menu(ServidorProxy &servidor) : servidor(servidor), lobby(etapas, servidor), inicio(&etapas, servidor, lobby),\
 crearPartida(etapas, servidor) {
    etapas.addWidget(&inicio);
    etapas.addWidget(&lobby);
    etapas.addWidget(&crearPartida);
	etapas.setFixedSize(700,400);
}

void Menu::ejecutarMenu() {
	    etapas.show();
}
