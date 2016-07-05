import QtQuick 2.6
import QtQuick.Layouts 1.0
import Qt.labs.controls 1.0
import QtQuick.Controls 1.4

import "./TestScreen"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar : MenuBar{
        Menu{
            title: "File"
            MenuItem{
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    TabBar {
        id: tabBar
        anchors.bottom:   parent.bottom
        anchors.bottomMargin:20
        anchors.horizontalCenter: parent.horizontalCenter
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
//            anchors.top: parent.top
        }
        TabButton {
            text: qsTr("Second")
        }
    }
}
