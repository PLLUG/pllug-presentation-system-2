import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

Drawer {
    id: drawer

    signal currentSlideChanged

    contentItem: ListView {
        model: presentationModel

        delegate: Rectangle{
            border.color: "black"
            width: 250
            height: 110
            Text{
                width: parent.width
                wrapMode: Text.WordWrap
                text: Html
            }
            Rectangle{
                width: 25
                height: 25
                color: "#ffffff"
                border.color: "black"

                Text{
                    text: (index + 1)
                    font.bold: true
                    color: "red"
                    font.pixelSize: 20
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

