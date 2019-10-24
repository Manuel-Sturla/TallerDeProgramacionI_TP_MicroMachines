//
// Created by manfer on 24/10/19.
//

#include "FlotanteLua.h"
#define TIPO "flotante"

FlotanteLua::FlotanteLua(const float numero):
    ParametroLua(TIPO), flotante(numero) {
}

void FlotanteLua::apilarAlStack(lua_State *L) {
    lua_pushnumber(L, flotante);
}
