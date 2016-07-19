import QtQuick 2.6
import QtQuick.Layouts 1.0
import Qt.labs.controls 1.0

import "./TestScreen"
import "./FontAwesome"


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    FontAwesome{
        id: awesome
        resource: "qrc:/FontAwesome/font/fontawesome-webfont.ttf"
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        Page {
            Label {
                //Font Awesome usage

                text: awesome.icons.fa_ambulance  //icon set up
                font.pointSize: 20                //icon size
                anchors.centerIn: parent
                //text: qsTr("Second page")

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
