//
// Created by diego on 22/10/19.
//

#include "ComandoAcelerar.h"

void ComandoAcelerar::ejecutar() {
    servidor.enviar("acelerar");
}
