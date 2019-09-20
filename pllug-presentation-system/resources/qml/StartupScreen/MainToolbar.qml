import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import com.cutehacks.fontawesome 1.0
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.0


ToolBar {
    id: toolBar

    signal selectedFile

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
                onClicked: {
                    fileDialog.open()
                    console.log("Clicked")
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

    FileDialog {
        id: fileDialog

        title: "Please choose a file"
        folder: shortcuts.desktop
        nameFilters: [ "Markdown files (*.md)", "All files (*)" ]

        Component.onCompleted: {
            accepted.connect(toolBar.selectedFile)
        }

        onAccepted: {
            presentationController.importPresentation(fileDialog.fileUrl)
        }
        onRejected: {
            console.log("Canceled")
        }

    }
}

