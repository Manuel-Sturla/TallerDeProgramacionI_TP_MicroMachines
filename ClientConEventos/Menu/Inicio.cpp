//
// Created by diego on 6/11/19.
//

#include <iostream>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include "Inicio.h"
#include "Lobby.h"
#include "../Sockets/SocketPeerException.h"

Inicio::Inicio(QStackedWidget *menu, ServidorProxy &servidor,Lobby& lobby, QWidget *parent) :\
menu(menu), servidor(servidor), lobby(lobby) {
    Ui::Inicio inicio;
    inicio.setupUi(this);
    conectar();
}

void Inicio::conectar() {
    auto* boton = findChild<QPushButton*>("pushButton");
    if(!boton){
        std::cerr<<"Boton no encontrado\n";
    } else {
        QObject::connect(boton, &QPushButton::clicked,this, &Inicio::leerPantalla);
    }
}

void Inicio::leerPantalla() {
    auto* aux = findChild<QLineEdit*>("Servicio");
    std::string host, servicio;
    if(aux != nullptr){
        servicio = aux->text().toStdString();
    }
    aux = findChild<QLineEdit*>("Host");
    if(aux != nullptr){
        host = aux->text().toStdString();
    }
    try {
        servidor.conectar(host, servicio);
    } catch(SocketPeerException& e){
        QMessageBox msgBox;
        msgBox.setText("El servidor no existe");
        msgBox.exec();
        return;
    }
    lobby.copiarPartidas();
    menu->setCurrentIndex(1);
}
