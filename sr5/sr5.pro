#-------------------------------------------------
#
# Project created by QtCreator 2015-02-11T18:04:10
#
#-------------------------------------------------

QT       += core gui \
            testlib
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sr5
TEMPLATE = app


SOURCES += main.cpp\
        shadowruntool.cpp \
    reader.cpp \
    inventory.cpp \
    programms.cpp \
    skills.cpp

HEADERS  += shadowruntool.h \
    reader.h \
    inventory.h \
    programms.h \
    skills.h

FORMS    += shadowruntool.ui \
    inventory.ui
