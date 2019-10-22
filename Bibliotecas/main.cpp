#include "BibliotecaEstatica/utilidades.h"
//#include "BibliotecaDinamica/PruebaMod.h"
#include <vector>
#include <iostream>
#include <dlfcn.h>
int main(){
    //Prueba biblioteca estatica
	std::vector<int> v = {1,2,3,4,5};
	Sumador sum(v);
	std::cout << "El sumador summo: "<<sum.sumar() << std::endl;

	//Prueba bliblioteca dinamica
	std::cout << "Inicio pruebas de libreria dinamica" << std::endl;

	void* handle = dlopen("lib/libPruebaMod.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    int (*sumar_1)(int);
    *(void **) (&sumar_1) = dlsym(handle, "sumar_1");

    int num = 2;
	std::cout << "El resultado es: " << (*sumar_1)(num) << std::endl;
	return 0;
}
