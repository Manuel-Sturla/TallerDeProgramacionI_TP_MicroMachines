//
// Created by manfer on 17/10/19.
//

#ifndef LUATEST_INTERPRETELUA_H
#define LUATEST_INTERPRETELUA_H
#ifdef _cplusplus
    #include "lua.hpp"
#else
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
#endif
class InterpreteLua {
    lua_State* L;
public:
    InterpreteLua();
    ~InterpreteLua();
    //Recibir el nobre del script a ejecutar
    //ejecutar funcion.
};


#endif //LUATEST_INTERPRETELUA_H
