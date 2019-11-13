//
// Created by diego on 13/11/19.
//

#include "Sonido.h"
#include "../Excepciones/ExcepcionConPos.h"

Sonido::Sonido(std::string archivo) {
    sonido = Mix_LoadMUS(archivo.c_str());
    if(sonido == nullptr){
        throw  ExcepcionConPos(__FILE__, __LINE__, "Archivo de sonido no encontrado");
    }
    Mix_PlayMusic( sonido, 1 );
}

Sonido::~Sonido() {
    Mix_FreeMusic(sonido);
}
