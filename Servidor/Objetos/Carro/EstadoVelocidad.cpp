#include "EstadoVelocidad.h"

EstadoVelocidad::EstadoVelocidad(float32 velocidadMaxima, float32 aceleracion):
velocidadBase(velocidadMaxima, aceleracion), velocidadBoost(velocidadMaxima, aceleracion) {
  estados["Base"] = &velocidadBase;
  estados["Boost"] = &velocidadBoost;
  estadoActual = "Base";
}

void EstadoVelocidad::boost() {
  estadoActual = estados[estadoActual] -> boost();
}

bool EstadoVelocidad::alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual) {
  return estados[estadoActual] -> alcanzoLaVelocidadMaxima(velocidadActual);
}

void EstadoVelocidad::actualizar() {
  estadoActual = estados[estadoActual] -> actualizar();
}

EstadoVelocidad::~EstadoVelocidad() {
}

void EstadoVelocidad::acelerar(b2Body &cuerpo) {
    b2Vec2 velocidad = cuerpo.GetLinearVelocity();
    if (!alcanzoLaVelocidadMaxima(velocidad)) {
        aplicarFuerza(cuerpo, estados[estadoActual] -> darImpulso());
    }
}

void EstadoVelocidad::aplicarFuerza(b2Body &cuerpo, float32 factorDeFuerza) {
    float32 angulo = cuerpo.GetAngle();
    b2Vec2 fuerza(factorDeFuerza * cos(angulo), factorDeFuerza * sin(angulo));
    cuerpo.ApplyLinearImpulseToCenter(fuerza, true);
}

void EstadoVelocidad::frenar(b2Body &cuerpo) {
    b2Vec2 velocidad = cuerpo.GetLinearVelocity();
    if (!alcanzoLaVelocidadMaxima(velocidad)) {
        aplicarFuerza(cuerpo, -estados[estadoActual] -> darImpulso());
    }
}

void EstadoVelocidad::obtenerDatos(CarroDTO &dto) {
    estados["Base"]->obtenerDatos(dto);
    dto.boost = estadoActual == "Boost";
}

void EstadoVelocidad::actualizarDatos(CarroDTO_t &dto) {
    //Por ahora solo actualiza la velocidad maxima de la vel Base
    velocidadBase.actualizarDatos(dto);
    if (dto.boost && (estadoActual!="Boost")){
        boost();
    }
}
