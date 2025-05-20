#include <Buch.hpp>
#include <Zeitschrift.hpp>
#include <DVD.hpp>
#include <Benutzer.hpp>

#define MAX_ANZAHL_BUCH 50
#define MAX_ANZAHL_ZEIT 50
#define MAX_ANZAHL_DVD  50
#define MAX_ANZAHL_BENUTZER 100 
#define MAX_ANZAHL_AUSGELIEHEN 150

using namespace std;

class Bibliothek {
    private:
        unsigned int index_benutzer=0;
        unsigned int index_buch=0;
        unsigned int index_zeitschrift=0;
        unsigned int index_dvd=0;
        unsigned int index_ausgeliehene_medien=0;

        Buch list_of_buecher[MAX_ANZAHL_BUCH];
        Zeitschrift list_of_zeitschriften[MAX_ANZAHL_ZEIT];
        DVD list_of_dvds[MAX_ANZAHL_DVD];
        Benutzer list_of_benutzer[MAX_ANZAHL_BENUTZER];
        unsigned int list_of_ausgeliehene_medien[MAX_ANZAHL_AUSGELIEHEN][2]; // [0] = id von benutzer (wer), [1] = id von medien (was)

        unsigned int id_buecher=101;
        unsigned int id_zeitschriften=201;
        unsigned int id_dvds=301;
        unsigned int id_benutzer=1001;
    

    public:
        Bibliothek() {}
        ~Bibliothek() {
            cout << "Bibliothek destructor called" << endl;
        }

        bool UngueltigEingaben(string eingabe) {
            for (int i = 0; i < eingabe.size(); i++) {
                int ascii = eingabe[i];
                if (!((ascii >= 48 && ascii <= 57) ||     // 0-9
                        (ascii >= 65 && ascii <= 90) ||     // A-Z
                        (ascii >= 97 && ascii <= 122))) {   // a-z
                        cout << "Eingabe darf nur Buchstaben oder Zahlen enthalten!" << endl;
                        return true;
                }
            }
                
                if (eingabe.empty()) {
                    cout << "Eingabe darf nicht leer sein!" << endl;
                    return true;
                }

            return false;
        }

        
        /////////////////////////// Funktionen für Benutzer ///////////////////////////
        bool BenutzerHinzufuegen(string name) { // TODO: lowercase
            for (int i = 0; i < index_benutzer; i++) {
                if (list_of_benutzer[i].GetName() == name) {
                    cout << "Benutzer mit diesem Namen existiert bereits!" << endl;
                    return false;
                }
            }

            if (index_benutzer >= MAX_ANZAHL_BENUTZER) {
                cout << "Maximale Anzahl an Benutzern erreicht!" << endl;
                return false;
            }
            
            
            if (UngueltigEingaben(name)) {
                return false;
            }
            
            list_of_benutzer[index_benutzer] = Benutzer(name, id_benutzer);
            id_benutzer++;
            index_benutzer++;
            cout << "Benutzer hinzugefügt: " << name << "  mit ID: " << list_of_benutzer[index_benutzer-1].GetId() << endl;
            return true;
        }
        
        unsigned int SearchBenutzer(string name) {
            for (int i = 0; i < index_benutzer; i++) {
                if (list_of_benutzer[i].GetName() == name) {
                    return i;
                }
            }
            return -1;
        } 
        
        void InfoFuerEinBenutzer(string name){
            int index = SearchBenutzer(name);
            if (index == -1) {
                cout << "Benutzer nicht gefunden!" << endl;
            }
            else {
                cout << "Benutzer ID: " << list_of_benutzer[index].GetId() << endl;
                cout << "Benutzer Name: " << list_of_benutzer[index].GetName() << endl;
                cout << "Ausgeliehene Medien: " << endl;
                if (list_of_benutzer[index].GetIndex() == 0) {
                    cout << "\tKeine ausgeliehenen Medien!" << endl;
                }
                for (int i = 0; i < list_of_benutzer[index].GetIndex(); i++) {
                    FindBuchAndShowInfo_id(list_of_benutzer[index].GetListeAusgeliehenerBuecher()[i]);
                }
                cout << endl;
            }
        }

        void InfoFuerAlleBenutzer() {  
            cout << "Alle Benutzer: " << endl;
            for (int i = 0; i < index_benutzer; i++) {
                cout << "\tBenutzer ID: " << list_of_benutzer[i].GetId() << endl;
                cout << "\tBenutzer Name: " << list_of_benutzer[i].GetName() << endl;
                cout << "\tAusgeliehene Medien: " << endl;
                if (list_of_benutzer[i].GetIndex() == 0) {
                    cout << "\t\tKeine ausgeliehenen Medien!" << endl;
                }
                for (int j = 0; j < list_of_benutzer[i].GetIndex(); j++) {
                    FindBuchAndShowInfo_id(list_of_benutzer[i].GetListeAusgeliehenerBuecher()[j]);
                }
                cout << endl;
            }
        }
        
        // TODO: benutzer , anzeigen und löschen
        ///////////////////////////////////////////////////////////////////////////////
        
        
        
        void FindBuchAndShowInfo_id(unsigned int id) {} //TODO: name und datum anzeigen
        // TODO: buch hinzufügen, anzeigen und löschen
        // TODO: zeitschrift hinzufügen, anzeigen und löschen 
        // TODO: dvd hinzufügen, anzeigen und löschen

        

        // TODO: list of ausgeliehene medien anzeigen
        // TODO: ausleihen und zurückgeben
        // TODO: benutzer und medien suchen
        // TODO: alle medien anzeigen
        // TODO: alle benutzer anzeigen
        // TODO: alle ausgeliehenen medien nicht zurückgegeben anzeigen
        
        

        // TODO: load data from file



};