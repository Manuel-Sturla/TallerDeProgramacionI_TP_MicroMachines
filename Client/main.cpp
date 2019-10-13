#include <SDL2/SDL.h>
#include <iostream>
#include "Ventana.h"
#include "Textura.h"

int main(int argc, char** argv){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("No pude incializar el SDL %s", SDL_GetError());
        return 0;
    }
    try {
        Ventana ventana(600, 600);
        Textura textura("fondo.bmp", ventana.getRenderizador());
        Textura textura1("imagen.bmp", ventana.getRenderizador());
        textura.mostrar(1500);
        textura1.mostrar(1500);
    } catch(const std::runtime_error& e){
        std::cerr<<e.what()<<'\n';
        SDL_Quit();
        return 0;
    }
    SDL_Quit();
    return 0;
}