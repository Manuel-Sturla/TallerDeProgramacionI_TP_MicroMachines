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
#include "ConfiguracionServidor.h"
#include "Partida/Partida.h"
#include "Comunicacion/HiloCliente.h"
#include "Partida/HashProtegido.h"

class Servidor: public Hilo {
private:
    ConfiguracionServidor configuracion;
    SocketPasivo socketPasivo;
    HashProtegido partidas;
    std::vector<std::unique_ptr<HiloCliente>> clientes;
    std::atomic<bool> continuar;
    EnJuego enJuego;
    EnMenu enMenu;

public:
    Servidor(const std::string& servicio);
    HashProtegido & obtenerPartidas();
    void run() override;

    ~Servidor();

    void cerrar_clientes_desconectados();

    void cerrar_partidas_terminadas();

    void apagar();
};

#endif
