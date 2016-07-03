#-------------------------------------------------
#
# Project created by QtCreator 2016-07-03T19:01:14
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_slidetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include(../includes/default.pri)
include(../../../pllug-presentation-system/presentation-data/presentation-data.pri)

SOURCES += tst_slidetest.cpp
