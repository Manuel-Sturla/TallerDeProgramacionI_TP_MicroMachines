#ifndef _PISTA_H_
#define _PISTA_H_

#include <list>
#include "../Objetos/Suelos/Pasto.h"
#include "../Objetos/Suelos/Asfalto.h"
#include "../Objetos/Suelos/LimiteDePista.h"
#include "../Objetos/Suelos/Recta.h"
#include "../Objetos/Suelos/Curva.h"
class Pista {
private:
    MundoBox2D mundoBox2D;
    Asfalto asfalto;
    Pasto pasto;
    LimiteDePista limiteDePista;
    std::list<Recta> rectas;
    std::list<Curva> curvas;
    std::list<Carro> carros;

    Material* darMaterial(const std::string& materialPedido);

public:
    Pista() = default;

    void simular();

    Carro *crearCarro(int velocidad, float32 anguloEnRadianes, int agarre);

    int cantidadDeCarros();

    void empaquetarCarro(std::vector<std::string> *destino);

    void empaquetarSuelos(std::vector<std::string> *destino);

    void
    agregarRecta(std::string &material, float32 x, float32 y, float32 angulo);

    void agregarCurva(float32 x, float32 y, float32 angulo);

    ~Pista();
};



#endif
