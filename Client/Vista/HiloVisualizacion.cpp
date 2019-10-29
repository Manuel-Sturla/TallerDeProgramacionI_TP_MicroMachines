//
// Created by diego on 22/10/19.
//

#include <iostream>
#include "HiloVisualizacion.h"
#include "../Excepciones/ExcepcionConPos.h"

HiloVisualizacion::HiloVisualizacion(Servidor& servidor) : renderizador("microMachines.exe", 1000, 1000)\
, servidor(servidor), camara(renderizador) {
    camara.inicializar();
}

void HiloVisualizacion::run() {
    try{
        std::vector<int> mensaje = servidor.recibir();
        while(mensaje[0] != -1){
            renderizador.imprimir(20);
            renderizador.limpiar();
            camara.actualizar(mensaje);
            renderizador.copiarTodo();
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
