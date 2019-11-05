TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES +=  main.cpp \
    boton.cpp \
    ventana.cpp

HEADERS += \
    boton.h \
    ventana.h
