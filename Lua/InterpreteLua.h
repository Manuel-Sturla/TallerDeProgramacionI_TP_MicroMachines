
#ifndef LUATEST_INTERPRETELUA_H
#define LUATEST_INTERPRETELUA_H
#ifdef _cplusplus
    #include "lua.hpp"
#else

#include <string>
#include <vector>
#include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
#endif

#include "ParametrosLua/ParametroLua.h"
#include <memory>
class InterpreteLua {
    lua_State* L;
public:
    InterpreteLua();
    InterpreteLua(const std::string& script);
    ~InterpreteLua();
    std::vector<std::unique_ptr<ParametroLua>> ejecutar_funcion(const std::string nombre,\
    std::vector<std::unique_ptr<ParametroLua>>& parametros);
    std::unique_ptr<ParametroLua> obtenerElemento(size_t pos);
};


#endif //LUATEST_INTERPRETELUA_H
