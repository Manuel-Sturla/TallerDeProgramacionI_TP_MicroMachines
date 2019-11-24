#include "Curva.h"
#define FUERA_DE_CURVA 1
#define EN_ASFALTO 3
#define EN_PASTO 2

Curva::Curva(MundoBox2D &pista, Asfalto *asfalto, Pasto *pasto, float32 x,
             float32 y, float32 angulo, int numeroDeSuelo) {
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    cuerpo = pista.agregarObjeto(&bodyDef);
    agregarseAPista(pista, angulo);
    this -> asfalto = asfalto;
    this -> pasto = pasto;
    interaccion = FUERA_DE_CURVA;
    this -> numeroDeSuelo = numeroDeSuelo;
}

void Curva::agregarseAPista(MundoBox2D &pista, float32 angulo) {
    cuerpo -> SetUserData(this);
    b2PolygonShape caja;
    caja.SetAsBox(2.0f, 2.0f);
    b2FixtureDef fixtureCuadrado;
    fixtureCuadrado.shape = &caja;
    fixtureCuadrado.density = 0.0f;
    fixtureCuadrado.isSensor = true;
    fixtureCuadrado.userData = (void *) &cuadrado;
    cuerpo -> CreateFixture(&fixtureCuadrado);

    b2CircleShape circuloShape;
    circuloShape.m_p.Set(2.0,-2.0);
    circuloShape.m_radius = 4.0f; //DEPENDE DEL TAMANIO QUE VAYA A TENER LA PISTA
    b2FixtureDef fixtureCirculo;
    fixtureCirculo.shape = &circuloShape;
    fixtureCirculo.density = 0.0f;
    fixtureCirculo.isSensor = true;
    fixtureCirculo.userData = (void*) &circulo;
    cuerpo -> CreateFixture(&fixtureCirculo);
    cuerpo -> SetTransform(cuerpo -> GetPosition(), angulo);
}

std::string Curva::darId() {
    return "Curva";
}

void Curva::interactuar(Carro *unCarro) {
    if (interaccion == EN_ASFALTO) {
        asfalto->interactuar(unCarro, numeroDeSuelo);
    } else if (interaccion == EN_PASTO) {
        pasto->interactuar(unCarro, numeroDeSuelo);
    }
}

Curva::~Curva() {
}

void Curva::tipoDeInteraccion(int identificadorDeInteraccion) {
    interaccion = identificadorDeInteraccion;
}

bool Curva::esValido() {
    return true;
}

Curva::Curva(Curva &&otraCurva) {
    this -> cuerpo = otraCurva.cuerpo;
    this -> asfalto = otraCurva.asfalto;
    this -> pasto = otraCurva.pasto;
    this -> interaccion = otraCurva.interaccion;
    this -> numeroDeSuelo = otraCurva.numeroDeSuelo;
    otraCurva.cuerpo = nullptr;
    otraCurva.asfalto = nullptr;
    otraCurva.pasto = nullptr;
}

Curva &Curva::operator=(Curva &&otraCurva) {
    if (this == &otraCurva) {
        return *this;
    }
    this -> cuerpo = otraCurva.cuerpo;
    this -> asfalto = otraCurva.asfalto;
    this -> pasto = otraCurva.pasto;
    this -> interaccion = otraCurva.interaccion;
    this -> numeroDeSuelo = otraCurva.numeroDeSuelo;
    otraCurva.cuerpo = nullptr;
    otraCurva.asfalto = nullptr;
    otraCurva.pasto = nullptr;
    return  *this;
}

Curva::Curva(const Curva &otraCurva) {
    this -> cuerpo = otraCurva.cuerpo;
    this -> asfalto = otraCurva.asfalto;
    this -> pasto = otraCurva.pasto;
    this -> interaccion = otraCurva.interaccion;
    this -> numeroDeSuelo = otraCurva.numeroDeSuelo;
}

void Curva::empaquetar(std::vector<std::string> *destino) {
    destino -> emplace_back("Curva");
    empaquetarPosicion(destino);
    empaquetarAngulo(destino);
}

Curva &Curva::operator=(const Curva &otraCurva) {
    if (this == &otraCurva) {
        return *this;
    }
    this -> cuerpo = otraCurva.cuerpo;
    this -> asfalto = otraCurva.asfalto;
    this -> pasto = otraCurva.pasto;
    this -> numeroDeSuelo = otraCurva.numeroDeSuelo;
    this -> interaccion = otraCurva.interaccion;
    return *this;
}

void Curva::revivirCarro(MundoBox2D &mundoBox2D, Carro *unCarro) {
    b2Vec2 posicion = cuerpo->GetPosition();
    unCarro -> revivir(mundoBox2D, posicion.x, posicion.y);
}
