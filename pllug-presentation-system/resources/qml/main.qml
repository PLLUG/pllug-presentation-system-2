import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick 2.7

import "./TestScreen"
import "./View"


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
//            Rectangle{
//                width: parent.width
//                height: parent.height
//                color: "green"
//                ShaderEffectSource{
//                    id:effect

//                    width: parent.width
//                    height: parent.height
//                    sourceItem:  mainWindow
//                }
//            }
        }

        Page {
            MainWindow{
                id: mainWindow

                width: parent.width
                height: parent.height
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
