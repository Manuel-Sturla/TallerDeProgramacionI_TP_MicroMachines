#ifndef _POSICION_H_
#define _POSICION_H_



class Posicion {
private:
    int numeroDeVueltas;
    int numeroDeSuelo;
public:
    Posicion();

    void actualizar(int nuevoNumeroDeSuelo);

    bool termineLaCarrera(int vueltasParaTerminar);

    int obtenerSueloParaRevivir();

    bool operator< (const Posicion& otraposicion);

    ~Posicion();

};



#endif
