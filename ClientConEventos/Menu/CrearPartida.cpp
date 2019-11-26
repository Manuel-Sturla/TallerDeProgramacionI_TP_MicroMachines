//
// Created by diego on 23/11/19.
//

#include <QtWidgets/QMessageBox>
#include <iostream>
#include "CrearPartida.h"

CrearPartida::CrearPartida(QStackedWidget &menu, ServidorProxy &servidor, QWidget *parent) :\
servidor(servidor), menu(menu){
    std::cout << std::endl;
    Ui::CrearPartida crearPartida;
    crearPartida.setupUi(this);
    QObject::connect(findChild<QPushButton*>("pushButton"), &QPushButton::clicked, this, &CrearPartida::crearPartida);
}

void CrearPartida::crearPartida() {
    std::vector<std::string> pistas = servidor.obtenerPistas();
    std::cout << "Imprimo las pistas: " << pistas.size() << std::endl;
    for (auto& pista: pistas){
        std::cout << pista << ". ";
    }
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
    servidor.crearPartida(nombre, cantJugadores, cantVueltas, "Dona");
    servidor.elegirPartida(nombre);
    QCoreApplication::quit();
}
