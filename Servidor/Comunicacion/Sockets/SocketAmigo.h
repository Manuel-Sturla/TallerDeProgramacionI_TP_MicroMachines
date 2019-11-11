#ifndef _SOCKET_AMIGO_H_
#define _SOCKET_AMIGO_H_

#include <string>

class SocketAmigo {
  protected:
    int fd;

  public:
    explicit SocketAmigo(int aFd);

    SocketAmigo(SocketAmigo&& other);

    SocketAmigo& operator=(SocketAmigo&& other);

    void enviarLongitud(unsigned int longitud);

    unsigned int recibirLongitud();

    void enviar(std::string message);

    void recibir(std::string& answer, size_t lenght);

    void cerrar();

    ~SocketAmigo();
};


#endif
