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
    GUI/comande.cpp \
    GUI/inventario.cpp \
    GUI/contabilizzazione.cpp \
    GUI/tabellacomposita.cpp \
    GUI/digitalclock.cpp \
    GUI/wizardNuovoArticolo/wizard_nuovoArticolo.cpp \
    GUI/wizardNuovoArticolo/nuovoArticolo_intro.cpp \
    GUI/wizardNuovoArticolo/nuovoArticolo_pizza.cpp \
    GUI/wizardNuovoArticolo/nuovoArticolo_bevanda.cpp \
    GUI/wizardNuovoArticolo/nuovoArticolo_end.cpp \
    GUI/comandagui.cpp \
    GUI/wizardNuovoConsumabile/wizard_nuovoConsumabile.cpp \
    GUI/wizardNuovoConsumabile/nuovoConsumabile_intro.cpp \
    GUI/wizardNuovoConsumabile/nuovoConsumabile_dettagli.cpp \
    GUI/wizardNuovoConsumabile/nuovoConsumabile_end.cpp \
    GUI/wizardNuovoArticolo/nuovoArticolo_dettagli.cpp \
    GUI/pushbuttonwithid.cpp \
    GUI/inputValidator.cpp \
    GUI/paginaComanda.cpp \
    GUI/wizardNuovaComanda/wizard_nuovaComanda.cpp \
    GUI/wizardNuovaComanda/nuovaComanda_dettagli.cpp \
    GUI/wizardNuovaComanda/nuovaComanda_end.cpp \
    GUI/tabellarisorse.cpp \
    GUI/tabellacomande.cpp \

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
    GUI/comande.h \
    GUI/inventario.h \
    GUI/contabilizzazione.h \
    GUI/tabellacomposita.h \
    GUI/digitalclock.h \
    GUI/wizardNuovoArticolo/wizard_nuovoArticolo.h \
    GUI/wizardNuovoArticolo/nuovoArticolo_intro.h \
    GUI/wizardNuovoArticolo/nuovoArticolo_pizza.h \
    GUI/wizardNuovoArticolo/nuovoArticolo_bevanda.h \
    GUI/wizardNuovoArticolo/nuovoArticolo_end.h \
    GUI/comandagui.h \ 
    GUI/wizardNuovoConsumabile/wizard_nuovoConsumabile.h \
    GUI/wizardNuovoConsumabile/nuovoConsumabile_intro.h \
    GUI/wizardNuovoConsumabile/nuovoConsumabile_dettagli.h \
    GUI/wizardNuovoConsumabile/nuovoConsumabile_end.h \
    GUI/wizardNuovoArticolo/nuovoArticolo_dettagli.h \
    GUI/pacchetti.h \
    GUI/pushbuttonwithid.h \
    GUI/paginaComanda.h \
    GUI/wizardNuovaComanda/wizard_nuovaComanda.h \
    GUI/wizardNuovaComanda/nuovaComanda_dettagli.h \
    GUI/wizardNuovaComanda/nuovaComanda_end.h \
    GUI/tabellarisorse.h \
    GUI/tabellacomande.h
    #test/testgui.h \

RESOURCES += \
    GUI/resources.qrc
