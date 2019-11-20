#include "Visibilidad.h"

Visibilidad::Visibilidad() {
  visibilidadReducida = false;
  duracion = 0;
}

void Visibilidad::reducirVisibilidad() {
  visibilidadReducida = true;
  duracion += 250;
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

void Visibilidad::empaquetar(std::vector<std::string> *destino) {
    if (visibilidadReducida) {
        destino->emplace_back("Sucio");
    } else {
        destino-> emplace_back("Limpio");
    }
}

void Visibilidad::obtenerDatos(CarroDTO &dto) {
    dto.visibilidadReducida = visibilidadReducida;
    dto.duracionBarro = duracion;
}

void Visibilidad::actualizarDatos(CarroDTO_t &dto) {
    visibilidadReducida = dto.visibilidadReducida;
    duracion = dto.duracionBarro;
}
