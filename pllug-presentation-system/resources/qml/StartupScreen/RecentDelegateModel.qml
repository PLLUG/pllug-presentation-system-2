import QtQuick 2.0
import QtQuick.Controls 2.0


Item {
    id: container

    Rectangle {
        id: recentDelegeteRectangle
        anchors.fill: parent
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        border.width: 2
        border.color: "black"
        color: "white"

        Rectangle
        {
            anchors.fill:parent
            anchors.topMargin: 140
            border.color: "black";
            border.width: 2
            Text {
                id: presentationNameText
                anchors.fill:parent
                anchors.topMargin: 10
                anchors.bottomMargin: 10

                text: presentationName
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

        }
        Rectangle {
            anchors.fill:parent
            anchors.leftMargin: 2
            anchors.rightMargin: 2
            anchors.topMargin: 2
            anchors.bottomMargin: 40

            Image {
                id: presentationImage
                anchors.fill: parent
                source: imageSrc
            }
        }

        Rectangle{
            id: darkRectangle
            anchors.fill: parent
            border.width: 2
            border.color: "black"
            color: "black"
            opacity: 0.5
            visible: false

        }

        RecentDelegateContextMenu{ id: contextMenu}


        MouseArea {
            id: mouseArea
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                darkRectangle.visible = true;
            }
            onExited: {
                darkRectangle.visible = false;
            }
            onClicked: {
                if(mouse.button === Qt.LeftButton)
                {

                }
                else if(mouse.button === Qt.RightButton)
                {
                    contextMenu.x = mouseX
                    contextMenu.y = mouseY
                    contextMenu.open()
                }
            }

        }

    }






}
