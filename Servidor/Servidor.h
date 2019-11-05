#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include <unordered_map>
#include <string>
#include <memory>
#include <atomic>
#include <map>
#include "Planos/PlanoDePista.h"
#include "../Protocolo/Socket/SocketPasivo.h"
#include "Hilo.h"
#include "Partida/Partida.h"
#include "ConfiguracionServidor.h"
#include "Comunicacion/ClienteProxy.h"

class Servidor: public Hilo {
private:
    ConfiguracionServidor configuracion;
    SocketPasivo socketPasivo;
    std::map<std::string, std::shared_ptr<Partida>> partidas;
    std::vector<std::unique_ptr<ClienteProxy>> clientes;
    std::atomic<bool> continuar;

public:
    Servidor(const std::string& servicio);
    std::map<std::string, std::shared_ptr<Partida>> & obtenerPartidas();
    void run() override;

    ~Servidor();

    void cerrar_clientes_desconectados();

    void cerrar_partidas_terminadas();
};

#endif
