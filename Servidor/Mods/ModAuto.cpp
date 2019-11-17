//
// Created by manfer on 17/11/19.
//

#include "ModAuto.h"

ModAuto::ModAuto(const std::string &ruta) : Mod(ruta){
    *(void**)(&funcionActivar) = biblioteca.buscar_funcion(nombreFuncion);
}

int ModAuto::activar(Carro& carro) {
    return funcionActivar((void*)& carro);
}

ModAuto::ModAuto(ModAuto &&otro) : Mod(std::move(otro)){
    funcionActivar = otro.funcionActivar;
    otro.funcionActivar = nullptr;
}

ModAuto &ModAuto::operator=(ModAuto &&otro) {
    if (this == &otro) {
        return *this;
    }
    funcionActivar = otro.funcionActivar;
    otro.funcionActivar = nullptr;
    Mod::operator=(std::move(otro));
    return *this;
}
