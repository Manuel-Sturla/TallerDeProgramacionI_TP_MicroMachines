#ifndef _PISTA_H_
#define _PISTA_H_

#include <list>
#include <map>
#include <mutex>
#include "../Objetos/Suelos/Pasto.h"
#include "../Objetos/Suelos/Asfalto.h"
#include "../Objetos/Suelos/LimiteDePista.h"
#include "../Objetos/Suelos/Recta.h"
#include "../Objetos/Suelos/Curva.h"
#include "../Comunicacion/Eventos/EventosParseables/EventosParseables.h"
#include "Podio.h"

class Pista {
private:
    MundoBox2D mundoBox2D;
    Asfalto asfalto;
    Pasto pasto;
    LimiteDePista limiteDePista;
    std::map<int, std::unique_ptr<Suelo>> BloquesDeasfalto;
    std::list<b2Vec2> posicionesInicio;
    std::list<Recta> rectas;
    std::list<Carro> carros;
    std::mutex mutex;

    Material* darMaterial(const std::string& materialPedido);

public:
    Pista() = default;

    void simular();

    Carro *crearCarro(int velocidad, float32 anguloEnRadianes, int agarre);

    int cantidadDeCarros();

    void empaquetarCarro(std::vector<std::shared_ptr<EventosParseables>> *destino);

    void empaquetarSuelos(std::vector<std::string> *destino);

    void agregarPosicionDeInicio(b2Vec2 &posicion);

    void
    agregarRecta(std::string &material, float32 x, float32 y, float32 angulo, int numeroDeSuelo);

    void agregarCurva(float32 x, float32 y, float32 angulo, int numeroDeSuelo);

    void inicializarPodio(Podio *podio);

    ~Pista();
};



#endif
