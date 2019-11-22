#ifndef _POSICION_H_
#define _POSICION_H_

#include <stack>

class Posicion {
private:
    int numeroDeVueltas;
    int numeroDeSuelo;
    std::stack<int> suelosPorLosQuePase;

    void actualizarSuelosPorLosQuePase(int nuevoNumeroDeSuelo);
public:
    Posicion();

    void actualizar(int nuevoNumeroDeSuelo);

    bool termineLaCarrera(int vueltasParaTerminar);

    int obtenerSueloParaRevivir();

    bool operator<= (const Posicion& otraposicion);

    ~Posicion();

};



#endif
