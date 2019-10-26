//
// Created by manfer on 24/10/19.
//

#include "FlotanteLua.h"
#define TIPO "flotante"

FlotanteLua::FlotanteLua(const double numero):
    ParametroLua(TIPO), flotante(numero) {
}

void FlotanteLua::apilarAlStack(lua_State *L) {
    lua_pushnumber(L, flotante);
}

Retorno FlotanteLua::obtenerValor() {
    Retorno ret;
    ret.flotante = flotante;
    return ret;
}
