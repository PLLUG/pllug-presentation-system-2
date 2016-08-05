import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: elements
    width: window.width;
    height: window.height

    FocusScope {
        id: mainView
        width: parent.width; height: parent.height


        GridMenu {
            id: gridMenu
            anchors.fill: parent
            width: parent.width;
            height:parent.height
        }
    }
}
