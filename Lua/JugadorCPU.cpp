//
// Created by manfer on 26/10/19.
//

#include "JugadorCPU.h"

#define FUNC_NUEVA_ACCION "obtenerNuevaAccion"
#define FUNC_NUEVO_MAPA "crearMapa"
std::string JugadorCPU::obtenerAccion() {
    std::vector<std::unique_ptr<ParametroLua>> ret = interprete.ejecutarFuncion(FUNC_NUEVA_ACCION);
    return ret[0]->obtenerValor().cadena;
}

JugadorCPU::JugadorCPU(const std::string& rutaScript) :
    interprete(rutaScript){
    interprete.ejecutarFuncion(FUNC_NUEVA_ACCION); //Faltan las cosas del mapa
}
