import QtQuick 2.0

Item {
    id: container
    property alias modelNameText: presentationNameText.text
    property alias modelPathSource: presentationImage.source

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
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
    }
}
