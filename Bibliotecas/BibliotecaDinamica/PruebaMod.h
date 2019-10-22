#ifndef PRUEBA_MOD_H
#define PRUEBA_MOD_H

#include <stdlib.h>
#include <vector>

typedef struct PruebaMod{
	int modificador = 3;
	//std::vector<int>& numeros;
}PruebaMod_t;

extern "C"{
	void PruebaMod_crear(PruebaMod_t* self, int num);
	int PruebaMod_obtener_mod(PruebaMod_t* self);
}


#endif