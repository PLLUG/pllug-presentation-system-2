import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import com.cutehacks.fontawesome 1.0
import QtGraphicalEffects 1.0


ToolBar {

    RowLayout {
        id: rowLayout
        anchors.fill: parent

        MyGlow {
            id: optionsMenuToolButton
            toolButtonIcon: icons.ellipsis_v
            anchors.left: parent.left
            toolTipText: "Options"

        }
        MyGlow {
            id: sideBarToolButton
            toolButtonIcon: icons.bars
            toolTipText: "Switch to preview"
            anchors {
                left: optionsMenuToolButton.right
                leftMargin: 30     
            }
            MyGlow {
                id: importButton
                toolButtonIcon: icons.arrow_circle_right
                toolTipText: "Import presentation"
                anchors {
                    left: sideBarToolButton.right
                    leftMargin: 40
                }
            }
            MyGlow {
                id: quitButton
                toolButtonIcon: icons.times
                toolTipText: "Quit"
                anchors {
                    left: importButton.right
                    leftMargin: 40
                }
            }

        }

    }
}

