import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

Drawer {
    id: drawer

    signal currentSlideChanged

    contentItem: ListView {
            spacing: 20
        model: presentationModel
        width: 250
        delegate: Rectangle{
            id: slide
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            border.color: "black"
            width: parent.width
            height: 110
            radius: 5
            Text{
                width: parent.width
                wrapMode: Text.WordWrap
                text: Html
            }
            Rectangle{
                id: slideNumber
                width: 20
                height: 20
                color: "grey"
                radius: 5
                anchors.right: parent.right
                opacity: 0.5
                Text{
                    text: (index + 1)
                    font.bold: true
                    color: "black"
                    font.pixelSize: 15
                    font.family: "Lucida Sans Unicode"
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
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true
    }
}

