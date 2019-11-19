#include "Suelo.h"
#include "../Modificadores/Barro.h"


void Suelo::colocarExtra(MundoBox2D &mundoBox2D,
    std::list<std::unique_ptr<Modificador>> *extras) {
    b2Vec2 posicion = cuerpo->GetPosition();
    extras->emplace_back(new Barro(mundoBox2D, posicion.x,posicion.y, extras->size()));
}
