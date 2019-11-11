#ifndef _PODIO_H_
#define _PODIO_H_

#include <list>
#include "../Objetos/Carro/Carro.h"

class Podio {
private:
    int cantidadDeVueltas;
    std::list<Carro*> carros;

public:
    explicit Podio(int cantidadDeVueltas);

    void agregarCarro(Carro *carro);

    void actualizarPodio();

    ~Podio();

};


#endif
