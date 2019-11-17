//
// Created by manfer on 17/11/19.
//

#ifndef SERVIDOR_MODAUTO_H
#define SERVIDOR_MODAUTO_H


#include <string>
#include "Mod.h"
#include "../Objetos/Carro/Carro.h"

class ModAuto: public Mod {
    int(*funcionActivar)(void*);
    const std::string nombreFuncion = "activar";

public:
    ModAuto(const std::string& ruta);
    ModAuto(ModAuto&& otro);
    ModAuto& operator=(ModAuto &&otro);
    int activar(Carro& carro) override;
};


#endif //SERVIDOR_MODAUTO_H
