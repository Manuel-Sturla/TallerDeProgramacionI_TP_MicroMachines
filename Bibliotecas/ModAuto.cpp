//
// Created by manfer on 28/10/19.
//

#include "ModAuto.h"

ModAuto::ModAuto(std::string ruta) : biblioteca(ruta){
    *(void**)(&funcionActivar) = biblioteca.buscar_funcion(nombreFuncion);
}

void ModAuto::activar(Carro& carro) {
    funcionActivar((void*)&carro);
}
