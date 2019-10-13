cmake_minimum_required(VERSION 3.6)
project(OpenGLTest)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp Textura.cpp Textura.h Ventana.cpp Ventana.h)
add_executable(OpenGLTest ${SOURCE_FILES})

target_link_libraries(OpenGLTest SDL2main SDL2 SDL2_image)

install(FILES assets/cat.gif DESTINATION ${CMAKE_BINARY_DIR})