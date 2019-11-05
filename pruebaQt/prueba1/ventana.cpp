#include "ventana.h"
#include "boton.h"
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <iostream>

Ventana::Ventana(int ancho, int altura){
    setFixedSize(ancho, altura);
}

void Ventana::agregarBoton(std::string titulo, int posX, int posY, int tam){
    auto* boton = new Boton(this, titulo, posX, posY, tam);
    botones.insert(std::pair<std::string, Boton*>(titulo, boton));
}

void Ventana::conectar(std::string titulo){
    auto it = botones.find(titulo);
    if(it == botones.end()){
        std::cerr<<"Boton invalido\n";
        return;
    }
    it->second->conectar();
/*    connect(botones[0], SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setGeometry(10, 10, 180, 30);


    QSlider *slider = new QSlider(this);
     slider->setOrientation(Qt::Horizontal);
     slider->setRange(0, 100);
     slider->setValue(0);
     slider->setGeometry(10, 40, 180, 30);

     QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));*/
}

Ventana::~Ventana(){
    for(auto boton : botones){
        delete(boton.second);
    }
}
