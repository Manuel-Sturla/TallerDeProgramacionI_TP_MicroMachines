//
// Created by manfer on 24/10/19.
//

#include "CadenaLua.h"
#define TIPO "cadena"
CadenaLua::CadenaLua(const std::string &cadena) :
    ParametroLua(TIPO), cadena(cadena){
}

void CadenaLua::apilarAlStack(lua_State *L) {
    lua_pushlstring(L, cadena.c_str(), cadena.size());
}
