QT += xml qml quick

CONFIG += c++14

CONFIG += silent


include(presentation-data/presentation-data.pri)

SOURCES += main.cpp

RESOURCES += \
    resources/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
include($$PWD/vendor/vendor.pri)

# Pandoc-slave
include($$PWD/../pandoc-slave/pandoc-slave/pandoc-slave/pandoc-slave.pri)
