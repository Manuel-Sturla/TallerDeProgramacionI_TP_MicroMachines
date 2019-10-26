#ifdef _cplusplus
    #include "lua.hpp"
#else

#include <iostream>
#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
#include "ParametrosLua/ParametroLua.h"
#include "ParametrosLua/EnteroLua.h"
#include "InterpreteLua.h"
#include "ParametrosLua/CadenaLua.h"

#endif

int main(){
    try{
        InterpreteLua inteprete("./script.lua");
        std::vector<std::unique_ptr<ParametroLua>> params;
        params.emplace_back(new CadenaLua("Hola"));
        params.emplace_back(new EnteroLua(3));
        std::vector<std::unique_ptr<ParametroLua>> ret = inteprete.ejecutar_funcion("multiplicarString", params);
        Retorno cadenaRepetido = ret[0]->obtenerValor();
        std::cout << cadenaRepetido.cadena << std::endl;
    }catch(std::runtime_error &e){
        std::cerr << e.what() << std::endl;
    }
}
