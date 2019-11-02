//
// Created by diego on 2/11/19.
//

#include <iostream>
#include "HiloMenu.h"

HiloMenu::HiloMenu(ServidorProxy &servidor, bool &enMenu) : enMenu(enMenu), servidor(servidor){
}

void HiloMenu::run() {
    while(enMenu){
        enMenu = !servidor.creePartida();
    }
}
