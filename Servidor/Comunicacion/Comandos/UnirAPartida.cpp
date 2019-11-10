#include "UnirAPartida.h"
#include "../../PartidaLlenaExcepcion.h"

#define MSJ_PARTIDA_INEXISTENTE "La Partida no existe"

#define MSJ_NO_UNIDO "UnirNoOK"

#define MSJ_UNIR_OK "UnirOK"

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
    try{
        cliente.setCarro(partidas[nombrePartida]->agregarCliente(mapasYAutos.darPlanoDeCarro(carro), &cliente));
        cliente.jugar();
    }catch (PartidaLlenaExcepcion &e){
        cliente.enviar(MSJ_NO_UNIDO);
    }
    //Agregar el nombre de la partida a la que se unio al cliente
    cliente.enviar(MSJ_UNIR_OK);
}
