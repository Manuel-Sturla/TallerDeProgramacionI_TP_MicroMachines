
#include "EnviarPartidas.h"
#include "../../Utilidades.h"

#define EVENTO_ENVIAR_PARTIDAS "ObtenerPartidas"

EnviarPartidas::EnviarPartidas(HashProtegido &partidas) : partidas(partidas){

}

std::string EnviarPartidas::obtenerParseado() {
    std::vector<std::string> nombrePartidas;
    nombrePartidas.emplace_back(EVENTO_ENVIAR_PARTIDAS);
    for(auto& partida : partidas.obtenerClaves()){
        nombrePartidas.push_back(partida);
    }
    return unir(nombrePartidas, SEPARADOR);
}
