//
// Created by manfer on 26/11/19.
//

#include "EnviarCantJugadores.h"

EnviarCantJugadores::EnviarCantJugadores(size_t cant) : cantActualJugadores(cant){

}

std::string EnviarCantJugadores::obtenerParseado() {
    return std::to_string(cantActualJugadores);
}
