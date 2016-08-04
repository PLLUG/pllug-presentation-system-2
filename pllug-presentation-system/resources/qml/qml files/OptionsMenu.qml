import QtQuick 2.6
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4

Menu {
    Menu{
        title: "File"
        MenuItem{
            text: "Import..."
            shortcut: "CTRL+l"
        }
    }
    MenuSeparator { }
    MenuItem {
        text: "Quit"
        shortcut: "CTRL+Q"
        onTriggered: Qt.quit()
    }
}
