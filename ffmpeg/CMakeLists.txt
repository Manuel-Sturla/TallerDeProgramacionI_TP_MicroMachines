cmake_minimum_required(VERSION 3.15)
project(ffmpeg)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(ffmpeg main.cpp
        Hilo.h
        Sdl/Area.cpp
        Sdl/Area.h
        Sdl/SdlException.cpp
        Sdl/SdlException.h
        Sdl/SdlTexture.cpp
        Sdl/SdlTexture.h
        Sdl/SdlWindow.cpp
        Sdl/SdlWindow.h
        GrabadorVideo.cpp GrabadorVideo.h VideoSalida.cpp VideoSalida.h Codec.cpp Codec.h ErrorFfmpeg.cpp ErrorFfmpeg.h Escalador.cpp Escalador.h Frame.cpp Frame.h BufferBloqueante.cpp BufferBloqueante.h HiloGrabador.cpp HiloGrabador.h)

target_link_libraries(ffmpeg avformat avcodec avutil swscale SDL2 SDL2_image)