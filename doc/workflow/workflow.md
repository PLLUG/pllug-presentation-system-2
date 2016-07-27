# Workflow
  To start working with project, please read carefully following rules.
  1.  PPS 2.0 is Qt application. You will need to install [Qt Framework (Open Source)](https://www.qt.io/download-open-source/) to work with source code. Note, that Qt version must be 5.6.1 or higher.
  2.  To work with PPS 2.0 you need to:
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
  3.  To start working on issue and apply your changes to project after, please read ["Git Best Practices -> 2. Developer Workflow"](https://alexchmykhalo.gitbooks.io/pllug-presentation-system-2-documents-and-specifi/content/doc/workflow/git_best_practices.html).
  4.  You should use our ["Coding Standard"](https://alexchmykhalo.gitbooks.io/pllug-presentation-system-2-documents-and-specifi/content/doc/workflow/coding_standard.html) and ["Coding Standard QML"](https://alexchmykhalo.gitbooks.io/pllug-presentation-system-2-documents-and-specifi/content/doc/workflow/coding_standard_qml.html), when working with project, to keep order, same style and readability of source code. If something do not mentioned in our rules, always follow ["C++ Core Guidelines"](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
  5.  If you have some feature or improvement ideas or found a bug, please create appropriate issue on ["Overvio board"](https://overv.io/PLLUG/pllug-presentation-system-2/board/). Put this issue to "Backlog".
  6.  If you need help, advice, or have comments about project you may write to our [Gitter chat](https://gitter.im/PLLUG/pllug-presentation-system-2?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge).
    
  ***  
    

  

