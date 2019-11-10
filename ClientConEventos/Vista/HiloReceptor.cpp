//
// Created by diego on 2/11/19.
//

#include <iostream>
#include "HiloReceptor.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "Camara.h"
#include "../Sockets/SocketPeerException.h"

HiloReceptor::HiloReceptor(Renderizador& renderizador, ServidorProxy &servidor, Camara &camara, bool& keepTalking)\
: keepTalking(keepTalking), servidor(servidor), desplazables(renderizador) {
    std::vector<std::string> eventos = servidor.obtenerEventos();
    desplazables.ejecutarEventos(eventos);
    desplazables.setCamara(camara);
}

void HiloReceptor::run() {
    try {
        while(keepTalking){
            std::vector<std::string> eventos;
            eventos = servidor.obtenerEventos();
            desplazables.ejecutarEventos(eventos);
        }
    } catch (const SocketPeerException& e){
        keepTalking = false;
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
    } catch (std::exception& e) {
        std::cerr<<e.what()<<'\n';
    } catch (...) {
        std::cerr<<"Error desconocido\n";
    }
}
