//
// Created by manfer on 24/10/19.
//

#ifndef LUATEST_FLOTANTELUA_H
#define LUATEST_FLOTANTELUA_H


#include "ParametroLua.h"

class FlotanteLua: public ParametroLua {
    double flotante;
public:
    explicit FlotanteLua(const double numero);
    void apilarAlStack(lua_State *L) override;
    Retorno obtenerValor() override;
};


#endif //LUATEST_FLOTANTELUA_H
