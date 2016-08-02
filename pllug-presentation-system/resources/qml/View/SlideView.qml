import QtQuick 2.0
import QtQuick.Layouts 1.1

ColumnLayout {
    width: parent.width
    Repeater {
        model: slideModel
        delegate: Text{
            width: parent.width
            wrapMode: Text.WordWrap
            text: Html
        }
    }
}
