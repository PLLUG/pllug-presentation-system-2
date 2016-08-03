import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

Drawer {
    id: drawer

    signal currentSlideChanged

    contentItem: ListView {
        id: listView

        spacing: 25
        width: 250

        model: presentationModel

        delegate: Rectangle{
            id: slide
            anchors{
                left: parent.left
                right: parent.right
                leftMargin: 20
                rightMargin: 20
            }
            width: parent.width
            height: text.height + 8
            radius: 5

            border.color: area.pressed ? "white" : "black"
            color: area.pressed ? "blue" : "white"

            Text{
                id: text
                width: parent.width
                wrapMode: Text.WordWrap
                anchors{
                    left: parent.left
                    leftMargin: 5
                    right: parent.right
                    rightMargin: 5
                    top: parent.top
                    topMargin: 5
                    bottom: parent.bottom
                    bottomMargin: 5
                }
                text: Html
                color: area.pressed ? "white" : "black"
            }
            Rectangle{
                id: slideNumber
                width: 20
                height: 20
                color: area.pressed ? "white" : "grey"
                radius: 5
                opacity: 0.5
                anchors{
                    rightMargin: 3
                    right: parent.right
                    top: parent.top
                    topMargin: 3
                }
                Text{
                    text: (index + 1)
                    color: area.pressed ? "white" : "black"
                    font{
                        bold: true
                        pixelSize: 15
                        family: "Lucida Sans Unicode"
                    }
                    anchors.centerIn: parent
                }
            }
            MouseArea{
                id: area
                anchors.fill: parent

                onClicked: {
                    slideModel.setSlideNumber(index)
                    drawer.currentSlideChanged()

                }
            }
        }
        ScrollIndicator.vertical: ScrollIndicator { }

    }
}

