import QtQuick 2.6
import QtQuick.Layouts 1.0
import Qt.labs.controls 1.0
import com.cutehacks.fontawesome 1.0

import "./TestScreen"


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        Page {
            FAText {
                    text: icons.ambulance
                    anchors.centerIn: parent
                    font.pixelSize: 72
                    color: "steelblue"
                }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }
}
