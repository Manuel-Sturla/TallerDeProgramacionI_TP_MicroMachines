//
// Created by manfer on 23/10/19.
//

#ifndef LUATEST_ERRORLUA_H
#define LUATEST_ERRORLUA_H


#include <stdexcept>

class ErrorLua : public std::runtime_error{

public:
    ErrorLua(const std::string& msj, const std::string& script, \
    const std::string& error, int linea, const char *archivo);
};


#endif //LUATEST_ERRORLUA_H

