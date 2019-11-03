#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "Excepciones/ExcepcionConPos.h"
#include "Juego/Partida.h"
#include "HiloMenu.h"

int main(int argc, char const* argv[]) {
    if(argc != 3){
        std::cout<<"Uso correcto ./client host servicio\n";
        return 1;
    }
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("No pude incializar el SDL %s", SDL_GetError());
        return 0;
    }
    try {
        ServidorProxy servidor(argv[1], argv[2]);
        Renderizador renderizador("micromachines.exe", 1000, 1000);
        HiloLector lector(servidor);
        lector.start();
        bool enMenu = true;
/*        HiloMenu menu(servidor, enMenu);
        menu.start();
        renderizador.agregarTextura("inicio.jpeg", nullptr);
        Camara cam(100);
        renderizador.copiarTodo(cam);
        while(enMenu){
            renderizador.imprimir(20);
        }
        menu.join();*/
        bool enPartida = true;
        HiloVisualizacion partida(servidor, enPartida);
        partida.start();
        partida.join();
        lector.join();
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
        IMG_Quit();
        SDL_Quit();
        return 0;
    } catch (std::exception& e) {
        std::cerr<<e.what()<<'\n';
        IMG_Quit();
        SDL_Quit();
    } catch (...) {
        std::cerr<<"Error desconocido\n";
        IMG_Quit();
        SDL_Quit();
    }
    IMG_Quit();
    SDL_Quit();
    return 0;
}