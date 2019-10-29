#include "BibliotecaEstatica/utilidades.h"
#include "BibliotecaDinamica.h"
#include "ErrorBiblioteca.h"
#include "Plugin.h"
#include "ModAuto.h"
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
    Plugin plugin("BibliotecaDinamica1/libPruebaMod.so");
    try{
        int num = 2;
        std::cout << "El resultado es: " << plugin.activar(num) << std::endl;
    }catch(ErrorBiblioteca &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Pruebo BD con casteo a clase" << std::endl;
    ModAuto mod("BibliotecaDinamica2/libBoost.so");
    float vel = 50;
    Carro carro(vel);
    mod.activar(carro);
    std::cout << "Velocidad antes de mod: " << vel << ", velocidad despues: " << carro.obtenerVelicidadMax() << std::endl;
	return 0;
}
