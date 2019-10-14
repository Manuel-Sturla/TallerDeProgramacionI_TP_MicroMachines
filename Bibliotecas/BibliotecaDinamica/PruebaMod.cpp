#include "PruebaMod.h"

PruebaMod::PruebaMod(std::vector<int>& v): numeros(v){}

void PruebaMod::activar(){
	for (int& num : numeros)
		num = num * modificador;
}