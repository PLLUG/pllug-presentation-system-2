import QtQuick 2.0
import QtQuick.Layouts 1.0

Item {
    id: mainWindow
    SideBar{
        id: sideBar
        height: parent.height
        width: 250
        Component.onCompleted: {
            toolBar.sideBarButtonClicked.connect(sideBar.open)
            sideBar.currentSlideChanged.connect(sideBar.close)
        }
    }

    ToolBar{
        id: toolBar
    }

    SlideView {
        id: slideView
        anchors {
            topMargin: toolBar.height
            fill: parent
        }

        PageIndicator{
            id: pageIndicator
            anchors{
                bottom: parent.bottom
                horizontalCenter: parent.horizontalCenter
            }

            Component.onCompleted: {
                sideBar.currentSlideChanged.connect(pageIndicator.updateSlideIndexText)
            }
        }
    }
}
