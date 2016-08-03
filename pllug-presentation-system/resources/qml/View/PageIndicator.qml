import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import com.cutehacks.fontawesome 1.0

RowLayout{
    id: pageIndicator

    QtObject {
        id: internal
        property int buttonWidth: 50
        property int buttonHeight: 20
        property int buttonRadius: 7
        property int fontPixelSize: 15
        property color buttonColor: "grey"
        property color buttonPressedColor: "black"
        property color buttonTextColor: "white"
    }

    function updateSlideIndexText() {
        slideIndexText.text = slideModel.slideNumber() + 1 + " of " + slideModel.slideCount()
    }

    Button{
        id: startButton

        onClicked: {
            slideModel.firstSlide()
            updateSlideIndexText()
        }

        width: internal.buttonWidth
        height: internal.buttonHeight
        style: ButtonStyle{
            background: Rectangle{
                radius: internal.buttonRadius
                anchors.margins: 5
                color: control.pressed ? internal.buttonPressedColor : internal.buttonColor
            }

            label: FAText{
                text: icons.angle_double_left
                font.pixelSize: internal.fontPixelSize
                anchors.centerIn: parent
                color: internal.buttonTextColor
            }
        }

    }

    Button{
        id: previousSlideButton

        onClicked: {
            slideModel.previousSlide()
            updateSlideIndexText()
        }

        width: internal.buttonWidth
        height: internal.buttonHeight
        style: ButtonStyle{
            background: Rectangle{
                id: previousSlideRect

                radius: internal.buttonRadius
                color: control.pressed ? internal.buttonPressedColor : internal.buttonColor
            }

            label: FAText{
                text: icons.angle_left
                font.pixelSize: internal.fontPixelSize
                anchors.centerIn: parent
                color: internal.buttonTextColor
            }
        }
    }

    Rectangle{
        id: slideIndexLabel

        width: 80
        height: 30
        color: "lightgrey"
        radius: internal.buttonRadius

        Text{
            id: slideIndexText

            text: slideModel.slideNumber() + 1 + " of " + slideModel.slideCount()
            font.pixelSize: internal.fontPixelSize + 8
            anchors.centerIn: parent
            color: "grey"
        }
    }

    Button{
        id: nextSlideButton

        onClicked: {
            slideModel.nextSlide()
            updateSlideIndexText()
        }

        width: internal.buttonWidth
        height: internal.buttonHeight
        style: ButtonStyle{
            background: Rectangle{
                id:  nextSlideRect

                radius: internal.buttonRadius
                color: control.pressed ? internal.buttonPressedColor : internal.buttonColor
            }

            label: FAText{
                text: icons.angle_right
                font.pixelSize: internal.fontPixelSize
                anchors.centerIn: parent
                color: internal.buttonTextColor
            }
        }


    }

    Button{
        id: endButton

        onClicked: {
            slideModel.lastSlide()
            updateSlideIndexText()
        }

        width: internal.buttonWidth
        height: internal.buttonHeight
        style: ButtonStyle{
            background: Rectangle{
                id:  endRect

                radius: internal.buttonRadius
                color: control.pressed ? internal.buttonPressedColor : internal.buttonColor
            }

            label: FAText{
                text: icons.angle_double_right
                font.pixelSize: internal.fontPixelSize
                anchors.centerIn: parent
                color: internal.buttonTextColor
            }
        }       
    }
}
