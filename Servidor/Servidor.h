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

class Servidor: public Hilo {
private:
    ConfiguracionServidor configuracion;
    SocketPasivo socketPasivo;
    std::map<std::string, Partida> partidas;
    std::atomic<bool> continuar;

public:
    Servidor(const std::string& servicio);
    std::map<std::string, Partida>& obtenerPartidas();
    void run() override;

    ~Servidor();

};

#endif
