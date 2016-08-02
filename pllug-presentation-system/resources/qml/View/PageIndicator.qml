import QtQuick 2.0
import QtQuick.Controls 1.4

Row{
    id: pageIndicator

    QtObject {
        id: internal
        property int buttonWidth: 50
        property int buttonHeight: 20
    }

    function updateSlideIndexText() {
        slideIndexText.text = slideModel.slideNumber() + 1 + " of " + slideModel.slideCount()
    }

    Button{
        id: startButton
        width: internal.buttonWidth
        height: internal.buttonHeight
        text: "<<"
        iconName : "startButton.png"

        onClicked: {
            slideModel.firstSlide()
            updateSlideIndexText()
        }
    }
    Button{
        id: previousSlideButton
        width: internal.buttonWidth
        height: internal.buttonHeight
        text: "<"
        iconName : "previousSlideButton.png"

        onClicked: {
            slideModel.previousSlide()
            updateSlideIndexText()
        }

    }
    Rectangle{
        id: slideIndexLabel
        width: internal.buttonWidth
        height: internal.buttonHeight
        Text{
            id: slideIndexText
            anchors.centerIn: parent
            text: slideModel.slideNumber() + 1 + " of " + slideModel.slideCount()
        }



    }
    Button{
        id: nextSlideButton
        width: internal.buttonWidth
        height: internal.buttonHeight
        text: ">"
        iconName : "nextSlideButton.png"

        onClicked: {
            slideModel.nextSlide()
            updateSlideIndexText()
        }
    }
    Button{
        id: endButton
        width: internal.buttonWidth
        height: internal.buttonHeight
        text: ">>"
        iconName : "endButton.png"

        onClicked: {
            slideModel.lastSlide()
            updateSlideIndexText()
        }
    }
}
