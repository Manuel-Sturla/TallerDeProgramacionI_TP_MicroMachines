//
// Created by manfer on 12/11/19.
//

#include "HashProtegidoClientes.h"

bool HashProtegidoClientes::ubicar(const std::string &clave, ClienteProxy &cliente) {
    std::unique_lock<std::mutex> lock(mutex);
    return clientes.emplace(clave, cliente).second;
}

bool HashProtegidoClientes::eliminar(const std::string &clave) {
    std::unique_lock<std::mutex> lock(mutex);
    return clientes.erase(clave) != 0;
}

ClienteProxy & HashProtegidoClientes::obtener(const std::string &clave) {
    return clientes.at(clave);
}

std::vector<std::string> HashProtegidoClientes::obtenerClaves() {
    std::vector<std::string> claves;
    claves.reserve(clientes.size());
    std::unique_lock<std::mutex> lock(mutex);
    for(auto& cliente : clientes){
        claves.push_back(cliente.first);
    }
    return claves;
}

bool HashProtegidoClientes::contiene(const std::string& clave) {
    return clientes.find(clave) != clientes.end();
}

bool HashProtegidoClientes::estaVacio() {
    return clientes.empty();
}

void HashProtegidoClientes::eliminarTodos() {
    std::unique_lock<std::mutex> lock(mutex);
    clientes.clear();
}
