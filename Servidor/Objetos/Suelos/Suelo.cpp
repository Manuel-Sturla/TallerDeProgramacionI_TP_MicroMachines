#include "Suelo.h"
#include "../Modificadores/Barro.h"
#include "../Modificadores/Aceite.h"
#include "../Modificadores/Boost.h"
#include "../Modificadores/CajaDeSalud.h"
#include "../Modificadores/Piedra.h"


void Suelo::colocarExtra(MundoBox2D &mundoBox2D,
                         std::list<std::unique_ptr<Modificador>> &extras) {

    b2Vec2 posicion = cuerpo->GetPosition();
    int numeroDeExtra = rand() % 5;
    if (numeroDeExtra == 0) {
        extras.emplace_back(new Barro(mundoBox2D, posicion.x,posicion.y, extras.size()));
    } else if (numeroDeExtra == 1) {
        extras.emplace_back(new Aceite(mundoBox2D, posicion.x,posicion.y, extras.size()));
    } else if (numeroDeExtra == 2) {
        extras.emplace_back(new Boost(mundoBox2D, posicion.x,posicion.y, extras.size()));
    } else if (numeroDeExtra == 3) {
        extras.emplace_back(new CajaDeSalud(mundoBox2D, posicion.x,posicion.y, extras.size()));
    } else {
        extras.emplace_back(new Piedra(mundoBox2D, posicion.x,posicion.y, extras.size()));
    }
}

void Suelo::revivirCarro(MundoBox2D &mundoBox2D, Carro *unCarro) {
    b2Vec2 posicion = cuerpo->GetPosition();
    unCarro -> revivir(mundoBox2D, posicion.x, posicion.y);
}
