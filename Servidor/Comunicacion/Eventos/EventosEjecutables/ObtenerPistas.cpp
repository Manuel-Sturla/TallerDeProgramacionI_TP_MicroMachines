//
// Created by manfer on 25/11/19.
//

#include "ObtenerPistas.h"
#include "../../Utilidades.h"
#include "../EventosParseables/EnviarPistas.h"

ObtenerPistas::ObtenerPistas(ConfiguracionServidor &pistas) : configuracionServidor(pistas){
}

void ObtenerPistas::ejecutar(ClienteProxy &cliente, std::vector<std::string> argumentos) {
    std::vector<std::string> aux = configuracionServidor.obtenerNombresPlanos();
    cliente.encolarEvento(new EnviarPistas(aux));
}

