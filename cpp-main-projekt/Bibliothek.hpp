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

        // TODO: benutzer hinzufügen, anzeigen und löschen
        

        
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