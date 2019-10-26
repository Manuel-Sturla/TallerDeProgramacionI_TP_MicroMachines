
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
    size_t tope = 0;
    void imprimirPila();
    std::unique_ptr<ParametroLua> obtenerElemento(size_t pos);
public:
    InterpreteLua();
    InterpreteLua(const std::string& script);
    ~InterpreteLua();
    std::vector<std::unique_ptr<ParametroLua>> ejecutarFuncion(const std::string& nombre,\
    std::vector<std::unique_ptr<ParametroLua>>& parametros);
    std::vector<std::unique_ptr<ParametroLua>> ejecutarFuncion(const std::string& nombre);
    void agregarElementoTabla(const std::string& tabla, ParametroLua& clave, ParametroLua& valor);

    std::unique_ptr<ParametroLua> obtenerElementoTabla(const std::string &tabla, ParametroLua& clave);
};


#endif //LUATEST_INTERPRETELUA_H
