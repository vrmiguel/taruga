TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L ./usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += \
        src/main.cpp


DISTFILES += \
    data/turtle.png \
    data/turtle.tga \
    ruga \
    turtle.png

HEADERS += \
    include/taruga.hpp
