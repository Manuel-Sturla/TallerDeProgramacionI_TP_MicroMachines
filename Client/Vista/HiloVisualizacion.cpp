//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "HiloVisualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"

HiloVisualizacion::HiloVisualizacion(Servidor& servidor) : renderizador("microMachines.exe", 1000, 1000)\
, servidor(servidor), contenedor(renderizador), camara(contenedor.getAuto().getPos(), 1000) {}

void HiloVisualizacion::run() {
    try{
        std::vector<int> mensaje = servidor.recibir();
        contenedor.actualizar(mensaje);
        while(mensaje[0] != -1){
            renderizador.limpiar();
            renderizador.copiarTodo(camara);
            renderizador.imprimir(20);
            contenedor.actualizar(mensaje);
            mensaje = servidor.recibir();
        }
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
    } catch (std::exception& e) {
        std::cerr<<e.what()<<'\n';
    } catch (...) {
        std::cerr<<"Error desconocido\n";
    }
}
