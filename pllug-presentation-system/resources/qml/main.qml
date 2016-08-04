import QtQuick.Controls 1.4
import QtQuick.Controls 2.0

import "./View"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("PLLUG-Presentation-System-2.0")

    MainWindow{
        id: mainWindow

        width: parent.width
        height: parent.height
    }
}
