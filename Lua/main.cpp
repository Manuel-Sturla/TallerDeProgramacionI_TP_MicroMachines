#ifdef _cplusplus
    #include "lua.hpp"
#else
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
#endif

int main(){
    lua_State *L = luaL_newstate(); //Mi stack de variables esta vacio.
    luaL_openlibs(L);
    luaL_dostring(L, "print('Hola mundo')");
}