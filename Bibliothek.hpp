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

        
        /////////////////////////////////// Benutzer ///////////////////////////////////
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
        
        void AnzeigenFuerEinBenutzer(string name){
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
                    AnzeigenMedienMitId(list_of_benutzer[index].GetListeAusgeliehenerBuecher()[i]);
                }
                cout << endl;
            }
        }

        void AnzeigenFuerAlleBenutzer() {  
            cout << "Alle Benutzer: " << endl;
            for (int i = 0; i < index_benutzer; i++) {
                cout << "\tBenutzer ID: " << list_of_benutzer[i].GetId() << endl;
                cout << "\tBenutzer Name: " << list_of_benutzer[i].GetName() << endl;
                cout << "\tAusgeliehene Medien: " << endl;
                if (list_of_benutzer[i].GetIndex() == 0) {
                    cout << "\t\tKeine ausgeliehenen Medien!" << endl;
                }
                for (int j = 0; j < list_of_benutzer[i].GetIndex(); j++) {
                    AnzeigenMedienMitId(list_of_benutzer[i].GetListeAusgeliehenerBuecher()[j]);
                }
                cout << endl;
            }
        }
        
        void BenutzerLoeschen(string name) {
            unsigned int temp_id = SearchBenutzer(name);
            if (temp_id == -1) {
                cout << "Benutzer nicht gefunden!" << endl;
                return;
            }
            for (int i = temp_id; i < index_benutzer - 1; i++) {
                list_of_benutzer[i] = list_of_benutzer[i + 1];
            }
            index_benutzer--;
            cout << "Benutzer gelöscht: " << name << endl;
        }
 
        ////////////////////////////////////////////////////////////////////////////////
        

        //////////////////////////////////// Medien ////////////////////////////////////
        void AnzeigenMedienMitId(unsigned int id) {
            cout << "+-------------------------------------------+" << endl;
            switch(id/100){

                case 1:
                    cout << "|\tBUCH:" << endl;
                    for (int i = 0; i < index_buch; i++) {
                        if (list_of_buecher[i].GetId() == id) {
                            list_of_buecher[i].Anzeigen();
                        }
                    }
                    break;
                
                case 2:
                    cout << "|\tZEITSCHRIFT:" << endl;
                    for (int i = 0; i < index_zeitschrift; i++) {
                        if (list_of_zeitschriften[i].GetId() == id) {
                            list_of_zeitschriften[i].Anzeigen();
                        }
                    }
                    break;

                case 3:
                    cout << "|\tDVD:" << endl;
                    for (int i = 0; i < index_dvd; i++) {
                        if (list_of_dvds[i].GetId() == id) {
                            list_of_dvds[i].Anzeigen();
                        }
                    }

                default:
                    cout << "|\t\tUnbekannter Typ oder not found!" << endl;
                    break;
            }
            cout << "+-------------------------------------------+" << endl;
        }
        
        void AnzeigenMedienAll(int type) {//ch
            cout << "+-------------------------------------------+" << endl;            
            switch(type) {
                case 1:
                    cout << "|\tBUCH:" << endl;
                    for (int i = 0; i < index_buch; i++) {
                        list_of_buecher[i].Anzeigen();
                        cout << "---------------------------------------------" << endl;
                    }
                    break;
                
                case 2:
                    cout << "|\tZEITSCHRIFT:" << endl;
                    for (int i = 0; i < index_zeitschrift; i++) {
                        list_of_zeitschriften[i].Anzeigen();
                    }
                    break;

                case 3:
                    cout << "|\tDVD:" << endl;
                    for (int i = 0; i < index_dvd; i++) {
                        list_of_dvds[i].Anzeigen();
                    }
                    break;

                default:
                    cout << "|\t\tUnbekannter Typ!" << endl;
                    break;
            }
            cout << "+-------------------------------------------+" << endl;
        }
        ////////////////////////////////////////////////////////////////////////////////


        ///////////////////////////////////// Buch /////////////////////////////////////
        void HinzufuegenBuch(string title, string autor, unsigned int ISBN, bool verfuegbar) {
            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetTitel() == title) {
                    cout << "Buch mit diesem Titel existiert bereits!" << endl;
                    return;
                }
            }

            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetISBN() == ISBN) {
                    cout << "Buch mit dieser ISBN existiert bereits!" << endl;
                    return;
                }
            }
            
            if (index_buch >= MAX_ANZAHL_BUCH) {
                cout << "Maximale Anzahl an Buechern erreicht!" << endl;
                return;
            }

            list_of_buecher[index_buch] = Buch(title, id_buecher, verfuegbar, autor, ISBN);
            id_buecher++;
            index_buch++;
            cout << "Buch hinzugefügt: " << title << "  mit ID: " << list_of_buecher[index_buch-1].GetId() << endl;
        }
        
        void AnzeigenBuchMitIndex(unsigned int index) {
            if (index == -1) {
                cout << "Buch nicht gefunden!" << endl;
                return;
            } 
            else {
                cout << "+-------------------------------------------+" << endl;            
                cout << "Buch gefunden: \n";
                list_of_buecher[index].Anzeigen();
                cout << "+-------------------------------------------+" << endl;            
            }
        }

        unsigned int SearchBuchTitle(string title) {
            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetTitel() == title) {
                    return i;
                }
            }
            return -1;
        }

        unsigned int SearchBuchISBN(unsigned int ISBN) {
            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetISBN() == ISBN) {
                    return i;
                }
            }
            return -1;
        }

        void SearchBuchAutherAndShow(string autor) { // 
            bool temp = true;
            cout << "+-------------------------------------------+" << endl;            
            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetAutor() == autor) {
                    list_of_buecher[i].Anzeigen();
                    temp = false;
                }
            }
            if (temp) {
                cout << "Buch nicht gefunden!" << endl;
            }   
            cout << "+-------------------------------------------+" << endl;            
        }
        
        void LoeschenBuch(unsigned int index) {
            if (index == -1) {
                cout << "Buch nicht gefunden!" << endl;
                return;
            }
            for (int i = index; i < index_buch - 1; i++) {
                list_of_buecher[i] = list_of_buecher[i + 1];
            }
            index_buch--;
            cout << "Buch gelöscht! " << endl;
        }

        ////////////////////////////////////////////////////////////////////////////////
        

        ////////////////////////////////// Zeitschrift //////////////////////////////////
        void HinzufuegenZeitschrift(string title, unsigned int ausgaabe_nummer, bool verfuegbar) {
            for (int i = 0; i < index_zeitschrift; i++) {
                if (list_of_zeitschriften[i].GetTitel() == title) {
                    cout << "Zeitschrift mit diesem Titel existiert bereits!" << endl;
                    return;
                }
            }

            if (index_zeitschrift >= MAX_ANZAHL_ZEIT) {
                cout << "Maximale Anzahl an Zeitschriften erreicht!" << endl;
                return;
            }

            list_of_zeitschriften[index_zeitschrift] = Zeitschrift(title, id_zeitschriften, verfuegbar, ausgaabe_nummer);
            id_zeitschriften++;
            index_zeitschrift++;
            cout << "Zeitschrift hinzugefügt: " << title << "  mit ID: " << list_of_zeitschriften[index_zeitschrift-1].GetId() << endl;
        }

        void AnzeigenZeitschriftMitIndex(unsigned int index) {
            if (index == -1) {
                cout << "Zeitschrift nicht gefunden!" << endl;
                return;
            } 
            else {
                cout << "+-------------------------------------------+" << endl;            
                cout << "Zeitschrift gefunden: \n";
                list_of_zeitschriften[index].Anzeigen();
                cout << "+-------------------------------------------+" << endl;            
            }
        }

        unsigned int SearchZeitschriftTitle(string title) {
            for (int i = 0; i < index_zeitschrift; i++) {
                if (list_of_zeitschriften[i].GetTitel() == title) {
                    return i;
                }
            }
            return -1;
        }

        unsigned int SearchZeitschriftAusgaabeNummer(unsigned int ausgaabe_nummer) {
            for (int i = 0; i < index_zeitschrift; i++) {
                if (list_of_zeitschriften[i].GetAusgaabeNummer() == ausgaabe_nummer) {
                    return i;
                }
            }
            return -1;
        }
        
        void LoschenZeitschrift(unsigned int index) {
            if (index == -1) {
                cout << "Zeitschrift nicht gefunden!" << endl;
                return;
            }
            for (int i = index; i < index_zeitschrift - 1; i++) {
                list_of_zeitschriften[i] = list_of_zeitschriften[i + 1];
            }
            index_zeitschrift--;
            cout << "Zeitschrift gelöscht! " << endl;
        }

        /////////////////////////////////////////////////////////////////////////////////


        ///////////////////////////////////// DVD ///////////////////////////////////////
        void HinzufuegenDVD(string title, unsigned int stunde, unsigned int minute, unsigned int sekunde, bool verfuegbar) {
            for (int i = 0; i < index_dvd; i++) {
                if (list_of_dvds[i].GetTitel() == title) {
                    cout << "DVD mit diesem Titel existiert bereits!" << endl;
                    return;
                }
            }

            if (index_dvd >= MAX_ANZAHL_DVD) {
                cout << "Maximale Anzahl an DVDs erreicht!" << endl;
                return;
            }

            list_of_dvds[index_dvd] = DVD(title, id_dvds, verfuegbar);
            list_of_dvds[index_dvd].SetAbspieldauer(stunde, minute, sekunde);
            id_dvds++;
            index_dvd++;
            cout << "DVD hinzugefügt: " << title << "  mit ID: " << list_of_dvds[index_dvd-1].GetId() << endl;
        }

        void AnzeigenDVDMitIndex(unsigned int index) {
            if (index == -1) {
                cout << "DVD nicht gefunden!" << endl;
                return;
            } 
            else {
                cout << "+-------------------------------------------+" << endl;            
                cout << "DVD gefunden: \n";
                list_of_dvds[index].Anzeigen();
                cout << "+-------------------------------------------+" << endl;            
            }
        }

        unsigned int SearchDVDTitle(string title) {
            for (int i = 0; i < index_dvd; i++) {
                if (list_of_dvds[i].GetTitel() == title) {
                    return i;
                }
            }
            return -1;
        }

        void LoschenDVD(unsigned int index) {
            if (index == -1) {
                cout << "DVD nicht gefunden!" << endl;
                return;
            }
            for (int i = index; i < index_dvd - 1; i++) {
                list_of_dvds[i] = list_of_dvds[i + 1];
            }
            index_dvd--;
            cout << "DVD gelöscht! " << endl;
        }

        ///////////////////////////////////////////////////////////////////////////////// 
        
        // TODO: name und datum anzeigen
        

        // TODO: list of ausgeliehene medien anzeigen, add to list of ausgeliehene medien
        // TODO: ausleihen und zurückgeben , manage lisst of ausgeliehene medien
        // TODO: benutzer und medien suchen
        // TODO: alle medien anzeigen
        // TODO: alle benutzer anzeigen
        // TODO: alle ausgeliehenen medien nicht zurückgegeben anzeigen
        
        

        // TODO: load data from file



};