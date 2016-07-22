#-------------------------------------------------
#
# Project created by QtCreator 2016-07-21T12:15:24
#
#-------------------------------------------------

QT       += xml testlib

QT       -= gui

TARGET = tst_htmlimporttest

include(../includes/default.pri)
include(../../../pllug-presentation-system/presentation-data/presentation-data.pri)

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_htmlimporttest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

DISTFILES += \
    test-data/single_paragraph.html \
    test-data/two_paragraphs.html \
    test-data/separated_paragraphs.html
