#include "utilidades.h"

Sumador::Sumador(std::vector<int>& vector): nums(vector){}

int Sumador::sumar(){
	int resultado = 0;
	for (int num : nums){
		resultado += num;
	}
	return resultado;
}