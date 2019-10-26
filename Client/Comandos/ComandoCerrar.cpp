//
// Created by diego on 24/10/19.
//

#include "ComandoCerrar.h"

void ComandoCerrar::ejecutar() {
    servidor.enviar("cerrar");
}
