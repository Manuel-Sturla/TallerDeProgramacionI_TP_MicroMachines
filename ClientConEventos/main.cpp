#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <QtWidgets/QApplication>
#include <SDL2/SDL_ttf.h>
#include "Excepciones/ExcepcionConPos.h"
#include "Menu/Lobby.h"
#include "Menu/Inicio.h"
#include "Vista/HiloVisualizacion.h"

int ejecutarInicio(int argc, char* argv[], std::string& host, std::string& servicio){
    QApplication app(argc, argv);
    Inicio inicio(host, servicio);
    inicio.show();
    return QApplication::exec();
}

int ejecutarLobby(int argc, char* argv[], ServidorProxy& servidor){
    QApplication app(argc, argv);
    Lobby lobby(servidor);
    lobby.show();
    return QApplication::exec();
}

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0 || TTF_Init() == -1){
        SDL_Log("No pude incializar el SDL %s", SDL_GetError());
        return 0;
    } if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
        return 0;
    }
    std::string host, servicio;
    try {
        ejecutarInicio(argc, argv, host, servicio);
        ServidorProxy servidor(host, servicio);
        ejecutarLobby(argc, argv, servidor);
        HiloVisualizacion partida(servidor);
        partida.esperarInicioPartida();
        partida.ejecutarPartida();
    } catch(const ExcepcionConPos& e){
        std::cerr<<e.what()<<'\n';
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
        return 0;
    } catch (std::exception& e) {
        std::cerr<<e.what()<<'\n';
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
    } catch (...) {
        std::cerr<<"Error desconocido\n";
        IMG_Quit();
        TTF_Quit();
        SDL_Quit();
    }
    IMG_Quit();
    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}