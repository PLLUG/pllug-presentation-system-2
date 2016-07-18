import QtQuick 2.6
import QtQuick.Dialogs 1.2

Rectangle {
    property string error_title: "Error"
    property string message: "Error"

    MessageDialog {
        id: messageDialog
        title: error_title
        text: message
        icon: StandardIcon.Critical
        onAccepted: console.log("You press OK in MessageError")
        Component.onCompleted: visible = true
    }
}
