//
// Created by manfer on 5/11/19.
//

#include "PartidaLlenaExcepcion.h"

PartidaLlenaExcepcion::PartidaLlenaExcepcion(const std::string &mensaje,
                                             int linea):
        runtime_error(mensaje + ". En: " + std::to_string(linea)) {
}