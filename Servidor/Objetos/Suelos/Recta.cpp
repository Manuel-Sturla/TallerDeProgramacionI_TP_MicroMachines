#include "Recta.h"

Recta::Recta(MundoBox2D &pista, Material *unMaterial, float32 x, float32 y,
             float32 angulo, int numeroDeSuelo) {
    material = unMaterial;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    cuerpo = pista.agregarObjeto(&bodyDef);
    cuerpo -> SetUserData(this);
    b2PolygonShape cajaEstatica;
    cajaEstatica.SetAsBox(2.0f, 2.0f); //TAMANIO DE CUADRADO
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &cajaEstatica;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.isSensor = true;
    cuerpo -> CreateFixture(&fixtureDef);
    cuerpo -> SetTransform(cuerpo -> GetPosition(), angulo);
    this -> numeroDeSuelo = numeroDeSuelo;
    tipo = "Recta";
}

Recta::~Recta() {
}

void Recta::interactuar(Carro *unCarro) {
    material->interactuar(unCarro, numeroDeSuelo);
}

std::string Recta::darId() {
    return "Recta";
}

bool Recta::esValido() {
    return true;
}

Recta::Recta(Recta &&otraRecta) {
    this -> cuerpo = otraRecta.cuerpo;
    this -> material = otraRecta.material;
    this -> numeroDeSuelo = otraRecta.numeroDeSuelo;
    otraRecta.cuerpo = nullptr;
    otraRecta.material = nullptr;
}

Recta &Recta::operator=(Recta &&otraRecta) {
    if (this == &otraRecta) {
        return *this;
    }
    this -> cuerpo = otraRecta.cuerpo;
    this -> material = otraRecta.material;
    this -> numeroDeSuelo = otraRecta.numeroDeSuelo;
    otraRecta.cuerpo = nullptr;
    otraRecta.material = nullptr;
    return *this;
}

void Recta::empaquetar(std::vector<std::string> *destino) {
    material -> empaquetarMaterial(destino);
    empaquetarPosicion(destino);
    empaquetarAngulo(destino);
}
