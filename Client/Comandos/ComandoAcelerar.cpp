//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "ComandoAcelerar.h"

void ComandoAcelerar::ejecutar() {
    std::cout << "Ejecute el comando acelerar" << std::endl;
    servidor.ejecutarMovimiento("acelerar");
}
