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
        renderizador.agregarFondo("pista.png");
        SDL_Rect pos;
        pos.x = 100;
        pos.y = 100;
        pos.w = 100;
        pos.h = 100;
        renderizador.agregarTextura("auto.png", &pos);
        while(comando >= 0){
            comando = LectorTeclado::leer();
            admin.ejecutar(comando);
            renderizador.imprimir();
        }
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