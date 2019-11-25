//
// Created by diego on 25/11/19.
//

#ifndef CLIENT_ELEGIRJUGADOR_H
#define CLIENT_ELEGIRJUGADOR_H


#include <QtWidgets/QStackedWidget>
#include "ui_elegirJugador.h"

class ElegirJugador : public QWidget {
private:
    bool& esCpu;
    QStackedWidget& menu;

public:
    ElegirJugador(QStackedWidget &menu, bool &esCpu, QWidget *parent = nullptr);

    void agregarCpu();

    void agregarJugador();
};


#endif //CLIENT_ELEGIRJUGADOR_H
