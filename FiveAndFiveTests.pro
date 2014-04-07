#-------------------------------------------------
#
# Project created by QtCreator 2014-04-07T10:26:50
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_FiveAndFiveTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_FiveAndFiveTests.cpp
INCLUDEPATH += "../FiveAndFive"
SOURCES += ../FiveAndFive/FiveAndFive.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
