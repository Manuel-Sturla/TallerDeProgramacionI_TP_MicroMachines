//
// Created by diego on 22/10/19.
//

#include "ComandoIzquierda.h"

void ComandoIzquierda::ejecutar() {
    servidor.enviar("doblar izquierda");
}
