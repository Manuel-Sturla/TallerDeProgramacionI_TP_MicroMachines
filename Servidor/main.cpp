#include "Servidor.h"

int main(int argc, char** argv) {
    if (argc != 2){
        std::cout << "Eventos invalidos\n";
        return 1;
    }
    try{
        Servidor servidor(argv[1]);
        std::cout << "Cree el servidor" << std::endl;
        servidor.start();
        char c = '0';
        do{
            std::cin.get(c);
            //Saco el \n restante
            std::cin.get();
        }while (c != 'q');
        servidor.apagar();
        servidor.join();
    }catch (std::runtime_error &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }catch (...){
        std::cerr << "Error desconocido" << std::endl;
    }
    return 0;
}