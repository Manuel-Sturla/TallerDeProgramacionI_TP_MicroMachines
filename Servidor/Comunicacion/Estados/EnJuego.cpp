#include "EnJuego.h"


#define MSJ_CMD_INVALIDO "ComandoInvalido"

void EnJuego::ejecutar(ClienteProxy &cliente) {
    /*std::string comando = cliente.recibir();
    if (comandos.find(comando) == comandos.end()){
        cliente.enviar(MSJ_CMD_INVALIDO);
    }else{
        comandos[comando]->ejecutar(cliente);
    }*/
    comandos["MOV"]->ejecutar(cliente);
}


EnJuego::EnJuego(std::map<std::string, std::shared_ptr<Partida>>& partidas) {
    comandos.emplace("MOV", new RecibirAccion());
}
