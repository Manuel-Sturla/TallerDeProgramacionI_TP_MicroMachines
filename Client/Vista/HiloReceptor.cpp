//
// Created by diego on 2/11/19.
//

#include <iostream>
#include "HiloReceptor.h"
#include "../Excepciones/ExcepcionConPos.h"
#include "Camara.h"
#include "../Sockets/SocketPeerException.h"

HiloReceptor::HiloReceptor(Renderizador& renderizador, ServidorProxy &servidor, Camara &camara, bool& keepTalking) : keepTalking(keepTalking)\
, servidor(servidor), miAuto(renderizador, 1){
    camara.setPosAuto(&miAuto.getPos());
}

void HiloReceptor::run() {
    try {
        while(keepTalking){
            std::vector<std::string> autos;
            std::vector<std::string> extras;
            servidor.obtenerPosiciones(extras, autos);
/*            int posX = std::stoi(autos[0]);
            int posY = std::stoi(autos[1]);
            int angulo = std::stoi(autos[2]);
            miAuto.mover(posX, posY, angulo);*/
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
