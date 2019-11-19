//
// Created by diego on 19/11/19.
//

#include "ComandoPodio.h"

#include <utility>
#include "../Sockets/Utilidades.h"

ComandoPodio::ComandoPodio(std::map<std::string, Desplazable *> &desplazables, Renderizador &renderizador,std::string idMiAuto)\
: ComandoVisualizacion(desplazables, renderizador), idMiAuto(std::move(idMiAuto)){
    int posY = 10;
    for(int i = 0; i < 7; i++){
        posPodio.emplace_back(10, posY, 150, 50, 0);
        posY += 60;
    }
    for(int i = 0; i < 7; i++){
        idPodio.emplace_back("posicion"+std::to_string(i));
    }
    std::string aux = "Posiciones:";
    renderizador.agregarTexto(aux, &posPodio[0], idPodio[0], 255, 255, 255);
}

void ComandoPodio::ejecutar(std::vector<std::string> &eventos) {
    for (int j = 1; j < 7; ++j) {
        renderizador.borrarTexto(idPodio[j]);
    }
    int i = 1;
    std::string aux;
    while(eventos[0] != "fin podio"){
        aux = std::to_string(i) + ". " + "Jugador "+eventos[0];
        if(eventos[0] == idMiAuto){
            renderizador.agregarTexto(aux, &posPodio[i], idPodio[i], 0, 0, 255);
        } else {
            renderizador.agregarTexto(aux, &posPodio[i], idPodio[i], 255, 255, 255);
        }
        eventos.erase(eventos.begin());
        i++;
    }
}
