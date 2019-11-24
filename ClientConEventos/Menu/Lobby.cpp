//
// Created by diego on 6/11/19.
//

#include <iostream>
#include "Lobby.h"

Lobby::Lobby(QStackedWidget &menu, ServidorProxy &servidor, QWidget *parent) : servidor(servidor), menu(menu) {
    Ui::Lobby lobby;
    lobby.setupUi(this);
    conectar();
}

void Lobby::conectar() {
    QObject::connect(findChild<QPushButton*>("crear"), &QPushButton::clicked, this, &Lobby::crearPartida);
}

void Lobby::crearPartida() {
    menu.setCurrentIndex(2);
}

void Lobby::copiarPartidas() {
    std::vector<std::string> partidas = servidor.obtenerPartidas();
    if(!partidas.empty()){
        QObject::connect(findChild<QPushButton*>("pista1"), &QPushButton::clicked, this, &Lobby::unirPartida);
        findChild<QPushButton*>("pista1")->setText(QString::fromUtf8(partidas[0].c_str()));
    }
    if(partidas.size() > 1){
        QObject::connect(findChild<QPushButton*>("pista2"), &QPushButton::clicked, this, &Lobby::unirPartida);
        findChild<QPushButton*>("pista2")->setText(QString::fromUtf8(partidas[1].c_str()));
    }
    if(partidas.size() > 2){
        QObject::connect(findChild<QPushButton*>("pista3"), &QPushButton::clicked, this, &Lobby::unirPartida);
        findChild<QPushButton*>("pista3")->setText(QString::fromUtf8(partidas[2].c_str()));
    }
    if(partidas.size() > 3){
        QObject::connect(findChild<QPushButton*>("pista4"), &QPushButton::clicked, this, &Lobby::unirPartida);
        findChild<QPushButton*>("pista4")->setText(QString::fromUtf8(partidas[3].c_str()));
    }
    if(partidas.size() > 4){
        QObject::connect(findChild<QPushButton*>("pista5"), &QPushButton::clicked, this, &Lobby::unirPartida);
        findChild<QPushButton*>("pista5")->setText(QString::fromUtf8(partidas[4].c_str()));
    }
}

void Lobby::unirPartida() {
    auto* boton = qobject_cast<QPushButton*>(sender());
}
