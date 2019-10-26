//
// Created by manfer on 24/10/19.
//

#ifndef LUATEST_ENTEROLUA_H
#define LUATEST_ENTEROLUA_H


#include "ParametroLua.h"


class EnteroLua: public ParametroLua {
    int entero;
public:
    explicit EnteroLua(int numero);
    void apilarAlStack(lua_State *L) override;

    Retorno obtenerValor() override;

};


#endif //LUATEST_ENTEROLUA_H
