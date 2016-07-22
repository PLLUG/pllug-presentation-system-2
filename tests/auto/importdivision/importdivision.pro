#-------------------------------------------------
#
# Project created by QtCreator 2016-07-21T16:46:07
#
#-------------------------------------------------

QT       += xml testlib

QT       -= gui

TARGET = tst_importdivisiontest

include(../includes/default.pri)
include(../../../pllug-presentation-system/presentation-data/presentation-data.pri)

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_importdivisiontest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
