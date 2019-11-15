#ifndef _PODIO_H_
#define _PODIO_H_

#include <list>
#include "../Objetos/Carro/Carro.h"

class Podio {
private:
    int cantidadDeVueltas;
    std::list<Carro*> carros;

public:
    Podio(int cantidadDeVueltas);

    void agregarCarro(Carro *carro);

    void actualizarPodio();

    bool analizarVictoria();

    std::string obtenerGanador();

    ~Podio();

};


#endif
