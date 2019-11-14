#include <sstream>
#include "Utilidades.h"

std::string unir(const std::vector<std::string>& elementos, char separador){
    std::string retorno;
    for (auto& cad : elementos){
        retorno.append(cad);
        retorno.append(1,separador);
    }
    return retorno;
}

std::vector<std::string> separar(std::string& cadena, char sep){
    std::vector<std::string> resultado;
    std::istringstream iss(cadena);
    while(iss.good()){
        std::string aux;
        std::getline(iss, aux, sep);
        if (aux == ""){
            continue;
        }
        resultado.push_back(aux);
    }
    return resultado;
}