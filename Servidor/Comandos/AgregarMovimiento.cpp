#include "AgregarMovimiento.h"

AgregarMovimiento::AgregarMovimiento(Protocolo &protocolo): protocolo(protocolo){
}

void AgregarMovimiento::ejecutar() {
    std::string comando = protocolo.recibir();
    movimientos.push(comando);
}
