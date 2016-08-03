import QtQuick 2.0
import QtQuick.Layouts 1.1

ColumnLayout {
    width: parent.width
    height: parent.height
    Repeater {
        model: slideModel
        width: parent.width
        height: parent.height
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
            width: parent.width
            wrapMode: Text.WordWrap
            text: Html
            font.pixelSize: 25
}
        }
    }
    Layout.fillHeight: false
}
