import QtQuick.Controls 1.4
import QtQuick.Controls 2.0

import "./View"
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.4

import "./StartupScreen"

ApplicationWindow {
    id: window
    width: 700
    height: 480
    title: qsTr("PLLUG-Presentation-System-2.0")

    visible: true

    MainWindow{
        id: mainWindow
        anchors.fill: parent
        visible: false
    }

    RecentProject {
        id:gridMenu
        anchors.fill: parent
    }

    header: MainToolbar {
        onSelectedFile: {
            gridMenu.visible = false
            mainWindow.visible = true
    } }
}
