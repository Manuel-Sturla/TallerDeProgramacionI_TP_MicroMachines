cmake_minimum_required(VERSION 3.15)
project(ffmpeg)

set(CMAKE_CXX_STANDARD 11)

add_executable(ffmpeg main.cpp GrabadorVideo.cpp GrabadorVideo.h VideoSalida.cpp VideoSalida.h Codec.cpp Codec.h ErrorFfmpeg.cpp ErrorFfmpeg.h Escalador.cpp Escalador.h Frame.cpp Frame.h)

target_link_libraries(ffmpeg avformat avcodec avutil swscale)