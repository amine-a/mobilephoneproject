TEMPLATE = app
TARGET = ../runDatastructure

LIBS += -L../datastructure -ldatastructure

QT += xml

INCLUDEPATH += ../datastructure

SOURCES += \
    main.cpp
