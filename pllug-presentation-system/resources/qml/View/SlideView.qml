import QtQuick 2.0
import QtQuick.Layouts 1.1

ColumnLayout {
    anchors.fill: parent
    Layout.fillHeight: false

    ListView {
        anchors.fill: parent

        model: slideModel

        delegate: Rectangle{
            anchors{
                top: parent.top
                topMargin: 15
                left: parent.left
                leftMargin: 15
                right: parent.right
                rightMargin: 15
            }
            width: parent.width

            Text{
                text: Html
                font.pixelSize: 25
                width: parent.width
                wrapMode: Text.WordWrap
            }
        }
    }
}
