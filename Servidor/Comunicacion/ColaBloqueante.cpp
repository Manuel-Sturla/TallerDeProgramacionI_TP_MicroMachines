#include <iostream>
#include "ColaBloqueante.h"

void ColaBloqueante::encolar(EventoParseable *evento) {
    std::unique_lock<std::mutex> lock(mutex);
    cola.emplace(evento);
    estaVacia.notify_all();
}

void ColaBloqueante::encolar(std::shared_ptr<EventoParseable> evento) {
    std::unique_lock<std::mutex> lock(mutex);
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

ColaBloqueante::ColaBloqueante(ColaBloqueante &&otra) :
cola(std::move(otra.cola)){
}

ColaBloqueante &ColaBloqueante::operator=(ColaBloqueante &&otra) {
    if (this == &otra) {
        return *this;
    }
    this->cola = otra.cola;
    return *this;
}

ColaBloqueante::~ColaBloqueante() {
    std::unique_lock<std::mutex> lock(mutex);
    while (!cola.empty()){
        cola.pop();
    }
}
