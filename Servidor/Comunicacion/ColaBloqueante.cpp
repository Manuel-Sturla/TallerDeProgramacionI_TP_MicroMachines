//
// Created by manfer on 10/11/19.
//

#include "ColaBloqueante.h"

void ColaBloqueante::encolar(EventoParseable *evento) {
    cola.emplace(evento);
    estaVacia.notify_all();
}

void ColaBloqueante::encolar(std::shared_ptr<EventoParseable>& evento) {
    cola.push(evento);
    estaVacia.notify_all();
}

std::shared_ptr<EventoParseable> ColaBloqueante::desencolar() {
    std::unique_lock<std::mutex> lock(mutex);
    while (cola.empty()){
        estaVacia.wait(lock);
    }
    std::shared_ptr<EventoParseable> aux = cola.front();
    cola.pop();
    return aux;
}
