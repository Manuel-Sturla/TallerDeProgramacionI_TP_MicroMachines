
#ifndef LUATEST_PARAMETROLUA_H
#define LUATEST_PARAMETROLUA_H


#include <string>
#include <lua.h>

class ParametroLua {
    std::string tipo;
public:
    explicit ParametroLua(std::string tipo);
    std::string obtenerTipo();
    virtual void apilarAlStack(lua_State* L) = 0;
    virtual struct Retorno obtenerValor() = 0;
};

struct Retorno{
    std::string cadena;
    double flotante;
    int entero;
};

#endif //LUATEST_PARAMETROLUA_H
