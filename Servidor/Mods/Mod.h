//
// Created by manfer on 17/11/19.
//

#ifndef SERVIDOR_MOD_H
#define SERVIDOR_MOD_H

#include <string>
#include <list>
#include "BibliotecaDinamica.h"
#include "../Objetos/Carro/Carro.h"

class Mod {
protected:
    BibliotecaDinamica biblioteca;
public:
    Mod(const std::string& ruta);
    virtual void activar(std::list<Carro> &param) = 0; //esta es la funcion que transoforma de cosas de C++ a C para llamarla
    Mod(Mod&& otro);
    Mod& operator=(Mod&& otro);
    Mod(const Mod& otro) = delete;
    Mod& operator=(const Mod&) = delete;
};

#endif //SERVIDOR_MOD_H
