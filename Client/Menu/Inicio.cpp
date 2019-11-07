//
// Created by diego on 6/11/19.
//

#include <iostream>
#include "Inicio.h"

Inicio::Inicio(std::string &host, std::string& servicio, QWidget* parent) :\
host(host), servicio(servicio) {
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
        QObject::connect(boton, &QPushButton::clicked,this, &QWidget::close);
    }
}

void Inicio::leerPantalla() {
    auto* aux = findChild<QLineEdit*>("Servicio");
    if(aux != nullptr){
        host = aux->text().toStdString();
    }
    aux = findChild<QLineEdit*>("Host");
    if(aux != nullptr){
        servicio = aux->text().toStdString();
    }
}
