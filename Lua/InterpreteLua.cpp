
//
// Created by manfer on 17/10/19.
//

#include "InterpreteLua.h"

InterpreteLua::InterpreteLua() {
    L = luaL_newstate();
    luaL_openlibs(L);
}

InterpreteLua::~InterpreteLua() {
    lua_close(L);
}
