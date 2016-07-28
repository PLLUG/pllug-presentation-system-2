import QtQuick 2.0

Column {
    Repeater {
        model: slideModel
        delegate: Text{
            width: parent.width
            wrapMode: Text.WordWrap
            text: Html
        }
    }
}
