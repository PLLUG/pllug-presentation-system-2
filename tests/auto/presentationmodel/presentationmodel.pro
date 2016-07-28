#-------------------------------------------------
#
# Project created by QtCreator 2016-07-26T14:17:09
#
#-------------------------------------------------

QT       += xml testlib

QT       -= gui

TARGET = tst_presentationmodeltest

include(../includes/default.pri)
include(../../../pllug-presentation-system/presentation-data/presentation-data.pri)

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_presentationmodeltest.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

include(./modeltest.pri)