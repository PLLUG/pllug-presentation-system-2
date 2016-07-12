#-------------------------------------------------
#
# Project created by QtCreator 2016-07-12T09:32:22
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_pandoctest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

include(../includes/default.pri)
include(../../../pllug-presentation-system/pandoc-workflow/pandoc-workflow.pri)

SOURCES += tst_pandoctest.cpp
