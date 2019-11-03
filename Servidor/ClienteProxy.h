#ifndef PROTOCOLO_CLIENTEPROXY_H
#define PROTOCOLO_CLIENTEPROXY_H


#include <memory>
#include <unordered_map>
#include <atomic>
#include "Protocolo.h"
#include "Comandos/Comando.h"
#include "Partida.h"

class ClienteProxy {
    Protocolo protocolo;
    std::unordered_map<std::string, std::unique_ptr<Comando>> comandos;
    std::atomic<bool> conectado;
public:
    ClienteProxy(SocketAmigo socketCliente, Partida &partida);

    void ejecutarComando();
    void desconectar();
    ~ClienteProxy();

    bool estaConectado();
};

#endif
