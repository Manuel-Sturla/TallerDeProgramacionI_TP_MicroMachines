#include "EnviarPosiciones.h"
#include "../Utilidades.h"

EnviarPosiciones::EnviarPosiciones(Protocolo &protocolo, std::vector<std::string> &extras,
                                   std::vector<std::string> &autos) :
                                   protocolo(protocolo), extras(extras), autos(autos){

}
/*
std::string parsearExtra(Modificador& extra ){
    std::vector<std::string> elementos;
    elementos.push_back(extra.darId);
    elementos.push_back(std::to_string(extra.darPosicion())); //Ni idea de como es esto
    return unir(elementos, SEPARADOR);
}
*/
void EnviarPosiciones::ejecutar() {
    for (auto& extra : extras){
        protocolo.enviar(extra); //parsearExtra(extra);
    }
    protocolo.enviar(MSJ_FIN);
    for (auto& unAuto : autos){
        protocolo.enviar(unAuto);
    }
    protocolo.enviar(MSJ_FIN);
}
