//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_COLABLOQUEANTE_H
#define SERVIDOR_COLABLOQUEANTE_H


#include <mutex>
#include <condition_variable>
#include <queue>
#include "Eventos/EventosParseables/EventoParseable.h"

class ColaBloqueante {
    std::mutex mutex;
    std::condition_variable estaVacia;
    std::queue<std::shared_ptr<EventoParseable>> cola;
public:
    ColaBloqueante() = default;
    void encolar(EventoParseable* evento);
    void encolar(std::shared_ptr<EventoParseable>& evento);
    std::shared_ptr<EventoParseable> desencolar();
};


#endif //SERVIDOR_COLABLOQUEANTE_H
