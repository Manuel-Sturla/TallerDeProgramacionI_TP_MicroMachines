

#include <bits/unique_ptr.h>
#include "InterpreteLua.h"
#include "ErrorLua.h"
#include "ParametrosLua/FlotanteLua.h"
#include "ParametrosLua/EnteroLua.h"
#include "ParametrosLua/CadenaLua.h"

InterpreteLua::InterpreteLua() {
    L = luaL_newstate();
    luaL_openlibs(L);
}

InterpreteLua::~InterpreteLua() {
    lua_close(L);
}

InterpreteLua::InterpreteLua(const std::string& script) : InterpreteLua(){
    int retorno = luaL_dofile(L, script.c_str());
    if (retorno != 0){
        throw ErrorLua("Error al ejecutar el archivo: ", script,\
        ".Retorno = " + std::to_string(retorno), __LINE__, __FILE__);
    }
}

std::vector<std::unique_ptr<ParametroLua>> InterpreteLua::ejecutar_funcion(const std::string nombre,\
std::vector<ParametroLua &>& parametros) {
    lua_getglobal(L, nombre.c_str());
    if (lua_isfunction(L,-1)){
        lua_pop(L,-1);
        throw ErrorLua("La funcion llamada", nombre,\
        "no existe o es de un tipo no llamable", __LINE__, __FILE__ );
    }
    size_t topePila = lua_gettop(L);
    for (auto parametro : parametros){
        parametro.apilarAlStack(L);
    }
    lua_call(L, parametros.size(), LUA_MULTRET);
    size_t cantArgumentos = topePila - lua_gettop(L);
    std::vector<std::unique_ptr<ParametroLua>> retorno;
    for (size_t i = topePila+1; i <= topePila+cantArgumentos; i++){
        std::unique_ptr<ParametroLua> parametroRetorno = obtenerElemento(i);
        retorno.push_back(parametroRetorno);
    }
    //vacio los parametros de la pila
    lua_settop(L, topePila);
    return retorno;
}

std::unique_ptr<ParametroLua> InterpreteLua::obtenerElemento(size_t pos) {
    if (lua_isnumber(L, pos)){
        return std::unique_ptr<ParametroLua>(new FlotanteLua(lua_tonumber(L,pos)));
    }else if(lua_isinteger(L,pos)){
        return std::unique_ptr<ParametroLua>(new EnteroLua(lua_tointeger(L, pos)));
    }else if(lua_isstring(L, pos)){
        return std::unique_ptr<ParametroLua>(new CadenaLua(lua_tostring(L,pos)));
    }
}
