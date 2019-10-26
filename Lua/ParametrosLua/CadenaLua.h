//
// Created by manfer on 24/10/19.
//

#ifndef LUATEST_CADENALUA_H
#define LUATEST_CADENALUA_H


#include "ParametroLua.h"

class CadenaLua: public ParametroLua {
    std::string cadena;
public:
    explicit CadenaLua(const std::string& cadena);
    void apilarAlStack(lua_State *L) override;
    Retorno obtenerValor() override;
};


#endif //LUATEST_CADENALUA_H
