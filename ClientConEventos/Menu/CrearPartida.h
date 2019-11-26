//
// Created by diego on 23/11/19.
//

#ifndef MENUQT20_CREARPARTIDA_H
#define MENUQT20_CREARPARTIDA_H

#include "ui_crearPartida.h"
#include "../Sockets/ServidorProxy.h"
#include <QtWidgets/QStackedWidget>

class CrearPartida : public QWidget {
private:
    ServidorProxy& servidor;
    QStackedWidget& menu;
    std::string pista;
public:
    CrearPartida(QStackedWidget &menu, ServidorProxy &servidor, QWidget *parent = nullptr);

    void crearPartida();

    void setPistas(std::vector<std::string>& pistas);

    void elegirPista();
};


#endif //MENUQT20_CREARPARTIDA_H
