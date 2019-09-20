import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

import "./View"
import "./StartupScreen"

ApplicationWindow {
    id: window
    width: 800
    height: 600
    visible: true
    title: qsTr("PLLUG Presentation System 2.0")

    MainWindow {
        id: mainWindow
        anchors.fill: parent
        visible: false
    }

    RecentProject {
        id: gridMenu
        anchors.fill: parent
    }

    header: MainToolbar {
        onSelectedFile: {
            gridMenu.visible = false
            mainWindow.visible = true
        }
    }
}
