//
// Created by manfer on 2/11/19.
//

#include "AgregarMovimiento.h"

AgregarMovimiento::AgregarMovimiento(Protocolo &protocolo): protocolo(protocolo){
}

void AgregarMovimiento::ejecutar() {
    std::string comando = protocolo.recibir();
    movimientos.push(comando);
}
