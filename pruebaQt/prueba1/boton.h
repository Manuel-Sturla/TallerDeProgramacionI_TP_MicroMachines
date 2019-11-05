#ifndef BOTON_H
#define BOTON_H

#include <QPushButton>

class Boton : public QPushButton {
private:
    QPushButton boton;

public:
    Boton(QWidget* ventana, std::string titulo, int posX, int posY, int tam);

    void conectar();
};

#endif // BOTON_H
