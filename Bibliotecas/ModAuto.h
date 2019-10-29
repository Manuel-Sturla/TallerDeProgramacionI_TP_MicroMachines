//
// Created by manfer on 28/10/19.
//

#ifndef BIBLIOTECASLOCAS_MODAUTO_H
#define BIBLIOTECASLOCAS_MODAUTO_H


#include <string>
#include "BibliotecaDinamica.h"
#include "Carro.h"

class ModAuto {
    void(*funcionActivar)(void*);
    std::string nombreFuncion = "activar";
    BibliotecaDinamica biblioteca;

public:
    ModAuto(std::string ruta);
    void activar(Carro& carro);
};


#endif //BIBLIOTECASLOCAS_MODAUTO_H
