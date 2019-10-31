#include <iostream>
#include <SocketActivo.h>
#include <SocketPasivo.h>
#include <sstream>
#include "Protocolo.h"

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
    /*
    std::string cadena("");
    std::vector<std::string> spliteado = separar(cadena, ';');
    for(auto cad: spliteado){
        std::cout << cad << " ";
    }
*/
    return 0;
}

