QT -= gui
QT += opengl
CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    cgpu_draw.cpp

INCLUDEPATH += C:/Users/Didou/Downloads/glew-2.1.0-win32/glew-2.1.0/include
INCLUDEPATH += C:/Users/Didou/Downloads/SDL2-devel-2.0.9-VC/SDL2-2.0.9/include

LIBS += -LC:/Users/Didou/Downloads/glew-2.1.0-win32/glew-2.1.0/lib/Release/Win32/ -lglew32
LIBS += -LC:/Users/Didou/Downloads/glew-2.1.0-win32/glew-2.1.0/lib/Release/Win32/ -lglew32s

LIBS += -LC:/Users/Didou/Downloads/SDL2-devel-2.0.9-VC/SDL2-2.0.9/lib/x86/ -lSDL2
LIBS += -LC:/Users/Didou/Downloads/SDL2-devel-2.0.9-VC/SDL2-2.0.9/lib/x86/ -lSDL2main
LIBS += -LC:/Users/Didou/Downloads/SDL2-devel-2.0.9-VC/SDL2-2.0.9/lib/x86/ -lSDL2test

HEADERS += \
    cgpu_draw.h



