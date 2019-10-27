

#include <bits/unique_ptr.h>
#include <iostream>
#include <zconf.h>
#include "InterpreteLua.h"
#include "ErrorLua.h"
#include "ParametrosLua/FlotanteLua.h"
#include "ParametrosLua/EnteroLua.h"
#include "ParametrosLua/CadenaLua.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
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
        lua_tostring(L,-1) + std::to_string(retorno), __LINE__, __FILE__);
    }
}
std::vector<std::unique_ptr<ParametroLua>>
InterpreteLua::ejecutarFuncion(const std::string &nombre, std::vector<std::string> &variables) {
    if (lua_getglobal(L, nombre.c_str()) != LUA_TFUNCTION){
        lua_pop(L,-1);
        throw ErrorLua("La funcion llamada", nombre,\
        "no existe o es de un tipo no llamable", __LINE__, __FILE__ );
    }
    for (std::string& var : variables){
        lua_getglobal(L, var.c_str());
    }
    return llamar(variables.size());
}
std::vector<std::unique_ptr<ParametroLua>> InterpreteLua::ejecutarFuncion(const std::string& nombre,\
    std::vector<std::unique_ptr<ParametroLua>>& parametros) {
    if (lua_getglobal(L, nombre.c_str()) != LUA_TFUNCTION){
        lua_pop(L,-1);
        throw ErrorLua("La funcion llamada", nombre,\
        "no existe o es de un tipo no llamable", __LINE__, __FILE__ );
    }
    for (std::unique_ptr<ParametroLua>& parametro : parametros){
        parametro->apilarAlStack(L);
    }
    return llamar(parametros.size());
}
std::vector<std::unique_ptr<ParametroLua>> InterpreteLua::llamar(size_t cantParametros){
    lua_call(L, cantParametros, LUA_MULTRET);
    size_t cantArgumentos = lua_gettop(L) - tope;
    std::vector<std::unique_ptr<ParametroLua>> retorno;
    for (size_t i = tope+1; i <= tope+cantArgumentos; i++){
        retorno.emplace_back(std::unique_ptr<ParametroLua>(obtenerElemento(i)));
    }
    //vacio los parametros de la pila
    lua_settop(L, tope);
    return retorno;
}
std::unique_ptr<ParametroLua> InterpreteLua::obtenerElemento(size_t pos) {
    if (lua_isinteger(L, pos)){
        return std::unique_ptr<ParametroLua>(new EnteroLua(lua_tonumber(L,pos)));
    }else if(lua_isnumber(L,pos)){
        return std::unique_ptr<ParametroLua>(new FlotanteLua(lua_tointeger(L, pos)));
    }else if(lua_isstring(L, pos)){
        return std::unique_ptr<ParametroLua>(new CadenaLua(lua_tostring(L,pos)));
    }
}

void InterpreteLua::agregarElementoTabla(const std::string& tabla,ParametroLua& clave, ParametroLua& valor) {
    const char* tabla_c = tabla.c_str();
    if(lua_getglobal(L, tabla_c) != LUA_TTABLE){
        lua_settop(L, tope);
        lua_newtable(L);
        lua_setglobal(L,tabla_c);
        lua_getglobal(L, tabla_c);
    }
    clave.apilarAlStack(L);
    valor.apilarAlStack(L);
    lua_settable(L,-3);
    lua_settop(L, tope);
}

std::vector<std::unique_ptr<ParametroLua>> InterpreteLua::ejecutarFuncion(const std::string &nombre) {
    std::vector<std::unique_ptr<ParametroLua>> aux;
    return ejecutarFuncion(nombre, aux);
}

std::unique_ptr<ParametroLua> InterpreteLua::obtenerElementoTabla(const std::string &tabla, ParametroLua& clave) {
    if(lua_getglobal(L, tabla.c_str()) != LUA_TTABLE){
        lua_settop(L, tope);
        throw ErrorLua("Error al buscar elemento de la tabla: ", tabla,\
        "no existe una variable global con ese nombre", __LINE__, __FILE__);
    }
    clave.apilarAlStack(L);
    lua_gettable(L, -2);
    std::unique_ptr<ParametroLua> ret = obtenerElemento(-1);
    lua_settop(L, tope);
    if (ret.get() == NULL){
        throw ErrorLua("Error al buscar elemento en la tabla: ", tabla, \
        "no existe una clave con el nombre indicado", __LINE__, __FILE__);
    }
    return ret;
}

void InterpreteLua::imprimirPila() {
        int i;
        int top = lua_gettop(L); /* depth of the stack */
        for (i = 1; i <= top; i++) { /* repeat for each level */
            int t = lua_type(L, i);
            switch (t) {
                case LUA_TSTRING: { /* strings */
                    printf("'%s'", lua_tostring(L, i));
                    break;
                }
                case LUA_TBOOLEAN: { /* Booleans */
                    printf(lua_toboolean(L, i) ? "true" : "false");
                    break;
                }
                case LUA_TNUMBER: { /* numbers */
                    printf("%g", lua_tonumber(L, i));
                    break;
                }
                default: { /* other values */
                    printf("%s", lua_typename(L, t));
                    break;
                }
            }
            printf(" "); /* put a separator */
        }
        printf("\n"); /* end the listing */
}




