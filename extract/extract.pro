TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../datastructure

HEADERS += \
    ExtractionException.h \
    AbstractMobilePhoneExtractor.h \
    AbstractAndroidExtractor.h \
    AndroidExtractorV2.h \
    SQLite3Connection.h \
    SQLiteException.h

SOURCES += \
    ExtractionException.cpp \
    AbstractMobilePhoneExtractor.cpp \
    AbstractAndroidExtractor.cpp \
    AndroidExtractorV2.cpp \
    SQLite3Connection.cpp \
    SQLiteException.cpp
