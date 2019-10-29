#include "Visibilidad.h"

Visibilidad::Visibilidad() {
  visibilidadReducida = false;
  duracion = 0;
}

void Visibilidad::reducirVisibilidad() {
  visibilidadReducida = true;
  duracion = 5;
}

void Visibilidad::actualizar() {
  if (visibilidadReducida) {
    actualizarVisibilidadReducida();
  }
}

void Visibilidad::actualizarVisibilidadReducida() {
  duracion -= 1;
  if (duracion == 0) {
    visibilidadReducida = false;
  }
}

Visibilidad::~Visibilidad() {
}
