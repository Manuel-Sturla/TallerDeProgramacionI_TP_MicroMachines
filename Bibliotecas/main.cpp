#include "BibliotecaEstatica/utilidades.h"
#include "BibliotecaDinamica.h"
#include "ErrorBiblioteca.h"
#include "Plugin.h"
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

	BibliotecaDinamica libreria("BibliotecaDinamica/libPruebaMod.so");


    Plugin plugin("BibliotecaDinamica/libPruebaMod.so");
    try{
        int num = 2;
        std::cout << "El resultado es: " << plugin.activar(num) << std::endl;
    }catch(ErrorBiblioteca &e){
        std::cerr << e.what() << std::endl;
    }


	return 0;
}
