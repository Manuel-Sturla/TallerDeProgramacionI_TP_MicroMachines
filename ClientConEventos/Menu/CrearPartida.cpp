//
// Created by diego on 23/11/19.
//

#include <QtWidgets/QMessageBox>
#include <iostream>
#include "CrearPartida.h"

CrearPartida::CrearPartida(QStackedWidget &menu, ServidorProxy &servidor, QWidget *parent) :\
servidor(servidor), menu(menu){
    Ui::CrearPartida crearPartida;
    crearPartida.setupUi(this);
    QObject::connect(findChild<QPushButton*>("pushButton"), &QPushButton::clicked, this, &CrearPartida::crearPartida);
}

void CrearPartida::crearPartida() {
    auto* aux = findChild<QLineEdit*>("nombre");
    std::string nombre, cantJugadores, cantVueltas;
    if(aux != nullptr){
        nombre = aux->text().toStdString();
    }
    aux = findChild<QLineEdit*>("cantJugadores");
    if(aux != nullptr){
        cantJugadores = aux->text().toStdString();
    }
    aux = findChild<QLineEdit*>("cantVueltas");
    if(aux != nullptr){
        cantVueltas = aux->text().toStdString();
    }
    int jugadores = 0;
    int vueltas = 0;
    try {
        jugadores = std::stoi(cantJugadores);
        vueltas = std::stoi(cantVueltas);
    } catch(std::invalid_argument& e){
        QMessageBox msgBox;
        msgBox.setText("Cantidad de vueltas o cantidad de jugadores invalida");
        msgBox.exec();
        return;
    }
    if(jugadores <= 0 || jugadores > 6){
        QMessageBox msgBox;
        msgBox.setText("La cantidad de jugadores debe estar entre 1 y 6");
        msgBox.exec();
        return;
    }
    if(vueltas <= 0 || vueltas > 10){
        QMessageBox msgBox;
        msgBox.setText("La cantidad de vueltas debe estar entre 1 y 10");
        msgBox.exec();
        return;
    }
    if(pista.empty()){
        QMessageBox msgBox;
        msgBox.setText("Debe seleccionar una pista para poder crear la partida");
        msgBox.exec();
        return;
    }
    servidor.crearPartida(nombre, cantJugadores, cantVueltas, pista);
    servidor.elegirPartida(nombre);
    QCoreApplication::quit();
}

void CrearPartida::setPistas(std::vector<std::string> &pistas) {
    if(!pistas.empty()){
        QObject::connect(findChild<QPushButton*>("pista1"), &QPushButton::clicked, this, &CrearPartida::elegirPista);
        findChild<QPushButton*>("pista1")->setText(QString::fromUtf8(pistas[0].c_str()));
    }
    if(pistas.size() > 1){
        QObject::connect(findChild<QPushButton*>("pista2"), &QPushButton::clicked, this, &CrearPartida::elegirPista);
        findChild<QPushButton*>("pista2")->setText(QString::fromUtf8(pistas[1].c_str()));
    }
    if(pistas.size() > 2){
        QObject::connect(findChild<QPushButton*>("pista3"), &QPushButton::clicked, this, &CrearPartida::elegirPista);
        findChild<QPushButton*>("pista3")->setText(QString::fromUtf8(pistas[2].c_str()));
    }
}

void CrearPartida::elegirPista() {
    auto* boton = qobject_cast<QPushButton*>(sender());
    pista = boton->text().toUtf8().constData();
}
