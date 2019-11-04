#ifndef PROTOCOLO_CLIENTEPROXY_H
#define PROTOCOLO_CLIENTEPROXY_H


#include <memory>
#include <unordered_map>
#include <atomic>
#include <queue>
#include "Protocolo.h"
#include "Comandos/Comando.h"
#include "../Partida/Partida.h"
#include "../Servidor.h"

class ClienteProxy: public Hilo {
    Protocolo protocolo;
    std::queue<std::unique_ptr<Accion>> movimientos;
    std::unordered_map<std::string, std::unique_ptr<Comando>> comandos;
    std::atomic<bool> conectado;
public:
    ClienteProxy(SocketAmigo socketCliente, Servidor &servidor, Partida& partida);

    void run() override;

    void ejecutarComando();
    void recibirAccion(); // Se hace en un hilo aparte que recibe acciones todo el tiempo y las encola
    void enviarPosiciones();
    void desconectar();
    void ejecutarAccion(Carro *autinio);
    ~ClienteProxy();

    bool estaConectado();
};

#endif
