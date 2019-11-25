//
// Created by manfer on 12/11/19.
//

#ifndef SERVIDOR_HASHPROTEGIDOCLIENTES_H
#define SERVIDOR_HASHPROTEGIDOCLIENTES_H


#include <string>
#include <memory>
#include <map>
#include "../Comunicacion/ClienteProxy.h"

class HashProtegidoClientes {
    std::mutex mutex;
    std::map<std::string, ClienteProxy&> clientes;
public:
    HashProtegidoClientes() = default;
    bool ubicar(const std::string& clave, ClienteProxy &cliente);
    bool eliminar(const std::string& clave);
    ClienteProxy & obtener(const std::string& clave);
    std::vector<std::string> obtenerClaves();
    bool contiene(const std::string& clave);
    void enviarEventos(std::vector<std::shared_ptr<EventoParseable>>& eventos);
    void ejecutarAccionesClientes();
    void enviarAutosPropios();
    bool estaVacio();
    void eliminarTodos();
};



#endif //SERVIDOR_HASHPROTEGIDOCLIENTES_H
