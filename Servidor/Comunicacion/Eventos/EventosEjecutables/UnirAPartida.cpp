#include "UnirAPartida.h"
#include "../../../PartidaLlenaExcepcion.h"
#include "../EventosParseables/NoSePudoUnir.h"
#include "../EventosParseables/UnirAPartidaCorrecto.h"

#define MSJ_NO_UNIDO "UnirNoOK"

#define MSJ_UNIR_OK "UnirOK"

UnirAPartida::UnirAPartida(HashProtegido &partidas,
                           ConfiguracionServidor& config): partidas(partidas), mapasYAutos(config) {
}

void UnirAPartida::ejecutar(ClienteProxy &cliente, std::vector<std::string> argumento) {
    //Recibo el nombre de la partida a la cual el usuario quiere agregarse o crear
    //std::string nombrePartida = cliente.recibir();
    std::string nombrePartida = argumento[0];
    if (!partidas.contiene(nombrePartida)) {
        cliente.encolarEvento(new NoSePudoUnir());
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
    try {
        cliente.setCarro(partidas.obtener(nombrePartida)->agregarCliente(mapasYAutos.darPlanoDeCarro(carro), &cliente));
        cliente.jugar();
    } catch (PartidaLlenaExcepcion &e) {  //Catcheo excepcion de que no existe el carro
        cliente.encolarEvento(new NoSePudoUnir());
    }
    //Agregar el nombre de la partida a la que se unio al cliente
}

