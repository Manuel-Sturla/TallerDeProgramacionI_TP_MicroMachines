#ifndef PROTOCOLO_CLIENTEPROXY_H
#define PROTOCOLO_CLIENTEPROXY_H


#include <memory>
#include <unordered_map>
#include <atomic>
#include <queue>
#include "Protocolo.h"
#include "../Acciones/Accion.h"
#include "../Objetos/Carro/Carro.h"

class ClienteProxy{
    Protocolo protocolo;
    std::queue<std::unique_ptr<Accion>> movimientos;
    Carro *miCarro;
    bool enJuego;
public:
    explicit ClienteProxy(SocketAmigo socketCliente);
    ClienteProxy(ClienteProxy&& otro);
    void jugar();
    bool estaEnJuego();
    void setCarro(Carro* carringuis);
    void encolarAccion(Accion* accion);
    void desconectar();
    void ejecutarAccion();
    void enviar(const std::string&  mensaje);
    std::string recibir();
    ~ClienteProxy();
};

#endif
