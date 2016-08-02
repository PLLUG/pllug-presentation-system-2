import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

ToolBar {
    signal sideBarButtonClicked
    RowLayout {
        anchors.fill: parent
        ToolButton {
            id: menuButton
            width: 50
            height: 20
            Text {
                text: "menu"
                anchors.left: parent.left
            }
        }
        ToolButton {
            id: sidebarButton
            width: 50
            height: 20
            Text {
                text: "sidebar"
                anchors.left: menuButton.right
            }
            onClicked: {
                sideBarButtonClicked()
            }
        }
    }
}
