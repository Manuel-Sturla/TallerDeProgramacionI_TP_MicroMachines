
#ifndef LUATEST_PARAMETROLUA_H
#define LUATEST_PARAMETROLUA_H


#include <string>
#include <lua.h>

class ParametroLua {
    std::string tipo;
public:
    //ParametroLua(const std::string cadena);
    //ParametroLua(const std::string cadena, size_t longitud);
    //ParametroLua(const int numero);
    //ParametroLua(const float numero);
    explicit ParametroLua(std::string tipo);
    //ParametroLua(const bool booleano);
    std::string obtenerTipo();
    virtual void apilarAlStack(lua_State* L) = 0;

};


#endif //LUATEST_PARAMETROLUA_H
