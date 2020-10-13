TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L ./usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += $$PWD/../include

SOURCES += \
        main.cpp

HEADERS += \
    taruga.hpp \
    tarugainterpreter.hpp
