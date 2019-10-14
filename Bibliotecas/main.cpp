#include "BibliotecaEstatica/utilidades.h"
#include "BibliotecaDinamica/PruebaMod.h"
#include <vector>
#include <iostream>
int main(){
	std::vector<int> v = {1,2,3,4,5};
	Sumador sum(v);
	std::cout << "El sumador summo: "<<sum.sumar() << std::endl;

	std::cout << "Inicio pruebas de libreria dinamica" << std::endl;
	PruebaMod mod(v);
	mod.activar();
	std::cout << "El resultado del vector es: ";
	for (auto num : v)
		std::cout << num << ", ";
	std::cout << std::endl;
	return 0;
}
