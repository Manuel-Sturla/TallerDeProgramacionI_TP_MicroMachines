//
// Created by manfer on 22/10/19.
//

#include <dlfcn.h>
#include <iostream>
#include "LibreriaDinamica.h"
#include "ErrorLibreria.h"

LibreriaDinamica::LibreriaDinamica(const std::string& ruta) {
    libreria = dlopen(ruta.c_str(), RTLD_LAZY);
    if (!libreria){
        std::cerr << dlerror() << std::endl;
    }
    dlerror();
}

LibreriaDinamica::~LibreriaDinamica() {
    dlclose(libreria);
}

void *LibreriaDinamica::buscar_funcion(const std::string &nombre) {
    void* ptr_funcion = dlsym(libreria, nombre.c_str());
    char* error;
    if ((error = dlerror()) != NULL)  {
        throw ErrorLibreria("Error al buscar funcion \"" + nombre + "\": " + std::string(error));
    }
    return ptr_funcion;
}
