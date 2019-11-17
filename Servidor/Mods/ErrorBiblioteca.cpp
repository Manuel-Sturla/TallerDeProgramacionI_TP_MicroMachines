//
// Created by manfer on 17/11/19.
//

#include <string>
#include "ErrorBiblioteca.h"

ErrorBiblioteca::ErrorBiblioteca(const std::string& msj) : runtime_error(msj){
}

ErrorBiblioteca::ErrorBiblioteca(const std::string& msj, const std::string& biblioteca, char *error, int linea,
                                 const char *archivo) :
        runtime_error(msj + " \""+ biblioteca +"\": " + std::string(error) +\
                                 " " + std::to_string(linea) + ":" + std::string(archivo)){

}
