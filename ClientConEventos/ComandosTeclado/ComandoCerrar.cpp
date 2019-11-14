//
// Created by diego on 24/10/19.
//

#include <iostream>
#include "ComandoCerrar.h"

void ComandoCerrar::ejecutar() {
    servidor.terminarConexion();
}
