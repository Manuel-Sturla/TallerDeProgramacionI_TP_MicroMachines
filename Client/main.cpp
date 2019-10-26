#include <SDL2/SDL.h>
#include <iostream>
#include "Excepciones/ExcepcionConPos.h"
#include "Juego/Partida.h"

int main() {
    Servidor servidor(450, 450);
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("No pude incializar el SDL %s", SDL_GetError());
        return 0;
    }
    try {
        Partida partida(servidor);
        partida.iniciar();
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
        SDL_Quit();
        return 0;
    } catch (std::exception& e) {
        std::cerr<<e.what()<<'\n';
        SDL_Quit();
    } catch (...) {
        std::cerr<<"Error desconocido\n";
        SDL_Quit();
    }
    SDL_Quit();
    return 0;
}