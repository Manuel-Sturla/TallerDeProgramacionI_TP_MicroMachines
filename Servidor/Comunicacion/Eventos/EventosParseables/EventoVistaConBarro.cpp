#include "EventoVistaConBarro.h"
#include "../../Utilidades.h"

#define EVENTO_VISTA_CON_BARRO "visibilidadReducida"

EventoVistaConBarro::EventoVistaConBarro(Carro &carro) {
    std::vector<std::string> mensaje;
    mensaje.emplace_back(EVENTO_VISTA_CON_BARRO);
    carro.empaquetarId(&mensaje);
    parseado =  unir(mensaje, SEPARADOR);
}

std::string EventoVistaConBarro::obtenerParseado() {
    return parseado;
}
