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
            id: gridView
            anchors.fill: parent;
            anchors.leftMargin: 10
            anchors.rightMargin: 5
            cellWidth: 220
            cellHeight: 220
            model: recentPresentationsModel

            delegate: RecentDelegateModel {
                width: GridView.view.cellWidth
                height: GridView.view.cellHeight
            }
        }
    }

    ScrollBar.vertical: ScrollBar { }

    // You should remove this ListModel when our model will be available
    ListModel {
        id: recentPresentationsModel

        ListElement {
            presentationName: "Presentation name1"
            imageSrc: ""
        }
        ListElement {
            presentationName: "Presentation name1"
            imageSrc: ""
        }
        ListElement {
            presentationName: "Presentation name1"
            imageSrc: ""
        }
        ListElement {
            presentationName: "Presentation name1"
            imageSrc: ""
        }
        ListElement {
            presentationName: "Presentation name1"
            imageSrc: ""
        }
        ListElement {
            presentationName: "Presentation name1"
            imageSrc: ""
        }
        ListElement {
            presentationName: "Presentation name1"
            imageSrc: ""
        }
    }
}
