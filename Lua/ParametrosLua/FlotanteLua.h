//
// Created by manfer on 24/10/19.
//

#ifndef LUATEST_FLOTANTELUA_H
#define LUATEST_FLOTANTELUA_H


#include "ParametroLua.h"

class FlotanteLua: public ParametroLua {
    float flotante;
public:
    explicit FlotanteLua(const float numero);

    void apilarAlStack(lua_State *L) override;

};


#endif //LUATEST_FLOTANTELUA_H
