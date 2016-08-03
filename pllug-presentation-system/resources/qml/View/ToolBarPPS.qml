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
            anchors{
                left: parent.left
                margins: 10
            }
            iconSource: "qrc:/ToolBarIcons/menu.png"
        }
        ToolButton {
            id: sidebarButton
            width: 50
            height: 20
            anchors{
                left: menuButton.right
                margins: 10
            }
            iconSource: "qrc:/ToolBarIcons/sidebar.png"
            onClicked: {
                sideBarButtonClicked()
            }
        }
    }
}
