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
