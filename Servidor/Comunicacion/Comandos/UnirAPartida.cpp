//
// Created by manfer on 5/11/19.
//

#include "UnirAPartida.h"

#define MSJ_PARTIDA_INEXISTENTE "La Partida no existe"

UnirAPartida::UnirAPartida(std::map<std::string, std::shared_ptr<Partida>> &partidas,
        ConfiguracionServidor& mapasYAutos): partidas(partidas), mapasYAutos(mapasYAutos) {
}

void UnirAPartida::ejecutar(ClienteProxy &cliente) {
    for(auto& partida : partidas){
        cliente.enviar(partida.first); //Aca formatearia los datos de la partida
    }
    cliente.enviar(MSJ_FIN);
    //Recibo el nombre de la partida a la cual el usuario quiere agregarse o crear
    std::string nombrePartida = cliente.recibir();
    auto it = partidas.find(nombrePartida);
    if (it == partidas.end()){
        cliente.enviar(MSJ_PARTIDA_INEXISTENTE);
        return;
    }
    //Elije un auto
    for (auto& carro : mapasYAutos.obtenerNombresCarros()){
        cliente.enviar(carro);
    }
    cliente.enviar(MSJ_FIN);
    std::string carro = cliente.recibir();
    partidas[nombrePartida]->agregarCliente(mapasYAutos.darPlanoDeCarro(carro), &cliente);
    cliente.jugar();
}
