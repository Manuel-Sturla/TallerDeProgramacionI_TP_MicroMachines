//
// Created by diego on 25/11/19.
//

#ifndef CLIENT_COMANDOGRABAR_H
#define CLIENT_COMANDOGRABAR_H


#include <SDL2/SDL_stdinc.h>
#include "ComandoTeclado.h"
#include "../GrabadorVideo/GrabadorVideo.h"

class ComandoGrabar : public ComandoTeclado {
private:
    bool grabando;
    GrabadorVideo& grabador;
    int cantVideos;

public:
    explicit ComandoGrabar(GrabadorVideo& grabador, ServidorProxy &servidor, const Uint8* estados);

    void ejecutar() override;

    void apretar() override;

    void desapretar() override;
};


#endif //CLIENT_COMANDOGRABAR_H
