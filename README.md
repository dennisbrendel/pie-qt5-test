# pie-qt5-test
Simple test for qt5 style connect()s with the Intel Compiler

We have discovered that Qt5 connect()s did not work when using the Intel Compiler. This is a linker problem which can be solved by building a position independent executable:
https://codereview.qt-project.org/c/qt/qtbase/+/183490
