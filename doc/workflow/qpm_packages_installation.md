To work with PPS 2.0 you need to install Font Awesome web fonts package manager, so:
-  download [qpm package manager](https://www.qpm.io/). 
-  put qpm.exe in PPS project folder.
-  use `qpm install com.cutehacks.fontawesome` in command line.
-  `include($$PWD/vendor/vendor.pri)` in pllug-presentation-system.pro file.
-  add in main.cpp file:       
      ```
      QQmlApplicationEngine engine;
      engine.addImportPath(QStringLiteral("qrc:/"));
      engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
      ```