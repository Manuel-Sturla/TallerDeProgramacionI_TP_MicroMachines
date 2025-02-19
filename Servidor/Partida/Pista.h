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
#include "../Comunicacion/Eventos/EventosParseables/EventoParseable.h"
#include "Podio.h"
#include "../Objetos/Modificadores/Modificador.h"


class Pista {
private:
    MundoBox2D mundoBox2D;
    Asfalto asfalto;
    Pasto pasto;
    LimiteDePista limiteDePista;
    float32 anguloInicial;
    std::map<int, std::unique_ptr<Suelo>> BloquesDeasfalto;
    std::list<std::unique_ptr<Modificador>> extras;
    std::list<b2Vec2> posicionesInicio;
    std::list<Recta> rectas;
    std::list<Carro> carros;
    std::mutex mutex;

    Material* darMaterial(const std::string& materialPedido);
    void agregarExtra();

public:
    Pista();

    void simular();

    Carro *crearCarro(float32 velocidad, float32  aceleracion, float32
    anguloEnRadianes, float32 agarre, size_t id);

    void empaquetarCarro(std::vector<std::shared_ptr<EventoParseable>> *destino);
    void empaquetarExtras(std::vector<std::shared_ptr<EventoParseable>> * destino);
    void empaquetarSuelos(std::vector<std::string> *destino);

    void agregarPosicionDeInicio(b2Vec2 &posicion);

    void setAnguloInicial(float32 anguloInicialRecibido);

    void
    agregarRecta(std::string &material, float32 x, float32 y, float32 angulo, int numeroDeSuelo);

    void agregarCurva(float32 x, float32 y, float32 angulo, int numeroDeSuelo);

    void inicializarPodio(Podio &podio);

    std::list<Carro>& obtenerCarros();
    ~Pista();
};



#endif
