# Coding Standard QML

## 1. QML document structure

#####Rule 1.1. Basic document and elements structure should be order like this:
* Id
* New property declarations
* New signal declarations
* Java Script functions
* Element's property initialization
* Children elements
* States
* Transitions

#####Rule 1.2. All above-mentioned groups should be separate with empty line

``` qml
Rectangle {
    id: myButton                                               
    
    property alias text: buttonText.text

    signal clicked

    color: "red"
    height: 100
    width: 250

    Text {                                             
        id: buttonText
        
        anchors.centerIn: parent
    }
    
    MouseArea {
        id: mouseArea
        
        anchor.fill: parent
        
        onClicked: {
            clicked()
        }
    }
}
```
