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
##### Rule 1.3 Grouped logically related properties.
##### Rule 1.4 Put internal object properties and functions into QtObject object to avoid changing outside
``` js
Rectangle {
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
#####Rule 3.1.2. All names should start with lower case letter.
#####Rule 3.1.3. All names should have logical meaning. Avoid abbreviation and single letter names.
####3.2 Brackets style
#####Rule 3.2.1 Open bracket should be in the same line as expression or object name
``` js
//Bad example
  Rectangle
  {
  }
  
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
  Rectangle {
  }
  
  if (isTrue) {
    //Do thomething
  } else {
    //Do thomething else
  }
  
  function myFunction (parameter) {
    //Important calculation
  }
```
#####Rule 3.2.2 Do not use semicolon if there is single or simple expression
``` js
function printText() {
  console.log("Hello")
}
//Bad example
MouseArea {
  onClicked : {
    printText()
  }
}

//Good example
MouseArea {
  onClicked : printText()
}
```
#### 3.3 Semicolons
#####Rule 3.3.1 Avoid to use semicolons in QML code where it is possible.
```js
function myFunction() {
  var firstVar = 1
  var secondVar = 2
  return firstVar + secondVar
}
```
###4. QML Files naming
##### Rule 4.1. All QML files shoul be name in camel case style and name shoul begin with capital leter.