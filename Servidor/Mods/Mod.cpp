//
// Created by manfer on 17/11/19.
//

#include "Mod.h"
Mod::Mod(const std::string& ruta) : biblioteca(ruta){
}


Mod::Mod(Mod &&otro) :biblioteca(std::move(otro.biblioteca)) {
}

Mod &Mod::operator=(Mod &&otro) {
    if (this == &otro) {
        return *this;
    }
    biblioteca = std::move(otro.biblioteca);
    return *this;
}
