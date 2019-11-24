//
// Created by manfer on 21/11/19.
//

#ifndef FFMPEG_BUFFERBLOQUEANTE_H
#define FFMPEG_BUFFERBLOQUEANTE_H


#include <vector>
#include <condition_variable>

class BufferBloqueante {
    std::vector<char> buffer;
    std::condition_variable tieneDatos;
    std::mutex mutex;
public:
    /* Guarda una copia de los datos en el buffer sobreescribiendo lo anterior*/
    void guardar(std::vector<char>& datos);

    /* Saca los elementos del buffer dejandolo vacío*/
    std::vector<char> sacar();
};


#endif //FFMPEG_BUFFERBLOQUEANTE_H
