#include "boton.h"
#include "ventana.h"

#include <QApplication>


Boton::Boton(QWidget* ventana, std::string titulo, int posX, int posY, int tam)\
    : boton(titulo.c_str(), ventana){
    boton.setGeometry(posX, posY, tam, tam);
}

void Boton::conectar(){
    connect(&boton, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}
