#include "BibliotecaEstatica/utilidades.h"
#include "LibreriaDinamica.h"
#include "ErrorLibreria.h"
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

	LibreriaDinamica libreria("lib/libPruebaMod.so");

    int (*sumar_1)(int);
    try{
        *(void**)(&sumar_1) = libreria.buscar_funcion("sumar_1");
        int num = 2;
        std::cout << "El resultado es: " << (*sumar_1)(num) << std::endl;
    }catch(ErrorLibreria &e){
        std::cerr << e.what() << std::endl;
    }


	return 0;
}
