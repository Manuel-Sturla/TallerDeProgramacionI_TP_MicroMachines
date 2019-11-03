#include "AgregarMovimiento.h"

AgregarMovimiento::AgregarMovimiento(Protocolo &protocolo): protocolo(protocolo), movimientos(std::queue<std::string> {}){
}

void AgregarMovimiento::ejecutar() {
    std::string comando = protocolo.recibir();
    movimientos.push(comando);
}
