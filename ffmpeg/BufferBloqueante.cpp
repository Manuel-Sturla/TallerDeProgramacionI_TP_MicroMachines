//
// Created by manfer on 21/11/19.
//

#include <iostream>
#include "BufferBloqueante.h"

void BufferBloqueante::guardar(std::vector<char> &datos) {
    std::unique_lock<std::mutex> lock(mutex);
    buffer.clear();
    buffer.assign(datos.begin(), datos.end());
    tieneDatos.notify_all();
}

std::vector<char> BufferBloqueante::sacar() {
    std::unique_lock<std::mutex> lock(mutex);
    while (buffer.empty()){
        tieneDatos.wait(lock);
    }

    std::vector<char> aux (buffer);
    buffer.clear();
    return aux;
}
