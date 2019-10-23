//
// Created by manfer on 23/10/19.
//

#ifndef BIBLIOTECASLOCAS_PLUGIN_H
#define BIBLIOTECASLOCAS_PLUGIN_H


#include <string>
#include "BibliotecaDinamica.h"

class Plugin {
    int (*funcion_activar) (int);
    std::string nombre_func = "sumar_1"; //aca va el nombre de la funcion generica de los plugins
    BibliotecaDinamica biblioteca;
public:
    Plugin(std::string ruta);
    int activar(int param); //esta es la funcion que transoforma de cosas de C++ a C para llamarla
};


#endif //BIBLIOTECASLOCAS_PLUGIN_H
