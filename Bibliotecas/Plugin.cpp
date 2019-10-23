//
// Created by manfer on 23/10/19.
//

#include "Plugin.h"

Plugin::Plugin(std::string ruta) : biblioteca(ruta){
    *(void**)(&funcion_activar) = biblioteca.buscar_funcion(nombre_func);
}

int Plugin::activar(int param) {
    return funcion_activar(param);
}

Plugin::Plugin(Plugin &&otro) :biblioteca(std::move(biblioteca)) {
    nombre_func = otro.nombre_func;
    funcion_activar = otro.funcion_activar;

    otro.funcion_activar = nullptr;
    otro.nombre_func = "";
}

Plugin &Plugin::operator=(Plugin &&otro) {
    biblioteca = std::move(otro.biblioteca);
    nombre_func = otro.nombre_func;
    funcion_activar = otro.funcion_activar;

    otro.funcion_activar = nullptr;
    otro.nombre_func = "";
    return *this;
}
