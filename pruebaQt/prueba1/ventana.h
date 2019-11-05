#ifndef VENTANA_H
#define VENTANA_H


#include "boton.h"
#include <QWidget>

class Ventana : public QWidget{
private:
    std::map<std::string, Boton*> botones;

public:
    Ventana(int ancho, int altura);

    void agregarBoton(std::string titulo, int posX, int posY, int tam);

    void conectar(std::string titulo);

    ~Ventana();
};

#endif // VENTANA_H
