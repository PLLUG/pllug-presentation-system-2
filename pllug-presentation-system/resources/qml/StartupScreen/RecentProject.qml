import QtQuick 2.6
import QtQuick.Controls 2.0


Flickable {
    id: flickable
    contentHeight: gridRectangle.height

    Rectangle {
        id: gridRectangle
        width: flickable.width
        height: flickable.height * 1.25
        anchors.bottomMargin: 40

        GridView {
            id: recentModelGridView
            anchors.fill: parent;
            anchors.leftMargin: 10
            anchors.rightMargin: 5
            cellWidth: 220
            cellHeight: 220
            model: recentModel

            delegate: RecentDelegateModel {
                width: GridView.view.cellWidth
                height: GridView.view.cellHeight
            }
        }
    }

    ScrollBar.vertical: ScrollBar { }

}
