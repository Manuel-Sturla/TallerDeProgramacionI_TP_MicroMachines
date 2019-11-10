//
// Created by diego on 22/10/19.
//

#include "ComandoFrenar.h"

void ComandoFrenar::ejecutar() {
    servidor.ejecutarMovimiento("frenar");
}
