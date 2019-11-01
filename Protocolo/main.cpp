#include <iostream>
#include <SocketActivo.h>
#include <SocketPasivo.h>
#include <sstream>
#include <zconf.h>
#include "Protocolo.h"
#include "ServidorProxy.h"
#include "ClienteProxy.h"
#include "Utilidades.h"
#include "Hilos/HiloServidor.h"
#include "Hilos/HiloCliente.h"

int main() {
    /*std::cout << "Inicio pruebas socket activo" <<std::endl;
    SocketActivo socket;
    socket.conectar("localhost", "5555");
    socket.enviar("");
    socket.enviar("12345678910");
    std::string recibido;
    socket.recibir(recibido, 10);
    std::cout << "Recibi: " + recibido << std::endl;
    socket.recibir(recibido, 0);
    std::cout << "Recibi2: " + recibido + "." << std::endl;
*/
/*    std::cout << "Inicio pruebas socket pasivo" << std::endl;
    SocketPasivo aceptador;
    aceptador.unirse("5555");
    aceptador.escuchar();
    SocketAmigo socketCliente = aceptador.aceptarCliente();
    std::string recibido;
    socketCliente.recibir(recibido, 0);
    std::cout << "Recibi: " + recibido << std::endl;
    */
    /*SocketActivo socket3;
    socket3.conectar("localhost", "5555");
    Protocolo protocolo(socket3);
    protocolo.enviar("Hola como va");
    protocolo.enviar("");
    protocolo.enviar(".\n");
    std::cout << "Recibi: " << protocolo.recibir() << std::endl;
*/
    std::string cadena("");
    std::vector<std::string> spliteado = separar(cadena, ';');
    for(auto cad: spliteado){
        std::cout << cad << " ";
    }
    std::cout << std::endl;
    std::string aux = unir({"a", "b",""}, ';');
    std::cout << "Joineado: " << aux << std::endl;
  /*  SocketPasivo socketPasivo;
    socketPasivo.unirseYEscuchar("5555");

    ClienteProxy proxy(socketPasivo.aceptarCliente());
    std::cout << proxy.obtenerComando() << std::endl;*/
    std::cout << "INICIO PRUEBAS PROXIS" << std::endl;
    HiloServidor hiloServidor("5555");
    hiloServidor.start();
//sleep(1);
    HiloCliente hiloCliente("localhost", "5555");
  //  sleep(1);
    hiloCliente.start();
    hiloCliente.join();
    hiloServidor.join();
    return 0;
}

