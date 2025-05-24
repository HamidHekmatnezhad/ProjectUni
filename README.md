# Library Management System – OOP Project

This project was a university-level assignment focused on practicing object-oriented programming in C++. It implements a basic **library management system** that supports adding users and media (books, DVDs, magazines), as well as lending and returning operations.

From my perspective, the `main.cpp` program could have been structured much better. In particular, the overuse of nested code blocks and lack of modular functions made the code harder to read and maintain. It would have been much cleaner if functionality had been separated into proper functions.

Additionally, for a real-world application of this type, the best approach would be to use an SQL database to manage and relate the data. This would allow for more robust data storage, query capabilities, and separation of logic from data management.

---

### Project Features
- User management (add, delete, search)
- Media management (books, DVDs, magazines)
- Borrowing and returning functionality
- Overdue tracking
- Data import from `data.txt`

### Technologies Used
- C++ (Object-Oriented Programming)
- File-based storage for simplicity

### Possible Improvements
- Modularization of code (especially in `main.cpp`)
- Replacing file storage with SQL database
- Improved user interface and validation

---

### Author
Hamid Hekmatnezhad – 2025  
Technische Hochschule Deggendorf


# PoP-Programmieraufgabe SS2025
C++ Programmieraufgabe: "Bibliotheksverwaltungssystem"

## Ziel:
Entwickeln Sie ein Konsolenprogramm zur Verwaltung einer Bibliothek. Das Programm soll
Benutzer, Benutzer und Ausleihen verwalten können.

## Funktionsumfang

1. Datenmodell:
Erstellen Sie geeignete Klassen für:

### Medium
Eigenschaften:
- Titel
- Inventar-ID
- Verfügbarkeit (ausgeliehen oder nicht)
- Ausleihdatum
- Rückgabedatum
  
Methoden:
- Virtual void anzeigen(); // Anzeige aller Eigenschaften
- Virtual string typ(); // Anzeige das Medium-Typs
- virtual operator<<: Gibt ein Medium formatiert auf dem ostream aus
- operator==: Vergleicht zwei Medien anhand ihrer inventarID

Abgeleitete Klassen von Medium
### Buch
Eigenschaften:
- Autor
- ISBN

Methoden:
- void anzeigen();
- string typ();

### Zeitschrift
Eigenschaften:
 - Ausgabenummer

### DVD
 - Abspieldauer


### Benutzer
Eigenschaften:
- Name
- Benutzer-ID
- Liste ausgeliehener Bücher

Methoden:
- Void ausleihen(Buch, Zeitschrift oder DVD));
- Void Zurückgeben (Inventar-ID);
- void anzeigen() const; // Liste der ausgeliehen Bücher

## 2. Funktionalitäten:
### 1. Bibliotheksverwaltung
 - Buch, Zeitschrift, DVD hinzufügen
 - Buch, Zeitschrift, DVD anzeigen (inkl. Verfügbarkeitsstatus)
 - Buch, Zeitschrift, DVD entfernen
### 2. Benutzerverwaltung
 - Benutzer registrieren
 - Benutzerinformationen anzeigen
 - Benutzer entfernen
### 3. Ausleihsystem
 - Buch, Zeitschrift, DVD ausleihen (nur wenn verfügbar)
 - Buch, Zeitschrift, DVD zurückgeben
 - Liste der aktuell ausgeliehenen Bücher, Zeitschriften, DVD eines Benutzers anzeigen
### 4. Suche nach Medium (nach Titel, Autor oder ISBN)
### 5. Anzeige aller überfälligen Medien (Rückgabedatum liegt in der Vergangenheit)

## 3. Anforderungen
- Kommentierter und lesbarer Code
- Einhaltung der Google Code Styles
- Verwendung von Klassen mit sinnvollen Methoden, Konstruktoren und Destruktoren
- Trennung von Logik und UI (z. B. Menü in main(), Logik in eigenen Klassen)
- Einfache Fehlerbehandlung (z. B. bei ungültigen Eingaben)4. 

## 4. Dateiarchitektur-Vorschlag
```
src/
├── main.cpp
├── Medium.hpp / Medium.cpp
├── Buch.hpp / Buch.cpp
├── Zeitschrift.hpp / Zeitschrift.cpp
├── DVD.hpp / DVD.cpp
├── Benutzer.hpp / Benutzer.cpp
└── Bibliothek.hpp / Bibliothek.cpp
```