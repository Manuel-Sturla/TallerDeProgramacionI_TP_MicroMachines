//
// Created by manfer on 26/10/19.
//

#include <algorithm>
#include "JugadorCPU.h"
#include "ParametrosLua/CadenaLua.h"
#include "ParametrosLua/EnteroLua.h"

#define FUNC_NUEVA_ACCION "obtenerNuevaAccion"
#define FUNC_NUEVO_MAPA "crearMapa"
std::string JugadorCPU::obtenerAccion() {
    std::vector<std::unique_ptr<ParametroLua>> ret = interprete.ejecutarFuncion(FUNC_NUEVA_ACCION);
    return ret[0]->obtenerValor().cadena;
}

JugadorCPU::JugadorCPU(const std::string& rutaScript, std::vector<std::string>& posPasto) :
    interprete(rutaScript){
    //Creo una tabla con los datos del mapa,
    // podría chequear que los strings estan separados con el SEPARADOR
    std::string nombreTabla = "tablaAuxiliar";
    for (size_t i = 1; i <= posPasto.size(); i++) {
        CadenaLua posicion(posPasto[i-1]);
        EnteroLua indice(i);
        interprete.agregarElementoTabla(nombreTabla, indice, posicion);
    }
    std::vector<std::string> vars = {nombreTabla};
    interprete.ejecutarFuncion(FUNC_NUEVO_MAPA, vars);
}
