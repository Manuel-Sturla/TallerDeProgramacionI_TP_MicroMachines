//
// Created by diego on 19/11/19.
//

#include "ComandoPodio.h"

#include <utility>
#include "../Sockets/Utilidades.h"

ComandoPodio::ComandoPodio(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador,std::string idMiAuto)\
: ComandoVisualizacion(desplazables, renderizador), idMiAuto(std::move(idMiAuto)){
    int anchoPantalla = renderizador.obtenerAncho();
    int alturaPantalla = renderizador.obtenerAltura();
    int posY = 10;
    for(int i = 0; i < 7; i++){
        idPodio.emplace_back("posicion"+std::to_string(i));
    }
    posPodio.emplace_back(10, posY, anchoPantalla/5, alturaPantalla/20, 0);
    for(int i = 0; i < 6; i++){
        posY += alturaPantalla/30;
        posPodio.emplace_back(10, posY, anchoPantalla/20, alturaPantalla/20, 0);
    }
    for(int i = 1; i < 7; ++i){
        renderizador.agregarTexto(std::to_string(i)+". ", &posPodio[i], idPodio[i], 255, 255, 255);
    }
    std::string aux = "Posiciones:";
    renderizador.agregarTexto(aux, &posPodio[0], idPodio[0], 255, 255, 255);
}

void ComandoPodio::ejecutar(std::vector<std::string> &eventos) {
    int i = 1;
    while(eventos[0] != "fin podio"){
        auto it = posJugadores.find(eventos[0]);
        if(it == posJugadores.end()){
            agregarJugador(posPodio[i], eventos[0]);
        } else {
            ponerEnPosicion(posPodio[i], it->second);
        }
        eventos.erase(eventos.begin());
        i++;
    }
}

void ComandoPodio::ponerEnPosicion(Posicion &puesto, Posicion &posJugador) {
    pos_t aux = puesto.getPosicion();
    posJugador.moverA(aux.x+aux.w+5, aux.y);
}

void ComandoPodio::agregarJugador(Posicion &posicion, std::string &idJugador) {
    pos_t aux = posicion.getPosicion();
    posJugadores.insert(std::pair<std::string, Posicion>(idJugador, Posicion(aux.x+aux.w+5, aux.y,\
    aux.w*3, aux.h, 0)));
    auto it = posJugadores.find(idJugador);
    if(idJugador == idMiAuto){
        renderizador.agregarTexto("Jugador "+idJugador, &it->second,\
        idJugador, 0, 0, 255);
    } else {
        renderizador.agregarTexto("Jugador "+idJugador, &it->second,\
        idJugador, 255,255, 255);
    }
}
