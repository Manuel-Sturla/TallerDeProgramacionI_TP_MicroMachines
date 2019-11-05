#include "ventana.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv){
    QApplication app (argc, argv);
    Ventana ventana(500, 500);
    ventana.agregarBoton("Hola", 10, 10, 100);
    ventana.agregarBoton("AAAA", 200, 200, 100);
    ventana.conectar("Hola");
    ventana.show();
    return app.exec();
}
