//
// Created by manfer on 24/10/19.
//

#include "ParametroLua.h"


ParametroLua::ParametroLua(std::string tipo) : tipo(tipo) {

}

std::string ParametroLua::obtenerTipo() {
    return tipo;
}
