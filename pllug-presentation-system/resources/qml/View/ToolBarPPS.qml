import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import com.cutehacks.fontawesome 1.0

ToolBar {
    signal sideBarButtonClicked

    RowLayout {
        anchors.fill: parent

        ToolButton {
            id: menuButton

            anchors{
                left: parent.left
                margins: 10
            }

            FAText{
                font.pixelSize: 20
                text: icons.ellipsis_v
                anchors.centerIn: parent
            }
        }

        ToolButton {
            id: sidebarButton

            onClicked: {
                sideBarButtonClicked()
            }

            anchors{
                left: menuButton.right
                margins: 10
            }

            FAText{
                font.pixelSize: 20
                text: icons.bars
                anchors.centerIn: parent
            }
        }
    }
}
