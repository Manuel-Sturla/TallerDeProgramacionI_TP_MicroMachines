//
// Created by manfer on 17/11/19.
//

#include <iostream>
#include "ModAuto.h"

ModAuto::ModAuto(const std::string &ruta) : Mod(ruta){
    *(void**)(&funcionActivar) = biblioteca.buscar_funcion(nombreFuncion);
}

void ModAuto::activar(std::list<Carro> &carros) {
    for (Carro& carro : carros){
        CarroDTO_t carroDTO = carro.crearDTO();
        funcionActivar(&carroDTO);
        carro.cargarDatos(carroDTO);
    }
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
