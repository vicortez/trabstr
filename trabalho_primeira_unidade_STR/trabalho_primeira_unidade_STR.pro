#-------------------------------------------------
#
# Project created by QtCreator 2017-08-29T21:02:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trabalho_primeira_unidade_STR
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    processo.cpp \
    conjunto_processos.cpp \
    processador.cpp \
    conjunto_processadores.cpp

HEADERS  += mainwindow.h \
    processo.h \
    conjunto_processos.h \
    processador.h \
    conjunto_processadores.h

FORMS    += mainwindow.ui

CONFIG += c++11
