## Test Qt 5.6 project
This project illustrates an odd behavior when compiling a project in Qt 5.6. The QListView along the left side of the form ("listViewWest") is styled using CSS in the mainwindow.ui stylesheet. The CSS sets the color of the unselected items, the hovered item, and the selected item. 

But when an item is selected, both it and the subsequent item are highlighted. 

Issue first appeared after upgrading from Qt 5.4 to 5.6. Using Qt Creator 3.6.1 and MinGW 4.9.2 to compile. Operating system is  Windows 7 Professional 64-bit.

View the Qt bug report here: [QTBUG-53186](https://bugreports.qt.io/browse/QTBUG-53186)
