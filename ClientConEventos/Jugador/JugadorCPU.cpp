//
// Created by manfer on 14/11/19.
//

#include <iostream>
#include "JugadorCPU.h"
#include "Lua/ParametrosLua/CadenaLua.h"
#include "Lua/ParametrosLua/EnteroLua.h"

#define FUNC_NUEVA_ACCION "obtenerNuevaAccion"
#define FUNC_NUEVO_MAPA "crearMapa"

JugadorCPU::JugadorCPU(const std::string &rutaScript) : interprete(rutaScript){
    cpu = true;
}

int JugadorCPU::obtenerComando() {
    std::vector<std::unique_ptr<ParametroLua>> params;
    params.emplace_back(new CadenaLua ("0-0"));
    std::vector<std::unique_ptr<ParametroLua>> ret = interprete.ejecutarFuncion(FUNC_NUEVA_ACCION, params);
    return 0;}

void JugadorCPU::ponerMapa(std::vector<std::string> &comando) {
    comando.erase(comando.begin());
    for (auto& c : comando){
        std::cout << c << "; ";
    }
    std::cout << std::endl;
    std::string nombreTabla = "tablaAuxiliar";
    for (size_t i = 1; i <= comando.size(); i++) {
        CadenaLua posicion(comando[i-1]);
        EnteroLua indice(i);
        interprete.agregarElementoTabla(nombreTabla, indice, posicion);
    }
    std::vector<std::string> vars = {nombreTabla};
    interprete.ejecutarFuncion(FUNC_NUEVO_MAPA, vars);
    interprete.ejecutarFuncion("MostrarMapa");
}
