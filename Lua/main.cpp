#ifdef _cplusplus
    #include "lua.hpp"
#else

#include <iostream>
#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
#include "ParametrosLua/ParametroLua.h"
#include "ParametrosLua/EnteroLua.h"

#endif

int main(){
    lua_State *L = luaL_newstate(); //Mi stack de variables esta vacio.
    luaL_openlibs(L);
    luaL_dostring(L, "print('Hola mundo')");
    EnteroLua enteroLua(3);
    ParametroLua& parametroLua = enteroLua;
    std::cout << parametroLua.obtenerTipo() << std::endl;
    parametroLua.apilarAlStack(L);
}