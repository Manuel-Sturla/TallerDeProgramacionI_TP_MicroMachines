#include <iostream>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_system.h>
#include <SDL2/SDL_messagebox.h>
#include <SDL2/SDL_events.h>
#include "Sdl/SdlWindow.h"
#include "Sdl/SdlTexture.h"
#include "GrabadorVideo.h"

#define ANCHO 352
#define ALTO 288

void handleSDLEvent(int &x, int &y, bool& running);


int main() {
    SdlWindow window(800, 600);
    window.fill();
    // Usar factory
    SdlTexture catTexture("cat.gif", window);
    Area srcArea(0, 0, 300, 300);
    bool running = true;
    int x = 0;
    int y = 0;
    // Textura sobre la que voy a renderizar lo que quiero grabar.
    SDL_Texture* videoTexture = SDL_CreateTexture(window.getRenderer(),\
                                                  SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_TARGET, ANCHO, ALTO);
    BufferBloqueante buffer;
    GrabadorVideo grabador (buffer);
    grabador.grabarVideo("prueba.mp4");
    while (running) {
        // Muevo textura con flechas direccionales
        handleSDLEvent(x, y, running);
        Area destArea(x, y, 160, 160);
        // Render sobre ventana
        SDL_SetRenderTarget(window.getRenderer(), NULL);
        window.fill(); // Repinto el fondo gris
        catTexture.render(srcArea, destArea);
        // Render sobre la textura que quiero guardar
        SDL_SetRenderTarget(window.getRenderer(), videoTexture);
        window.fill();
        catTexture.render(srcArea, destArea);
        // Efectivamente renderiza
        window.render();
        // Obtengo los bytes de la textura en el buffer
        std::vector<char> aux(ANCHO*ALTO*3);
        std::cout << "Llegue antes de renderizar pixeles" << std::endl;
        int res = SDL_RenderReadPixels(window.getRenderer(), NULL, SDL_PIXELFORMAT_RGB24, aux.data(), ANCHO * 3);
        std::cout << "El resultado de renderizar pixeles es: " << res << std::endl;

        if (res) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "RendererReadPixels error", SDL_GetError(), NULL);
            break;
        }
        buffer.guardar(aux);
        grabador.run();
    }
    return 0;
}

void handleSDLEvent(int &x, int &y, bool& running) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_KEYDOWN: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        x -= 1;
                        break;
                    case SDLK_RIGHT:
                        x += 1;
                        break;
                    case SDLK_UP:
                        y -= 1;
                        break;
                    case SDLK_DOWN:
                        y += 1;
                        break;
                }
            } // Fin KEY_DOWN
                break;
            case SDL_MOUSEMOTION:
                std::cout << "Oh! Mouse" << std::endl;
                break;
            case SDL_QUIT:
                std::cout << "Quit :(" << std::endl;
                running = false;
                break;
        }
    }