import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Row{
    id: pageIndicator

    QtObject {
        id: internal
        property int buttonWidth: 50
        property int buttonHeight: 20
        property color buttonColor: "grey"
        property color buttonPressedColor: "black"
        property color buttonTextColor: "white"
    }

    function updateSlideIndexText() {
        slideIndexText.text = slideModel.slideNumber() + 1 + " of " + slideModel.slideCount()
    }

    Button{
        id: startButton
        width: internal.buttonWidth
        height: internal.buttonHeight
        style: ButtonStyle{
            background: Rectangle{
                radius: 10
                color: control.pressed ? internal.buttonPressedColor : internal.buttonColor
                anchors.margins: 5
            }
            label: Text{
                text: "<<"
                color: internal.buttonTextColor
            }
        }
        onClicked: {
            slideModel.firstSlide()
            updateSlideIndexText()
        }
    }
    Button{
        id: previousSlideButton
        width: internal.buttonWidth
        height: internal.buttonHeight
        style: ButtonStyle{
            background: Rectangle{
                id: previousSlideRect
                radius: 10
                color: control.pressed ? internal.buttonPressedColor : internal.buttonColor
            }
            label: Text{
                text: "<"
                color: internal.buttonTextColor
            }
        }

        onClicked: {
            slideModel.previousSlide()
            updateSlideIndexText()
        }

    }
    Rectangle{
        id: slideIndexLabel
        width: internal.buttonWidth
        height: internal.buttonHeight
        color: "lightgrey"
        radius: 10
        Text{
            id: slideIndexText
            anchors.centerIn: parent
            color: "grey"
            font.bold: true
            text: slideModel.slideNumber() + 1 + " of " + slideModel.slideCount()
        }

    }
    Button{
        id: nextSlideButton
        width: internal.buttonWidth
        height: internal.buttonHeight
        style: ButtonStyle{
            background: Rectangle{
                id:  nextSlideRect
                radius: 10
                color: control.pressed ? internal.buttonPressedColor : internal.buttonColor
            }
            label: Text{
                text: ">"
                color: internal.buttonTextColor
            }
        }

        onClicked: {
            slideModel.nextSlide()
            updateSlideIndexText()
        }
    }
    Button{
        id: endButton
        width: internal.buttonWidth
        height: internal.buttonHeight
        style: ButtonStyle{
            background: Rectangle{
                id:  endRect
                radius: 10
                color: control.pressed ? internal.buttonPressedColor : internal.buttonColor
            }
            label: Text{
                text: ">>"
                color: internal.buttonTextColor
            }
        }


        onClicked: {
            slideModel.lastSlide()
            updateSlideIndexText()
        }
    }
}
