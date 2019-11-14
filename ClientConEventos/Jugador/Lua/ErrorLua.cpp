
#include "ErrorLua.h"

ErrorLua::ErrorLua(const std::string &msj, const std::string& script, \
const std::string &error, int linea, const char *archivo) :
        runtime_error(msj + " \""+ script +"\": " + std::string(error) +\
" " + std::to_string(linea) + ":" + std::string(archivo)){
}