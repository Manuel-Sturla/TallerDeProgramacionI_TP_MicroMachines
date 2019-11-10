#include "EnJuego.h"
#include "../../Partida/HashProtegido.h"


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


EnJuego::EnJuego(HashProtegido &partidas) {
    comandos.emplace("MOV", new RecibirAccion());
}
