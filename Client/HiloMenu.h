//
// Created by diego on 2/11/19.
//

#ifndef OPENGLTEST_HILOMENU_H
#define OPENGLTEST_HILOMENU_H


#include "Sockets/ServidorProxy.h"
#include "Hilo.h"

class HiloMenu : public Hilo {
private:
    ServidorProxy& servidor;
    bool& enMenu;

public:
    HiloMenu(ServidorProxy& servidor, bool& enMenu);

    void run() override;
};


#endif //OPENGLTEST_HILOMENU_H
