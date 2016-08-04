import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import com.cutehacks.fontawesome 1.0

ToolBar {

    RowLayout {
        anchors.fill: parent

        ToolButton {
            id: optionsMenuToolButton
            anchors.left: parent.left
            anchors.margins: 10


            FAText{
                font.pixelSize: 20
                text: icons.ellipsis_v
                anchors.centerIn: parent
            }
        }

        ToolButton {
            id: sideBarToolButton
            anchors.left: optionsMenuToolButton.right
            anchors.margins: 10


            FAText{
                font.pixelSize: 20
                text: icons.bars
                anchors.centerIn: parent
            }
        }
    }
}

