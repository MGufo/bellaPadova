Repository containing the didactic project of the "Object-Oriented Programming" course A.A. 2019/20. 

# BellaPadova

The project in question provides an application to computerize an ecological takeaway pizzeria oriented towards local products, implementing an efficient management of inventory, menus and orders.
The application was designed using the MVC (Model-View-Controller) architectural design pattern in order to separate the business logic from the view, which was implemented using the Qt framework.
In addition to the application, the didactic project involved the implementation of a container of polymorphic objects, which was implemented as a double-linked list template, with relative bidirectional iterators, methods of insertion, removal, search, counting and comparison operators.

# Compiling instructions

1. open a terminal in the project folder
2. `qmake bellaPadova.pro`
3. `make`
4. `./bellaPadova`

# Development environment

- OS: Microsoft Windows 10 Pro N 64bit
- Compiler: MinGW 5.3.0 32bit
- Qt version: 5.9.5
- IDE: Visual Studio Code / QtCreator
