import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0
import com.cutehacks.fontawesome 1.0

Item {
    id: rootItem
    property alias toolButtonIcon: faText.text
    readonly property alias icons: faText.icons
    property alias toolTipText: toolTip.text

    signal clicked

    ToolButton {
        id: toolButton

        FAText{
            id: faText
            font.pixelSize: 30
            anchors.centerIn: parent

        }

        ToolTip {
            id: toolTip
            delay: 1000
            timeout: 3000
            visible: false
        }

        MouseArea {
            id: mouseArea

            anchors.fill: parent
            hoverEnabled: true

            Component.onCompleted: {
                clicked.connect(rootItem.clicked)
            }
            onEntered: {
                glow.visible = true
                toolTip.open()
            }
            onExited: {
                glow.visible = false
                toolTip.close()
            }
        }

    }

    Glow {
        id: glow
        anchors.fill: toolButton
        radius: 10
        samples: 17
        spread: 0.5
        color: "black"
        source: toolButton
        visible: false
        opacity: 0.5
    }
}
