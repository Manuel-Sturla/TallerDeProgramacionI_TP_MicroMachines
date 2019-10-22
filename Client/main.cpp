#include <SDL2/SDL.h>
#include <iostream>
#include "LectorTeclado.h"
#include "Comandos/AdministradorComandos.h"
#include "Excepciones/ExcepcionConPos.h"
#include "Sdl/Ventana.h"
#include "Sdl/Renderizador.h"

int main() {
    Servidor servidor;
    AdministradorComandos admin(servidor);
    SDL_Keycode comando = 0;
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("No pude incializar el SDL %s", SDL_GetError());
        return 0;
    }
    try {
        Ventana ventana("microMachines.exe", 640, 480);
        Renderizador renderizador(ventana);
        while(comando >= 0){
            comando = LectorTeclado::leer();
            admin.ejecutar(comando);
        }
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
        SDL_Quit();
        return 0;
    }
    SDL_Quit();
    return 0;
}