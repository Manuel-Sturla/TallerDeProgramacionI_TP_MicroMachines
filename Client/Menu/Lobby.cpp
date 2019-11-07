//
// Created by diego on 6/11/19.
//

#include "Lobby.h"

Lobby::Lobby(ServidorProxy &servidor) : servidor(servidor) {
    Ui::Lobby lobby;
    lobby.setupUi(this);
    std::vector<std::string> partidas = servidor.obtenerPartidas();
    copiarPistas(partidas);
    conectar();
}

void Lobby::conectar() {
    QObject::connect(findChild<QPushButton*>("crear"), &QPushButton::clicked, this, &Lobby::crearPartida);
    QObject::connect(findChild<QPushButton*>("pista1"), &QPushButton::clicked, this, &Lobby::unirPartida);
    QObject::connect(findChild<QPushButton*>("pista2"), &QPushButton::clicked, this, &Lobby::unirPartida);
    QObject::connect(findChild<QPushButton*>("pista3"), &QPushButton::clicked, this, &Lobby::unirPartida);
    QObject::connect(findChild<QPushButton*>("pista4"), &QPushButton::clicked, this, &Lobby::unirPartida);
    QObject::connect(findChild<QPushButton*>("pista5"), &QPushButton::clicked, this, &Lobby::unirPartida);
}

void Lobby::crearPartida() {
    std::string nombre = findChild<QLineEdit*>("nombre")->text().toStdString();
    int cantJugadores = std::stoi(findChild<QLineEdit*>("cantJug")->text().toStdString());
    servidor.crearPartida(nombre, cantJugadores);
}

void Lobby::copiarPistas(std::vector<std::string> &partidas) {
    if(!partidas.empty()){
        findChild<QPushButton*>("partida1")->setText(QString::fromUtf8(partidas[0].c_str()));
    } else if(partidas.size() > 1){
        findChild<QPushButton*>("partida2")->setText(QString::fromUtf8(partidas[0].c_str()));
    } else if(partidas.size() > 2){
        findChild<QPushButton*>("partida3")->setText(QString::fromUtf8(partidas[0].c_str()));
    } else if(partidas.size() > 3){
        findChild<QPushButton*>("partida4")->setText(QString::fromUtf8(partidas[0].c_str()));
    } else if(partidas.size() > 4){
        findChild<QPushButton*>("partida5")->setText(QString::fromUtf8(partidas[0].c_str()));
    }
}

void Lobby::unirPartida() {

}


