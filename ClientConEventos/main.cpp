#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <QtWidgets/QApplication>
#include <SDL2/SDL_ttf.h>
#include "Excepciones/ExcepcionConPos.h"
#include "Menu/Lobby.h"
#include "Menu/Inicio.h"
#include "Vista/Visualizacion.h"
#include "Sockets/Utilidades.h"
#include "Jugador/JugadorReal.h"
#include "Jugador/JugadorCPU.h"

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

void menuConQT(int argc, char* argv[]) {
    std::string host, servicio;
    ejecutarInicio(argc, argv, host, servicio);
    ServidorProxy servidor(host, servicio);
    ejecutarLobby(argc, argv, servidor);
    //Inicializo un jugador
    std::shared_ptr<Jugador> jugador (new JugadorReal());
    Visualizacion partida(servidor, jugador);
    partida.esperarInicioPartida();
    partida.ejecutarPartida();
}

void menuSinQT(int argc, char *argv[]) {
    ServidorProxy servidor(argv[1], argv[2]);
    std::vector<std::string> partidas = servidor.obtenerPartidas();
    std::cout<<"Partidas:\n";
    for (int i = 0; i < partidas.size(); ++i) {
        std::cout<<partidas[i]<<'\n';
    }
    std::string aux;
    std::getline(std::cin, aux);
    std::vector<std::string> partida = separar(aux, ',');
    bool conectado = false;
    for (int i = 0; i < partidas.size(); ++i) {
        if(partida[0] == partidas[i]){
            servidor.elegirPartida(partida[0]);
            conectado = true;
        }
    }
    if(!conectado){
        servidor.crearPartida(partida[0], partida[1]);
        servidor.elegirPartida(partida[0]);
    }

//    std::shared_ptr<Jugador> jugador (new JugadorCPU("../Jugador/Lua/ScriptsLua/script.lua"));
    std::shared_ptr<Jugador> jugador (new JugadorReal());
    Visualizacion part(servidor, jugador);
    part.esperarInicioPartida();
    part.ejecutarPartida();
}

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0 || TTF_Init() == -1){
        SDL_Log("No pude incializar el SDL %s", SDL_GetError());
        return 0;
    } if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
        return 0;
    }
    try {
//        menuConQT(argc, argv);
        menuSinQT(argc, argv);
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