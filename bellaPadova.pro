INCLUDEPATH += C:\Qt\Qt5.9.5\5.9.5\mingw53_32\include\
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core gui widgets

SOURCES += \
    core/articolo.cpp \
    core/bevanda.cpp \
    core/bottiglia.cpp \
    core/comanda.cpp \
    core/consumabile.cpp \
    core/contatto.cpp \
    core/farina.cpp \
    core/gestoreComande.cpp \
    core/gestoreRisorse.cpp \
    core/ingrediente.cpp \
    core/lattina.cpp \
    core/pizza.cpp \
    core/pizzeria.cpp \
    core/risorsa.cpp \
    GUI/controller.cpp \
    GUI/MainWindow.cpp \
    test/main.cpp \
    GUI/header.cpp \
    GUI/menu.cpp \
    GUI/analogclock.cpp \
    GUI/comande.cpp \
    GUI/inventario.cpp \
    GUI/contabilizzazione.cpp \
    GUI/tabellacomposita.cpp \
    GUI/digitalclock.cpp \
    GUI/wizardNuovoArticolo/wizardNuovoArticolo.cpp \
    GUI/wizardNuovoArticolo/wizard_intro.cpp \
    GUI/wizardNuovoArticolo/wizard_pizza.cpp \
    GUI/wizardNuovoArticolo/wizard_bevanda.cpp \
    GUI/wizardNuovoArticolo/wizard_end.cpp \
    GUI/dettaglioComanda.cpp \
    GUI/comandagui.cpp
    #test/testgui.cpp

HEADERS += \
    core/articolo.h \
    core/bevanda.h \
    core/bottiglia.h \
    core/comanda.h \
    core/consumabile.h \
    core/contatto.h \
    core/farina.h \
    core/gestoreComande.h \
    core/gestoreRisorse.h \
    core/ingrediente.h \
    core/lattina.h \
    core/pizza.h \
    core/pizzeria.h \
    core/qontainer.h \
    core/risorsa.h \
    GUI/controller.h \
    GUI/MainWindow.h \
    GUI/header.h \
    GUI/menu.h \
    GUI/analogclock.h \
    GUI/comande.h \
    GUI/inventario.h \
    GUI/contabilizzazione.h \
    GUI/tabellacomposita.h \
    GUI/digitalclock.h \
    GUI/wizardNuovoArticolo/wizardNuovoArticolo.h \
    GUI/wizardNuovoArticolo/wizard_intro.h \
    GUI/wizardNuovoArticolo/wizard_pizza.h \
    GUI/wizardNuovoArticolo/wizard_bevanda.h \
    GUI/wizardNuovoArticolo/wizard_end.h \
    GUI/dettaglioComanda.h \
    GUI/comandagui.h
    #test/testgui.h
