#ifndef PROTOCOLO_CLIENTEPROXY_H
#define PROTOCOLO_CLIENTEPROXY_H


#include <memory>
#include <unordered_map>
#include <atomic>
#include <queue>
#include "Protocolo.h"
#include "Comandos/Comando.h"
#include "../Partida/Partida.h"

class ClienteProxy {
    Protocolo protocolo;
    std::queue<std::unique_ptr<Accion>> movimientos;
    std::unordered_map<std::string, std::unique_ptr<Comando>> comandos;
    std::atomic<bool> conectado;
public:
    ClienteProxy(SocketAmigo socketCliente, Partida &partida);

    void ejecutarComando();
    void recibirAccion(); // Se hace en un hilo aparte que recibe acciones todo el tiempo y las encola
    void desconectar();
    void ejecutarAccion(Carro *autinio);
    ~ClienteProxy();

    bool estaConectado();
};

#endif
