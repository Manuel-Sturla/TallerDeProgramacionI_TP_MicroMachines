//
// Created by manfer on 19/11/19.
//

#include "ErrorFfmpeg.h"

ErrorFfmpeg::ErrorFfmpeg(const std::string &msg, const char *error, int linea, const char *archivo):
        runtime_error(msg + std::string(error) +" " + std::to_string(linea) + " : " + std::string(archivo)){
}

ErrorFfmpeg::ErrorFfmpeg(const std::string &msg, int linea, const char *archivo) :
        runtime_error(msg + " " + std::to_string(linea) + " : " + std::string(archivo)){


}
