# Coding Standard QML

## 1. QML document structure

**Structure 1.1.** Basic document and elements structure should be ordered like this:

* Id
* New property declarations
* New signal declarations
* Element's property initialization
* States
* Transitions
* Java Script functions
* Children elements
* Connections
* Others

``` js
Rectangle {
    id: myButton

    //New property declarations
    property alias text: buttonText.text

    //New signal declarations
    signal clicked

    //Element's property initialization
    color: "red"
    height: 100
    width: 250

    //States
    states: [
        State {
          name: "default"
        },
        State {
          name: "hovered"
        }
    ]

    //Transition
    transitions: [
        Transition {
            from: "default"
            to: "hovered"
        }
    ]

    //Java Script functions
    function printHello() {
        console.log("Hello, from myButton!")
    }

    //Child element 1
    Text {
      id: buttonText

      anchors.centerIn: parent
    }

    //Child element 2
    MouseArea {
        id: mouseArea

        anchor.fill: parent

        onClicked: clicked()
    }

    //Connections
    Connections {
        target: someObject
        onSomeObjectAction: console.log("Hello, someObject!")
    }
}
```

**Structure 1.2.** All above-mentioned groups should be separated with empty line.

**Structure 1.3.** Put properties and functions for internal usage into QtObject to avoid changing outside.

``` js
Rectangle {
  id: myRect

  //Visible only inside "myRect"
  QtObject {
    id: internal
    property string someInternalText: "Hello"
  }
}
```

**Structure 1.4.** All "magic" numbers and text names should be moved to "readonly" properties

```js
Rectangle {
   readonly property int meaningOfLife: 42
   readonly property string stateName: "stateName"
}
```

## 2. Groped properties

**Groped 2.1.** Use group notation for group properties instead of dot notation.

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
  font {
    pointSize: 18
    bold: true
  }
}
```

## 3. Code Formatting

### 3.1 Naming convention

**Naming 3.1.1.** Use camel case style for properties, java script functions, java script variables, signals, ids.

**Naming 3.1.2.** All names should start with lower case letter.**

**Naming 3.1.3.** All names should have logical meaning. Avoid abbreviation and single letter names.

### 3.2 Brackets style

**Brackets 3.2.1** Open bracket should be in the same line as expression or object name

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

  function myFunction(parameter) {
    //Important calculation
  }
```

**Brackets 3.2.2** Do not use curly braces, if there is single or simple expression

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
  onClicked: printText()
}
```

### 3.3 Semicolons

**Semicolons 3.3.1** Avoid to use semicolons in QML code where it is possible.

```js
function myFunction() {
  var firstVar = 1
  var secondVar = 2
  return firstVar + secondVar
}
```

## 4. QML Files naming

**Files 4.1.** All QML files should be name in camel case style and name should begin with capital letter.

## 5.Best Practices and Advice

**Advice 5.1.** Try to avoid heavy calculation and data manipulation in QML/Java Script code. Use QML for UI purpose. For heavy operation use C++.