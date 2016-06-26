# Coding Standard QML

###1. QML document structure

#####Rule 1.1. Basic document and elements structure should be order like this:
* Id
* New property declarations
* New signal declarations
* Java Script functions
* Element's property initialization
* Children elements
* States
* Transitions
* Connections
* Others

#####Rule 1.2. All above-mentioned groups should be separate with empty line

``` js
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

###2. Groped properties
##### Rule 2.1. Use group notation for group properties instead of dot notation.

``` js
//Bad example
Rectangle {
  anchor.top: parent.top
  anchor.topMargin: 42
  anchor.left: parent.left
}

Text {
  text: "Some Text"  
  font.pointSize: 18
  font.bold: true
}

//Good example
Rectangle {
  anchor {
    top: parent.top
    topMargin: 42
    left: parent.left
  }
}

Text {
  text: "Some Text"  
  font{
    pointSize: 18
    bold: true
  }
}
```
###3. Code Formatting
####3.1 Naming convention
#####Rule 3.1.1. Use camel case style for properties, java script functions, java script variables, signals, ids names.
####3.2 Brackets style
#####Rule 3.2.1 Open bracket should be in the same line as condition
``` js
//Bad example
  if (isTrue) 
  {
    //Do thomething
  }
  else
  {
    //Do thomething else
  }
  
  function myFunction (parameter) 
  {
    //Important calculation
  }
  
//Good example
  if (isTrue) {
    //Do thomething
  } else {
    //Do thomething else
  }
  
  function myFunction (parameter) {
    //Important calculation
  }
```
####3.3 Whitespaces