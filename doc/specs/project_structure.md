# Project Structure

## Folder Structure

* **root**
  * **3rdparty**
    * (3rdparty Sources)
  * (C++ Sourses)
  * **resourses**
    * **qml**
      * (*.qrc files)
      * (QML Sourses)
      * **components**
        * (QML components used in all project)
      * (TestScreen Folder)
        * (TestScreen QML and QML UI files)
    * **images**
      * (Images used in PPS2 UI)
    * **fonts**
      * (Fonts used in PPS2 UI)
     
## General Considerations
* It is highly recommended to group QML files related to certain screen/component together by making a separate folder for it.
* Resources in Qt Resource File should be grouped in appropriate way by prefixes.
* All resources should have alias in Qt Resource File.
* Name of Qt Resource File should be the same as folder that have content related to this file.
