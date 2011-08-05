TEMPLATE = app

LIBS += -L../datastructure -ldatastructure
LIBS += -L../extract -lextract
LIBS += -lsqlite3

INCLUDEPATH += ../datastructure
INCLUDEPATH += ../extract

QT += xml

HEADERS += \
    MainWindow.h \
    MobilePhoneWidget.h

SOURCES += \
    MainWindow.cpp \
    MobilePhoneWidget.cpp \
    main.cpp

FORMS += \
    form.ui

TARGET = ../run
