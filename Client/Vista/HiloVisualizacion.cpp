//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "HiloVisualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"

HiloVisualizacion::HiloVisualizacion(Servidor& servidor) : renderizador("microMachines.exe", 1000, 1000)\
, contenedor(renderizador, servidor), camara(contenedor.getAuto().getPos(), 1000) {}

void HiloVisualizacion::run() {
    try{
        bool keepTalking = true;
        contenedor.actualizar();
        while(keepTalking){
            renderizador.limpiar();
            renderizador.copiarTodo(camara);
            renderizador.imprimir(20);
            keepTalking = contenedor.actualizar();
        }
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
    } catch (std::exception& e) {
        std::cerr<<e.what()<<'\n';
    } catch (...) {
        std::cerr<<"Error desconocido\n";
    }
}
