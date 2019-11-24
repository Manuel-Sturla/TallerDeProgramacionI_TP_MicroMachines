//
// Created by manfer on 19/11/19.
//

#ifndef FFMPEG_ERRORFFMPEG_H
#define FFMPEG_ERRORFFMPEG_H


#include <stdexcept>

class ErrorFfmpeg: public std::runtime_error {

public:
    ErrorFfmpeg(const std::string& msg, const char *error, int linea, const char *archivo);
    ErrorFfmpeg(const std::string& msg, int linea, const char *archivo);
};


#endif //FFMPEG_ERRORFFMPEG_H
