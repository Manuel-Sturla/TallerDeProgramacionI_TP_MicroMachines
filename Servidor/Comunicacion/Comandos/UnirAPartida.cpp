#include "UnirAPartida.h"

#define MSJ_PARTIDA_INEXISTENTE "La Partida no existe"

UnirAPartida::UnirAPartida(std::map<std::string, std::shared_ptr<Partida>> &partidas,
        ConfiguracionServidor& mapasYAutos): partidas(partidas), mapasYAutos(mapasYAutos) {
}

void UnirAPartida::ejecutar(ClienteProxy &cliente) {
    //Recibo el nombre de la partida a la cual el usuario quiere agregarse o crear
    std::string nombrePartida = cliente.recibir();
    auto it = partidas.find(nombrePartida);
    if (it == partidas.end()){
        cliente.enviar(MSJ_PARTIDA_INEXISTENTE);
        return;
    }
    //Elije un auto
    /*for (auto& carro : mapasYAutos.obtenerNombresCarros()){
        cliente.enviar(carro);
    }
    cliente.enviar(MSJ_FIN);
    std::string carro = cliente.recibir();
    */
    std::string carro = "ManuMovil";
    cliente.setCarro(partidas[nombrePartida]->agregarCliente(mapasYAutos.darPlanoDeCarro(carro), &cliente));
    //Agregar el nombre de la partida a la que se unio al cliente
    cliente.jugar();
}
