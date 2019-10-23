#ifndef BIBLIOTECASLOCAS_LIBRERIADINAMICA_H
#define BIBLIOTECASLOCAS_LIBRERIADINAMICA_H


#include <string>

class LibreriaDinamica {
    void* libreria;
public:
    explicit LibreriaDinamica(const std::string& ruta);
    ~LibreriaDinamica();
    void* buscar_funcion(const std::string& nombre);
    //Eliminar el constructor por copia, y agregar el de movimiento!!!
};


#endif //BIBLIOTECASLOCAS_LIBRERIADINAMICA_H
