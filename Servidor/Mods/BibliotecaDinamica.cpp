
#include <dlfcn.h>
#include <iostream>
#include "BibliotecaDinamica.h"
#include "ErrorBiblioteca.h"

BibliotecaDinamica::BibliotecaDinamica(const std::string& ruta) {
    libreria = dlopen(ruta.c_str(), RTLD_LAZY);
    if (!libreria){
        throw ErrorBiblioteca("Error al abrir biblioteca", ruta, dlerror(), __LINE__, __FILE__);
    }
    dlerror();
}

BibliotecaDinamica::~BibliotecaDinamica() {
    dlclose(libreria);
}

void *BibliotecaDinamica::buscar_funcion(const std::string &nombre) {
    void* ptr_funcion = dlsym(libreria, nombre.c_str());
    char* error;
    if ((error = dlerror()) != NULL)  {
        throw ErrorBiblioteca("Error al buscar funcion", nombre, error, __LINE__, __FILE__);
    }
    return ptr_funcion;
}

BibliotecaDinamica::BibliotecaDinamica(BibliotecaDinamica &&otra) {
    this->libreria = otra.libreria;
    otra.libreria = nullptr;
}

BibliotecaDinamica &BibliotecaDinamica::operator=(BibliotecaDinamica &&otra) {
    this->libreria = otra.libreria;
    otra.libreria = nullptr;
    return *this;
}

