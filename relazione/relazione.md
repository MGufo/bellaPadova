---
title: Relazione progetto Programmazione a Oggetti A.A. 2019/20
author: Gabriel Bizzo - 1170734, Marco Rosin - 1120673, Andrea Moscon - 1121217
date: Relazione di Rosin Marco
---
![bellaPadova](./logo.png){ width=50% }
 \newline \newline ![Università degli Studi di Padova | Dipartimento di Matematica](./uniPD_DM.jpg){ width=75% }

# Abstract e Funzionalità

Lo scopo del progetto è realizzare una 

# Progettezione e descrizione delle gerarchie utilizzate

# Chiamate Polimorfe

- getPrezzo (solo articolo)
- `carica` 
- `salva`
- `getComposizione` (solo articolo)
- `clone`
- `modifica`
- `getSpesa` (solo consumabile)
- `rendiEditabile()`: Metodo virtuale puro appartenente alla classe `tabellacomposita` 


# I/O

Il programma permette caricamento e salvataggio dei dati su file in formato JSON. È stato scelto il formato JSON in quanto:

- Ha una sintassi semplice e leggibile
- È notevolmente meno verboso rispetto al formato XML. 
- Supporta nativamente il caricamento e salvataggio delle mappe non ordinate, che sono state usate in modo estensivo nel modello dell'applicazione

Per implementare tali funzionalità sono state usate le apposite classi della libreria Qt (`QJsonDocument`, `QJsonObject` ecc).

Al fine di aumentare l'estensibilità del codice invece di implementare un'unica funzione di salvataggio/caricamento nell'interfaccia pubblica del modello si è deciso di fornire a ogni classe i metodi `carica()` e `salva()`, che hanno rispettivamente il compito di inizializzare i campi dati dell'oggetto di invocazione con i valori presenti nel file (_deserializzazione_) e di salvare i valori dei campi dati dell'oggetto di invocazione su file (serializzazione). Con questa implementazione il progettista che vorrà estendere la gerarchia dovrà solamente fornire l'implementazione di questi metodi per fornire la funzionalità di I/O alle classi da lui aggiunte. 

Il caricamento delle risorse avviene in automatico ad ogni apertura del programma attraverso il metodo `caricaRisorse()`.
Il salvataggio è manuale e a discrezione dell'utente; tuttavia per prevenire accidentali perdite di dati non salvati alla chiusura del programma viene visualizzata una finestra di dialogo in cui è possibile scegliere se salvare i dati modificati prima di uscire o meno. È inoltre possibile salvare manualmente i dati del programma selezionando l'opzione "Inventario e Menu" all'interno della sezione "Salva" nella barra dei menu.

È inoltre possibile modificare manualmente il contenuto dei file JSON: tuttavia questo metodo è fortemente sconsigliato in quanto un errore di sintassi nel file provocherebbe un errato caricamento dei dati.

# Istruzioni di compilazione

Il progetto è stato sviluppato utilizzando alcune funzionalità presenti in C++11 (`auto`, `nullptr` e `to_string`). Per questo motivo è stato necessario modificare il file .pro aggiungendo la direttiva "`CONFIG += c+11`".

Per compilare ed eseguire il programma sono quindi necessari i seguenti comandi (si suppone che il terminale sia aperto nella cartella del progetto):

1. `qmake bellaPadova.pro`
2. `make`
3. `./bellaPadova`

# Suddivisione dei compiti - Ore di sviluppo 


GUI: wizard, widget, controller 
Andrea: modello
Gufo: Codifica del modello, parte del controller, parte della GUI

Tutto lo sviluppo 
Per la realizzazione ..

- Gabriel (modello[gerarchia,qontainer,I/O(poco)], GUI[cotroller, widget principali vista, wizard])
- Andrea (modello[gerarchia,qontainer], GUI[controller, widget secondari, CSS])
- Gufo (modello[gerarchia,qontainer,I/O], GUI[controller, widget principali/secondari])

- Progettazione modello: 2 ore
- Progettazione GUI: 3 ore 
- Apprendimento libreria Qt: 3 ore + 7 ore tutorato
- Codifica modello: 10 ore
- Codifica GUI: 20 ore
- Debugging e testing: 10 ore
- Stesura relazione: 2 ore

# Ambiente di sviluppo

Il progetto è stato sviluppato in un'ambiente così configurato:

- **Sistema Operativo:** Microsoft Windows 10 Pro N 64bit (ver 1903)
- **Compilatore:** MinGW 5.3.0 32bit
- **Qt** ver 5.9.5

Modello e container sono stati sviluppati utilizzando l'IDE Visual Studio Code, poiché la maggior familiarità con esso ha permesso di eliminare il tempo di adattamento a un nuovo IDE. Successivamente il progetto è stato migrato a QtCreator in quanto la continua configurazione manuale (scrittura del _makefile_, _linking_ delle librerie Qt) è stata ritenuta ingestibile.

La fase di testing/debugging è stata svolta simultaneamente in ambienti Windows e Linux (quest'ultimo in particolare per la ricerca di _memory leak_ tramite _Valgrind_).