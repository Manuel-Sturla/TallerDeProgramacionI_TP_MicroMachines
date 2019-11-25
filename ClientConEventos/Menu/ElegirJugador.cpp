//
// Created by diego on 25/11/19.
//

#include "ElegirJugador.h"

ElegirJugador::ElegirJugador(QStackedWidget &menu, bool &esCpu, QWidget *parent) : esCpu(esCpu), menu(menu){
    Ui::ElegirJugador elegirJugador;
    elegirJugador.setupUi(this);
    QObject::connect(findChild<QPushButton*>("jugarCpu"), &QPushButton::clicked, this, &ElegirJugador::agregarCpu);
    QObject::connect(findChild<QPushButton*>("jugar"), &QPushButton::clicked, this, &ElegirJugador::agregarJugador);
}

void ElegirJugador::agregarCpu() {
    esCpu = true;
    menu.setCurrentIndex(2);
}

void ElegirJugador::agregarJugador() {
    menu.setCurrentIndex(2);
}
