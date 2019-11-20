//
// Created by manfer on 17/11/19.
//

#ifndef SERVIDOR_MODAUTO_H
#define SERVIDOR_MODAUTO_H


#include <string>
#include "Mod.h"

class ModAuto: public Mod {
    void(*funcionActivar)(CarroDTO_t*);
    const std::string nombreFuncion = "activar";

public:
    ModAuto(const std::string& ruta);
    ModAuto(ModAuto&& otro);
    ModAuto& operator=(ModAuto &&otro);
    void activar(Carro& carro) override;
};


#endif //SERVIDOR_MODAUTO_H
