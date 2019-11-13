//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "ComandoAcelerar.h"

void ComandoAcelerar::ejecutar() {
    std::cout<<"Acelere\n";
    servidor.ejecutarMovimiento("acelerar");
    std::cout<<"Deje de acelerar\n";
}
