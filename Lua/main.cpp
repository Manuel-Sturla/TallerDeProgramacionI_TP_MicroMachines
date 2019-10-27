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
#include "JugadorCPU.h"

#endif

int main(){
    try{
        std::vector<std::string> posPastoMapa = {"0-0", "0-1", "0-2"};
        JugadorCPU bot("../ScriptsLua/script.lua", posPastoMapa);
        std::cout << bot.obtenerAccion("1-1") << std::endl;
    }catch(std::runtime_error &e){
        std::cerr << e.what() << std::endl;
    }
}
