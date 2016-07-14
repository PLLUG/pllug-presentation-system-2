#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T17:38:10
#
#-------------------------------------------------

QT       += xml testlib

QT       -= gui

TARGET = tst_domdocumentdividertest

include(../includes/default.pri)
include(../../../pllug-presentation-system/presentation-data/presentation-data.pri)

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_domdocumentdividertest.cpp

DISTFILES += \
    test-data/single_paragraph.html
