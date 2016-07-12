QT += testlib
QT -= gui

include(../includes/default.pri)
include(../../../pllug-presentation-system/presentation-data/presentation-data.pri)

CONFIG += qt console warn_on depend_includepath testcase c++14
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += tst_presentation.cpp
