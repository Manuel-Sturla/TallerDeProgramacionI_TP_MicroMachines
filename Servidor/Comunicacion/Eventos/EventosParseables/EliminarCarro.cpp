#include "EliminarCarro.h"
#include "../../Utilidades.h"

#define EVENTO_ELIMINAR_AUTO "eliminarAuto"

EliminarCarro::EliminarCarro(size_t idCarro) {
    std::vector<std::string> aux;
    aux.emplace_back(EVENTO_ELIMINAR_AUTO);
    aux.emplace_back(std::to_string(idCarro));
    parseo = unir(aux, SEPARADOR);
}

std::string EliminarCarro::obtenerParseado() {
    return parseo;
}
