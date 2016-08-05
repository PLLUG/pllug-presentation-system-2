import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import "./TestScreen"
import "./qml files"

ApplicationWindow {
    id: window
    width: 700
    height: 480
    visible: true
    title: "PLLUG Presentation System 2.0"

    StartupScreen {}

    header: MainToolbar { }
}
