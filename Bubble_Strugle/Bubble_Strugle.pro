TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        enemy.cpp \
        main.cpp \
        menu.cpp \
        player.cpp \
        scena.cpp \
        weapon.cpp \
        widgets.cpp

HEADERS += \
    defs.h \
    enemy.h \
    menu.h \
    player.h \
    scena.h \
    weapon.h \
    widgets.h
