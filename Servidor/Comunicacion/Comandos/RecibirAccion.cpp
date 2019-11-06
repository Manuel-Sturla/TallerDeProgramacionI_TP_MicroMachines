//
// Created by manfer on 5/11/19.
//

#include "RecibirAccion.h"
#include "../../Acciones/Acelerar.h"
#include "../../Acciones/Frenar.h"
#include "../../Acciones/GiroADerecha.h"
#include "../../Acciones/GiroAIzquierda.h"

#define MSJ_CMD_INVALIDO "Comando invalido"
#define CMD_ACELERAR "acelerar"
#define CMD_FRENAR "frenar"
#define CMD_DERECHA "doblar derecha"
#define CMD_IZQUIERDA "doblar izquierda"
#define SALIR "salir"

void RecibirAccion::ejecutar(ClienteProxy &cliente) {
    std::string accion = cliente.recibir();
    if (accion == CMD_ACELERAR){
        cliente.encolarAccion(new Acelerar());
    }else if (accion == CMD_FRENAR){
        cliente.encolarAccion(new Frenar());
    }else if (accion == CMD_DERECHA){
        cliente.encolarAccion(new GiroADerecha());
    }else if (accion == CMD_IZQUIERDA){
        cliente.encolarAccion(new GiroAIzquierda());
    }else if (accion == SALIR){
        cliente.desconectar();
    }
}

