#include "PruebaMod.h"

void PruebaMod_crear(PruebaMod_t* self, int num){
    self->modificador = num;
}

int PruebaMod_obtener_mod(PruebaMod_t* self){
    return self->modificador;
}