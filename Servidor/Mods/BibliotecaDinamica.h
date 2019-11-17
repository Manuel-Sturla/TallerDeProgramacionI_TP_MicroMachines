
#ifndef SERVIDOR_BIBLIOTECADINAMICA_H
#define SERVIDOR_BIBLIOTECADINAMICA_H

#include <string>
#include "BibliotecaDinamica.h"


#include <string>

class BibliotecaDinamica {
    void* libreria;
public:
    explicit BibliotecaDinamica(const std::string& ruta);
    ~BibliotecaDinamica();
    void* buscar_funcion(const std::string& nombre);
    BibliotecaDinamica(BibliotecaDinamica&& otra);
    BibliotecaDinamica(const BibliotecaDinamica& otra) = delete;
    BibliotecaDinamica& operator=(BibliotecaDinamica&& otra);
    BibliotecaDinamica& operator=(const BibliotecaDinamica&) = delete;
};



#endif //SERVIDOR_BIBLIOTECADINAMICA_H
