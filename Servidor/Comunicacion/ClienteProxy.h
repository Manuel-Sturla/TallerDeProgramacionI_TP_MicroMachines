#ifndef PROTOCOLO_CLIENTEPROXY_H
#define PROTOCOLO_CLIENTEPROXY_H


#include <memory>
#include <unordered_map>
#include <atomic>
#include <queue>
#include "Protocolo.h"
#include "../Acciones/Accion.h"
#include "../Objetos/Carro/Carro.h"
#include "ColaBloqueante.h"

class ClienteProxy{
    Protocolo protocolo;
    std::queue<std::unique_ptr<Accion>> movimientos;
    ColaBloqueante eventosAEnviar;
    Carro *miCarro;
    std::string enPartida;
    bool enJuego;
    size_t idCliente;
public:
    explicit ClienteProxy(SocketAmigo socketCliente);
    ClienteProxy(ClienteProxy&& otro);
    void enviarEvento();
    void jugar(const std::string &nombrePartida);
    std::string& obtenerPartida();
    bool estaEnJuego();
    void setCarro(Carro* carringuis);
    void encolarAccion(Accion* accion);
    void encolarEvento(EventoParseable *evento);
    void encolarEvento(std::shared_ptr<EventoParseable> &evento);
    void mandarAutoPropio();
    void borrarAutoPropio();
    void ejecutarAccion();
    void desconectar();
    void enviar(const std::string&  mensaje);

    std::string recibir();

    ~ClienteProxy();

    void setID(size_t i);
    size_t obtenerID();
};

#endif
