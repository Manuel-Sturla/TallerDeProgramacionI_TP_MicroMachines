#include <thread>
#include "Pista.h"
#include "../Comunicacion/Eventos/EventosParseables/EventoParseable.h"
#include "../Comunicacion/Eventos/EventosParseables/EnviarCarro.h"
#include "../Comunicacion/Eventos/EventosParseables/EnviarExtra.h"
#include "../Objetos/Modificadores/CajaDeSalud.h"
#include "../Comunicacion/Eventos/EventosParseables/EnviarVida.h"

#define LONGITUD_DE_PISTA "4"

Material *Pista::darMaterial(const std::string& materialPedido) {
    if (materialPedido == "Asfalto") {
        return &asfalto;
    } else if (materialPedido == "Pasto"){
        return  &pasto;
    } else {
        return &limiteDePista;
    }
}

Pista::~Pista() {
}

void Pista::agregarRecta(std::string &material, float32 x, float32 y,
                         float32 angulo, int numeroDeSuelo) {
    if (material == "Asfalto") {
        BloquesDeasfalto.emplace(std::pair<int, std::unique_ptr<Suelo>>(numeroDeSuelo, new Recta(mundoBox2D, darMaterial(material), x, y, angulo, numeroDeSuelo) ));
    } else {
        rectas.emplace_back(mundoBox2D, darMaterial(material), x, y, angulo, numeroDeSuelo);
    }
}

void Pista::agregarCurva(float32 x, float32 y, float32 angulo, int numeroDeSuelo) {
    BloquesDeasfalto.emplace(std::pair<int, Suelo*>(numeroDeSuelo, new Curva(mundoBox2D, &asfalto, &pasto, x, y, angulo, numeroDeSuelo)));
}

void Pista::simular() {
    agregarExtra();
    std::list<Carro>::iterator itCarros;
    for (itCarros = carros.begin(); itCarros != carros.end(); itCarros++) {
        if (!itCarros->esValido()) {
            int numeroDeSuelo = itCarros->obtenerSueloParaRevivir();
            BloquesDeasfalto[numeroDeSuelo]->revivirCarro(mundoBox2D,
                                                          &*itCarros);
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
    float32 timeStep = 1.0f / 60.0f;
    int32 velocidadDeIteraciones = 6;
    int32 positionIterations = 2;
    mundoBox2D.simular(timeStep, velocidadDeIteraciones, positionIterations);
    mundoBox2D.actualizar();
    for (itCarros = carros.begin(); itCarros != carros.end(); itCarros++) {
        itCarros -> actualizar();
    }

}

void Pista::empaquetarCarro(std::vector<std::shared_ptr<EventoParseable>> *destino) {
    std::list<Carro>::iterator itCarros;
    for (itCarros = carros.begin(); itCarros != carros.end(); itCarros++) {
        destino->emplace_back(new EnviarCarro(*itCarros));
        destino->emplace_back(new EnviarVida(*itCarros));
    }
}
void Pista::empaquetarExtras(std::vector<std::shared_ptr<EventoParseable>> *destino) {
    for (auto& extra : extras){
        destino->emplace_back(new EnviarExtra(extra));
    }
}

void Pista::empaquetarSuelos(std::vector<std::string> *destino) {
    std::list<Recta>::iterator itRectas;
    destino -> emplace_back(LONGITUD_DE_PISTA);
    std::map<int, std::unique_ptr<Suelo>>::iterator itRectasDeAsfalto;
    for (itRectasDeAsfalto = BloquesDeasfalto.begin(); itRectasDeAsfalto != BloquesDeasfalto.end(); itRectasDeAsfalto++) {
        (itRectasDeAsfalto) -> second -> empaquetar(destino);
    }
    for (itRectas = rectas.begin(); itRectas != rectas.end(); itRectas++) {
        itRectas -> empaquetar(destino);
    }
}


Carro *Pista::crearCarro(float32 velocidad, float32 aceleracion,
                         float32 anguloDeGiroEnRadianes, float32 agarre, size_t id) {
    std::unique_lock<std::mutex> lock (mutex);
    b2Vec2 posicion = posicionesInicio.front();
    carros.emplace_back(mundoBox2D, velocidad, aceleracion, anguloDeGiroEnRadianes,
        agarre, posicion.x, posicion.y, anguloInicial, id);
    posicionesInicio.erase(posicionesInicio.begin());
    return &carros.back();
}

void Pista::agregarPosicionDeInicio(b2Vec2& posicion) {
    posicionesInicio.push_back(posicion);
}

void Pista::inicializarPodio(Podio &podio) {
    std::list<Carro>::iterator itCarros;
    for (itCarros = carros.begin(); itCarros != carros.end(); itCarros++) {
        podio.agregarCarro(&*itCarros);
    }
}

Pista::Pista() {
    this -> anguloInicial = 0;
}

void Pista::agregarExtra() {
    int numeroAleatorio = rand() % 100;
    if (numeroAleatorio == 1) {
        int sueloDeAsfalto = rand() % BloquesDeasfalto.size();
        BloquesDeasfalto[sueloDeAsfalto]->colocarExtra(mundoBox2D,
                                                      extras);
    }
}

void Pista::setAnguloInicial(float32 anguloInicialRecibido) {
    this -> anguloInicial = anguloInicialRecibido;
}

std::list<Carro> &Pista::obtenerCarros() {
    return carros;
}
