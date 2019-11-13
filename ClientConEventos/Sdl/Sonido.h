//
// Created by diego on 13/11/19.
//

#ifndef CLIENT_SONIDO_H
#define CLIENT_SONIDO_H


#include <string>
#include <SDL2/SDL_mixer.h>

class Sonido {
private:
    Mix_Music *sonido;

public:
    explicit Sonido(std::string archivo);

    virtual ~Sonido();
};


#endif //CLIENT_SONIDO_H
