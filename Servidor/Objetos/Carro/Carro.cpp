#include "Carro.h"
#include "VelocidadBase.h"
#include "../../Acciones/GiroAIzquierda.h"
#include <iostream>

Carro::Carro(MundoBox2D &mundoBox2D, float32 velocidadMaxima, float32 aceleracion,
    float32 anguloDeGiro, float32  agarre, float32 x, float32 y, float32  anguloInicial,
    size_t idCliente):
estadoVelocidad(velocidadMaxima, aceleracion), agarre(agarre) {
  this -> anguloDeGiro = anguloDeGiro;
  idConductor = std::to_string(idCliente);
  agregarseA(mundoBox2D, x, y, anguloInicial);
  tipo = "Carro";
  coeficienteDeRozamiento = 0;
}

void Carro::agregarseA(MundoBox2D &pista, float32 x, float32 y, float32 anguloInicial) {
    if(!vida.estoyVivo()) {
        vida.revivir();
    }
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = anguloInicial;
    bodyDef.linearDamping = 0.5f;
    cuerpo = pista.agregarObjeto(&bodyDef);
    cuerpo -> SetUserData(this);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.5f, 0.5f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    cuerpo -> CreateFixture(&fixtureDef);
}

void Carro::ejecutarAccion(Accion &unaAccion) {
    unaAccion.ejecutar(*cuerpo, estadoVelocidad, anguloDeGiro);
}

void Carro::actualizar() {
    b2Vec2 fuerza(-coeficienteDeRozamiento * cuerpo->GetLinearVelocity().x, -coeficienteDeRozamiento *cuerpo->GetLinearVelocity().y);
    cuerpo -> ApplyLinearImpulseToCenter(fuerza, true);
    agarre.actualizar(*cuerpo);
    visibilidad.actualizar();
    estadoVelocidad.actualizar();
}

void Carro::aplicarFriccion(float32 coeficienteDeRozamiento) {
  this -> coeficienteDeRozamiento = coeficienteDeRozamiento;
}

void Carro::reducirVisibilidad() {
  visibilidad.reducirVisibilidad();
}

std::string Carro::darId() {
  return tipo;
}

void Carro::recibirDanio(int danio) {
  vida.recibirDanio(danio);
}

void Carro::curar(int aumentoDeVida) {
  vida.aumentarVida(aumentoDeVida);
}

void Carro::reducirVelocidad(float32 factor) {
    b2Vec2 fuerza(-factor * cuerpo->GetLinearVelocity().x, -factor *cuerpo->GetLinearVelocity().y);
    cuerpo -> ApplyLinearImpulseToCenter(fuerza, true);
}

void Carro::recibirBoost() {
  estadoVelocidad.boost();
}

void Carro::imprimirPosicion() {
  b2Vec2 position = cuerpo -> GetPosition();
  float32 angle = cuerpo -> GetAngle();
  b2Vec2 velocidad = cuerpo -> GetLinearVelocity();
  printf("Nueva iteracion\n");
  std::cout << "Posicion: " << position.x << " " << position.y << " " <<  angle << std::endl;
  std::cout << "Velocidad: " << velocidad.x << " " << velocidad.y << std::endl;
}

bool Carro::esValido() {
  return vida.estoyVivo();
}

void Carro::reducirAgarre() {
  agarre.reducirAgarre();
}

void Carro::empaquetar(std::vector<std::string> *destino) {
    empaquetarId(destino);
    empaquetarPosicion(destino);
    empaquetarAngulo(destino);
}

void Carro::actualizarPosicion(int numeroDeSuelo) {
    posicion.actualizar(numeroDeSuelo);
}

void Carro::interactuar(Carro *otroCarro) {
    otroCarro->recibirDanio(5);
}

bool Carro::operator<(const Carro &otroCarro) {
    return (this -> posicion < otroCarro.posicion);
}

std::string Carro::darIdConductor() {
    return idConductor;
}

bool Carro::termineCarrera(int cantidadDeVueltasParaTerminar) {
    return posicion.termineLaCarrera(cantidadDeVueltasParaTerminar);
}

int Carro::obtenerSueloParaRevivir() {
    return posicion.obtenerSueloParaRevivir();
}

void Carro::revivir(MundoBox2D &pista, float32 x, float32 y) {
    if (!vida.estoyVivo() && vida.puedoRevivir()) {
        agregarseA(pista, x, y, cuerpo -> GetAngle());
    }
}

void Carro::borrar() {
    vida.salirDeJuego();
}

bool Carro::moriRecientemente() {
    return vida.moriRecientemente();
}

void Carro::empaquetarVida(std::vector<std::string> *destino) {
    empaquetarId(destino);
    vida.empaquetar(destino);
}

void Carro::empaquetarId(std::vector<std::string> *destino) {
    destino -> emplace_back(idConductor);
}
