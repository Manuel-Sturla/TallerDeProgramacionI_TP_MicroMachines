#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/yaml.h>
#include <QtWidgets/QApplication>
#include <QtGui/QWindow>
#include "Excepciones/ExcepcionConPos.h"
#include "Vista/Visualizacion.h"
#include "Sockets/Utilidades.h"
#include "Jugador/JugadorCPU.h"
#include "Menu/Menu.h"

int aux(int argc, char* argv[], ServidorProxy& servidor, bool& esCpu){
    QApplication app (argc, argv);
    Menu menu(servidor, esCpu);
    menu.ejecutarMenu();
    return app.exec();
}

int menuConQT(int argc, char* argv[]) {
    ServidorProxy servidor;
    bool esCpu = false;
    aux(argc, argv, servidor, esCpu);
    std::shared_ptr<Jugador> jugador;
    if(esCpu){
        jugador = std::shared_ptr<Jugador>(new JugadorCPU("../Jugador/Lua/ScriptsLua/script.lua"));
    } else {
        jugador = std::shared_ptr<Jugador>(new JugadorReal());
    }
    YAML::Node config = YAML::LoadFile("../config.yaml")["configuraciones"];
    Visualizacion part(servidor, jugador, config["anchoPantalla"].as<int>(), \
    config["alturaPantalla"].as<int>(), config["fpsRenderizacion"].as<int>(), config["aumentoCamara"].as<int>());
    part.esperarInicioPartida();
    part.ejecutarPartida();
    return 0;
}

void menuSinQT(int argc, char *argv[]) {
    if(argc < 3){
        std::cerr<<"Cantidad de parametros incorrecta\n";
    }
    ServidorProxy servidor(argv[1], argv[2]);
    std::vector<std::string> pistas = servidor.obtenerPistas();
    std::cout<<"Pistas:\n";
    for (int i = 0; i < pistas.size(); ++i) {
        std::cout<<pistas[i]<<'\n';
    }
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
    if(!conectado && partida.size() < 3){
        std::cout<<"Datos ingresados incorrectos";
        return;
    }
    if(!conectado){
        servidor.crearPartida(partida[0], partida[1], partida[2], partida[3]);
        servidor.elegirPartida(partida[0]);
    }

//    std::shared_ptr<Jugador> jugador (new JugadorCPU("../Jugador/Lua/ScriptsLua/script.lua"));
    std::shared_ptr<Jugador> jugador (new JugadorReal());
    YAML::Node config = YAML::LoadFile("../config.yaml")["configuraciones"];
    Visualizacion part(servidor, jugador, config["anchoPantalla"].as<int>(), \
    config["alturaPantalla"].as<int>(), config["fpsRenderizacion"].as<int>(), config["aumentoCamara"].as<int>());
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
        menuConQT(argc, argv);
//        menuSinQT(argc, argv);
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