//
// Created by manfer on 24/10/19.
//

#include "EnteroLua.h"

EnteroLua::EnteroLua(int num) : ParametroLua("entero"),
    entero(num){
}

void EnteroLua::apilarAlStack(lua_State *L) {
    lua_pushinteger(L, entero);
}
