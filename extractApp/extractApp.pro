TEMPLATE = app
TARGET = ../runExtract

QT += xml

CONFIG += ordered

LIBS += -lsqlite3
LIBS += -L../extract -lextract
LIBS += -L../datastructure -ldatastructure

INCLUDEPATH += ../datastructure
INCLUDEPATH += ../extract

SOURCES += \
    main.cpp
