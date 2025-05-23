#include "Buch.hpp"
#include "Zeitschrift.hpp"
#include "DVD.hpp"
#include "Benutzer.hpp"

#define MAX_ANZAHL_BUCH 50
#define MAX_ANZAHL_ZEIT 50
#define MAX_ANZAHL_DVD  50
#define MAX_ANZAHL_BENUTZER 100 
#define MAX_ANZAHL_AUSGELIEHEN 150

using namespace std;

ostream& operator<<(ostream& os, Medium& m) {
    m.Anzeigen();
    return os;
}

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

        unsigned int ausleihdauer=90;
    

    public:
        Bibliothek() {}
        ~Bibliothek() {}

        bool UngueltigEingaben(string eingabe) {
            for (int i = 0; i < eingabe.size(); i++) {
                int ascii = eingabe[i];
                if (!((ascii >= 48 && ascii <= 57) ||     // 0-9
                        (ascii >= 65 && ascii <= 90) ||     // A-Z
                        (ascii >= 97 && ascii <= 122) || // a-z
                        (ascii == 32))) {  // space
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

        bool IsNotNumber(string eingabe) {
            for (int i = 0; i < eingabe.size(); i++) {
                if (!(eingabe[i] >= '0' && eingabe[i] <= '9')) {
                    cout << "Eingabe darf nur Zahlen enthalten!" << endl;
                    return true;
                }
            }
            return false;
        }

        string ToLowerCase(string eingabe) {
            for (int i = 0; i < eingabe.size(); i++) {
                if (eingabe[i] >= 'A' && eingabe[i] <= 'Z') {
                    eingabe[i] += 32;
                }
            }
            return eingabe;
        }

        unsigned int GetAusleihdauer() {
            return ausleihdauer;
        }

        bool UngueltigInputUnsignedInt(unsigned int eingabe) {
            if (eingabe < 0) {
                cout << "Eingabe darf nicht negativ sein!" << endl;
                return true;
            }
            if (eingabe == 0) {
                cout << "Eingabe darf digit sein!" << endl;
                return true;
            }
            return false;
        }

        //////////////////////////////////// Medien ////////////////////////////////////
        void AnzeigenMedienMitId(unsigned int id) {
            cout << "+-------------------------------------------+" << endl;
            switch(id/100){

                case 1:
                    cout << "|\tBUCH:" << endl;
                    for (int i = 0; i < index_buch; i++) {
                        if (list_of_buecher[i].GetId() == id) {
                            list_of_buecher[i].Anzeigen();
                            break;
                        }
                    }
                    break;
                
                case 2:
                    cout << "|\tZEITSCHRIFT:" << endl;
                    for (int i = 0; i < index_zeitschrift; i++) {
                        if (list_of_zeitschriften[i].GetId() == id) {
                            list_of_zeitschriften[i].Anzeigen();
                            break;
                        }
                    }
                    break;

                case 3:
                    cout << "|\tDVD:" << endl;
                    for (int i = 0; i < index_dvd; i++) {
                        if (list_of_dvds[i].GetId() == id) {
                            list_of_dvds[i].Anzeigen();
                            break;
                        }
                    }

                default:
                    cout << "|\t\tUnbekannter Typ oder not found!" << endl;
                    break;
            }
            cout << "+-------------------------------------------+" << endl;
        }
        
        void AnzeigenAllMedien(int type) {
            // 0 = alle, 1 = buecher, 2 = zeitschriften, 3 = dvds
            cout << "+-------------------------------------------+" << endl;            
            if (type == 1 || type == 0) {
                    cout << "------------+  BUCH  +------------" << endl;
                    for (int i = 0; i < index_buch; i++) {
                        list_of_buecher[i].Anzeigen();
                        cout << "---------------------------------------------" << endl;
                    }
                }
                
                if (type == 2 || type == 0) {
                cout << "------------+  ZEITSCHRIFT  +------------" << endl;
                    for (int i = 0; i < index_zeitschrift; i++) {
                        list_of_zeitschriften[i].Anzeigen();
                        cout << "---------------------------------------------" << endl;
                    }
                }

                if (type == 3 || type == 0) {
                cout << "------------+  DVD  +------------" << endl;
                    for (int i = 0; i < index_dvd; i++) {
                        list_of_dvds[i].Anzeigen();
                        cout << "---------------------------------------------" << endl;
                    }
                }
                cout << "+-------------------------------------------+" << endl;
            }

        ////////////////////////////////////////////////////////////////////////////////


        /////////////////////////////////// Benutzer ///////////////////////////////////
        void BenutzerHinzufuegen(string name) {
            name = ToLowerCase(name);
            for (int i = 0; i < index_benutzer; i++) {
                if (list_of_benutzer[i].GetName() == name) {
                    cout << "Benutzer mit diesem Namen existiert bereits!" << endl;
                    return;
                }
            }

            if (index_benutzer >= MAX_ANZAHL_BENUTZER) {
                cout << "Maximale Anzahl an Benutzern erreicht!" << endl;
                return;
            }
            
            
            if (UngueltigEingaben(name)) {
                return;
            }
            
            list_of_benutzer[index_benutzer] = Benutzer(name, id_benutzer);
            id_benutzer++;
            index_benutzer++;
            cout << "Benutzer hinzugefügt: " << name << "  mit ID: " << list_of_benutzer[index_benutzer-1].GetId() << endl;
        }
        
        unsigned int SearchBenutzerMitName(string name) {
            for (int i = 0; i < index_benutzer; i++) {
                if (list_of_benutzer[i].GetName() == name) {
                    return i; // return index
                }
            }
            return -1;
        } 

        unsigned int SearchBenutzerMitId(unsigned int id) {
            for (int i = 0; i < index_benutzer; i++) {
                if (list_of_benutzer[i].GetId() == id) {
                    return i; // return index
                }
            }
            return -1;
        }
        
        void AnzeigenFuerEinBenutzer(unsigned int id){
            int index = SearchBuchMitId(id);
            if (index == -1) {
                cout << "Benutzer nicht gefunden!" << endl;
            }
            else {
                cout << "Benutzer ID: " << list_of_benutzer[index].GetId() << endl;
                cout << "Benutzer Name: " << list_of_benutzer[index].GetName() << endl;
                cout << "Ausgeliehene Medien: " << endl;
                if (list_of_benutzer[index].GetIndex() == 0) {
                    cout << "\tKeine ausgeliehenen Medien!" << endl;
                    return;
                }
                cout << "\tAusgeliehene Medien: " << endl;
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
                    return;
                }
                cout << "\tAusgeliehene Medien: " << endl;

                for (int j = 0; j < list_of_benutzer[i].GetIndex(); j++) {
                    AnzeigenMedienMitId(list_of_benutzer[i].GetListeAusgeliehenerBuecher()[j]);
                }
                cout << endl;
            }
        }
        
        void BenutzerLoeschen(unsigned int id) {
            unsigned int temp_idx = SearchBuchMitId(id);
            if (temp_idx == -1) {
                cout << "Benutzer nicht gefunden!" << endl;
                return;
            }
            for (int i = temp_idx; i < index_benutzer - 1; i++) {
                list_of_benutzer[i] = list_of_benutzer[i + 1];
            }
            index_benutzer--;
            cout << "Benutzer gelöscht: " << id << endl;
        }
 
        unsigned int GetBenutzerIndexMitId(unsigned int id) {
            for (int i = 0; i < index_benutzer; i++) {
                if (list_of_benutzer[i].GetId() == id) {
                    return i;
                }
            }
            return -1;
        }

        ////////////////////////////////////////////////////////////////////////////////
          

        ///////////////////////////////////// Buch /////////////////////////////////////
        void HinzufuegenBuch(string title, string autor, unsigned int ISBN, bool verfuegbar) {
            title = ToLowerCase(title);
            autor = ToLowerCase(autor);            

            if (UngueltigEingaben(title)) {return;}
            if (UngueltigEingaben(autor)) {return;}

            title = ToLowerCase(title);
            autor = ToLowerCase(autor);

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

        unsigned int SearchBuchMitId(unsigned int id) {
            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetId() == id) {
                    return i;
                }
            }
            return -1;
        }

        void SearchBuchTitleAnzeigen(string title) {
            bool temp = true;
            cout << "+-------------------------------------------+" << endl;            
            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetTitel() == title) {
                    cout << "Buch gefunden: \n";
                    list_of_buecher[i].Anzeigen();
                    temp = false;
                }
            }
            if (temp) {cout << "Buch nicht gefunden!" << endl;}
            cout << "+-------------------------------------------+" << endl;            
        }

        void SearchBuchISBNAnzeigen(unsigned int ISBN) {
            bool temp = true;
            cout << "+-------------------------------------------+" << endl;
            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetISBN() == ISBN) {
                    cout << "Buch gefunden: \n";
                    list_of_buecher[i].Anzeigen();
                    temp = false;
                }
            }
            if (temp) {cout << "Buch nicht gefunden!" << endl;}
            cout << "+-------------------------------------------+" << endl;
        }

        void SearchBuchAutherAnzeigen(string autor) { 
            bool temp = true;
            cout << "+-------------------------------------------+" << endl;            
            for (int i = 0; i < index_buch; i++) {
                if (list_of_buecher[i].GetAutor() == autor) {
                    list_of_buecher[i].Anzeigen();
                    temp = false;
                }
            }
            if (temp) {cout << "Buch nicht gefunden!" << endl;}   
            cout << "+-------------------------------------------+" << endl;            
        }
        
        void LoeschenBuch(unsigned int id) {
            unsigned int index = SearchBuchMitId(id);
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
            title = ToLowerCase(title);
            if (UngueltigEingaben(title)) {return;}

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

        unsigned int SearchZeitschriftMitId(unsigned int id) {
            for (int i = 0; i < index_zeitschrift; i++) {
                if (list_of_zeitschriften[i].GetId() == id) {
                    return i;
                }
            }
            return -1;
        }

        void SearchZeitschriftTitleAnzeigen(string title) {
            bool temp = true;
            cout << "+-------------------------------------------+" << endl;
            for (int i = 0; i < index_zeitschrift; i++) {
                if (list_of_zeitschriften[i].GetTitel() == title) {
                    list_of_zeitschriften[i].Anzeigen();
                    temp = false;
                }
            }
            if (temp) {cout << "Zeitschrift nicht gefunden!" << endl;}
            cout << "+-------------------------------------------+" << endl;
        }

        void SearchZeitschriftAusgaabeNummerAnzeigen(unsigned int ausgaabe_nummer) {
            bool temp = true;
            cout << "+-------------------------------------------+" << endl;
            for (int i = 0; i < index_zeitschrift; i++) {
                if (list_of_zeitschriften[i].GetAusgaabeNummer() == ausgaabe_nummer) {
                    list_of_zeitschriften[i].Anzeigen();
                    temp = false;
                }
            }
            if (temp) {cout << "Zeitschrift nicht gefunden!" << endl;}
            cout << "+-------------------------------------------+" << endl;
        }
        
        void LoeschenZeitschrift(unsigned int id) {
            unsigned int index = SearchZeitschriftMitId(id);
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

        unsigned int GetZeitschriftIndexMitId(unsigned int id) {
            for (int i = 0; i < index_zeitschrift; i++) {
                if (list_of_zeitschriften[i].GetId() == id) {
                    return i;
                }
            }
            return -1;
        }
        /////////////////////////////////////////////////////////////////////////////////


        ///////////////////////////////////// DVD ///////////////////////////////////////
        void HinzufuegenDVD(string title, unsigned int stunde, unsigned int minute, unsigned int sekunde, bool verfuegbar) {
            title = ToLowerCase(title);
            if (UngueltigEingaben(title)) {return;}
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

        unsigned int SearchDVDMitId(unsigned int id) {
            for (int i = 0; i < index_dvd; i++) {
                if (list_of_dvds[i].GetId() == id) {
                    return i;
                }
            }
            return -1;
        }

        void SearchDVDTitleAnzeigen(string title) {
            bool temp = true;
            cout << "+-------------------------------------------+" << endl;
            for (int i = 0; i < index_dvd; i++) {
                if (list_of_dvds[i].GetTitel() == title) {
                    list_of_dvds[i].Anzeigen();
                    temp = false;
                }
            }
            if (temp) {cout << "DVD nicht gefunden!" << endl;}
            cout << "+-------------------------------------------+" << endl;
        }

        void LoeschenDVD(unsigned int id) {
            unsigned int index = SearchDVDMitId(id);
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

        unsigned int GetDVDIndexMitId(unsigned int id) {
            for (int i = 0; i < index_dvd; i++) {
                if (list_of_dvds[i].GetId() == id) {
                    return i;
                }
            }
            return -1;
        }
        ///////////////////////////////////////////////////////////////////////////////// 
        

        /////////////////////////////// Ausleihen system /////////////////////////////////
        void Ausleihen(unsigned int benutzer_id, unsigned int mediun_id, unsigned int ausleihdauer, int tag=0, int monat=0, int jahr=0) {
            
            
            int index_benutzer = GetBenutzerIndexMitId(benutzer_id);
            if (index_benutzer == -1) {
                cout << "Benutzer mit ID " << benutzer_id << " nicht gefunden!" << endl;
                return;
            }
            
            if (!(list_of_benutzer[index_benutzer].GetIndex() < list_of_benutzer[index_benutzer].GetMaxAusleihungen())) {
                cout << "Maximale Anzahl an ausgeliehenen Medien erreicht! fuer Benutzer mit ID " << benutzer_id << endl;
                return;
            }

            int index_temp = 0;
            switch (mediun_id/100) {
            case 1:
                index_temp = SearchBuchMitId(mediun_id);
                if (index_temp == -1) {
                    cout << "Buch mit ID " << mediun_id << " nicht gefunden!" << endl;
                    return;
                }
                if (!list_of_buecher[index_temp].GetVerfuegbar()){
                    cout << "Buch mit ID " << mediun_id << " ist nicht verfügbar!" << endl;
                    return;
                }

                list_of_buecher[index_temp].SetVerfuegbar(false);
                if (tag == 0){list_of_buecher[index_temp].SetAusleihdatum();} // default, set to now
                else {list_of_buecher[index_temp].SetAusleihdatum(jahr, monat, tag);}// set to custom date
                list_of_buecher[index_temp].SetRueckgabedatum(ausleihdauer);

                list_of_buecher[index_temp].ShowAusleihdatum();
                list_of_buecher[index_temp].ShowRueckgabedatum();

                break;

            case 2:
                index_temp = GetZeitschriftIndexMitId(mediun_id);
                if (index_temp == -1) {
                    cout << "Zeitschrift mit ID " << mediun_id << " nicht gefunden!" << endl;
                    return;
                }
                if (!list_of_zeitschriften[index_temp].GetVerfuegbar()){
                    cout << "Zeitschrift mit ID " << mediun_id << " ist nicht verfügbar!" << endl;
                    return;
                }

                list_of_zeitschriften[index_temp].SetVerfuegbar(false);
                if (tag == 0){list_of_zeitschriften[index_temp].SetAusleihdatum();}
                else {list_of_zeitschriften[index_temp].SetAusleihdatum(jahr, monat, tag);}
                list_of_zeitschriften[index_temp].SetRueckgabedatum(ausleihdauer);

                list_of_zeitschriften[index_temp].ShowAusleihdatum();
                list_of_zeitschriften[index_temp].ShowRueckgabedatum();

                break;

            case 3:
                index_temp = GetDVDIndexMitId(mediun_id);
                if (index_temp == -1) {
                    cout << "DVD mit ID " << mediun_id << " nicht gefunden!" << endl;
                    return;
                }
                if (!list_of_dvds[index_temp].GetVerfuegbar()){
                    cout << "DVD mit ID " << mediun_id << " ist nicht verfügbar!" << endl;
                    return;
                }

                list_of_dvds[index_temp].SetVerfuegbar(false);
                if (tag == 0){list_of_dvds[index_temp].SetAusleihdatum();}
                else {list_of_dvds[index_temp].SetAusleihdatum(jahr, monat, tag);}
                list_of_dvds[index_temp].SetRueckgabedatum(ausleihdauer);

                list_of_dvds[index_temp].ShowAusleihdatum();
                list_of_dvds[index_temp].ShowRueckgabedatum();

                break;
            
            default:
                cout << "Unbekannter Typ oder nicht gefunden!" << endl;
                return;
                break;
            }

            list_of_ausgeliehene_medien[index_ausgeliehene_medien][0] = benutzer_id;
            list_of_ausgeliehene_medien[index_ausgeliehene_medien][1] = mediun_id;
            index_ausgeliehene_medien++;
            list_of_benutzer[index_benutzer].Ausleihen(mediun_id);
            cout << "Benutzer mit ID " << benutzer_id << " Medium mit ID " << mediun_id << " erfolgreich ausgeliehen!" << endl;

        }

        void Zurueckgeben(unsigned int benutzer_id, unsigned int mediun_id) {
            int index_benutzer = GetBenutzerIndexMitId(benutzer_id);
            if (index_benutzer == -1) {
                cout << "Benutzer mit ID " << benutzer_id << " nicht gefunden!" << endl;
                return;
            }

            int index_temp = 0;
            switch (mediun_id/100) {
            case 1:
                index_temp = SearchBuchMitId(mediun_id);
                if (index_temp == -1) {
                    cout << "Buch mit ID " << mediun_id << " nicht gefunden!" << endl;
                    return;
                }
                list_of_buecher[index_temp].SetVerfuegbar(true);
                list_of_buecher[index_temp].ResetAusleihdatum();
                list_of_buecher[index_temp].ResetRueckgabedatum();

                break;

            case 2:
                index_temp = GetZeitschriftIndexMitId(mediun_id);
                if (index_temp == -1) {
                    cout << "Zeitschrift mit ID " << mediun_id << " nicht gefunden!" << endl;
                    return;
                }
                list_of_zeitschriften[index_temp].SetVerfuegbar(true);
                list_of_zeitschriften[index_temp].ResetAusleihdatum();
                list_of_zeitschriften[index_temp].ResetRueckgabedatum();

                break;

            case 3:
                index_temp = GetDVDIndexMitId(mediun_id);
                if (index_temp == -1) {
                    cout << "DVD mit ID " << mediun_id << " nicht gefunden!" << endl;
                    return;
                }
                list_of_dvds[index_temp].SetVerfuegbar(true);
                list_of_dvds[index_temp].ResetAusleihdatum();
                list_of_dvds[index_temp].ResetRueckgabedatum();

                break;

            default:
                cout << "Unbekannter Typ oder nicht gefunden!" << endl;
                return;
                break;
            }
            
            for (int i = index_temp; i < index_ausgeliehene_medien - 1; i++) {
                    list_of_ausgeliehene_medien[i][0] = list_of_ausgeliehene_medien[i + 1][0];
                    list_of_ausgeliehene_medien[i][1] = list_of_ausgeliehene_medien[i + 1][1];
                }
                index_ausgeliehene_medien--;
                list_of_benutzer[index_benutzer].Zurueckgeben(mediun_id);
            }

        void AnzeigenAusgelieheneMedien(int type) {
            // 0 = alle, 1 = buecher, 2 = zeitschriften, 3 = dvds
            cout << "+-------------------------------------------+" << endl;
            cout << "Ausgeliehene Medien: " << endl;
            if (type == 1 || type == 0) {
                cout << "------------+  Buecher  +------------" << endl;
                for (int i = 0; i < index_ausgeliehene_medien; i++) {
                    if (list_of_ausgeliehene_medien[i][1]/100 == 1) {
                        cout << "Benutzer ID: " << list_of_ausgeliehene_medien[i][0] << endl;
                        list_of_buecher[i].Anzeigen();
                        cout << "---------------------------------------------" << endl;
                    }
                }
            }

            if (type == 2 || type == 0) {
                cout << "------------+  Zeitschriften  +------------" << endl;
                for (int i = 0; i < index_ausgeliehene_medien; i++) {
                    if (list_of_ausgeliehene_medien[i][1]/100 == 2) {
                        cout << "Benutzer ID: " << list_of_ausgeliehene_medien[i][0] << endl;
                        list_of_zeitschriften[i].Anzeigen();
                        cout << "---------------------------------------------" << endl;
                    }
                }
            }

            if (type == 3 || type == 0) {
                cout << "------------+  DVDs  +------------" << endl;
                for (int i = 0; i < index_ausgeliehene_medien; i++) {
                    if (list_of_ausgeliehene_medien[i][1]/100 == 3) {
                        cout << "Benutzer ID: " << list_of_ausgeliehene_medien[i][0] << endl;
                        list_of_dvds[i].Anzeigen();
                        cout << "---------------------------------------------" << endl;
                    }
                }
            }
        cout << "+-------------------------------------------+" << endl;
        }
        
        void AnzeigenUeberfaelligeMedien(int type) {
            // 0 = alle, 1 = buecher, 2 = zeitschriften, 3 = dvds
            cout << "+-------------------------------------------+" << endl;
            cout << "Ueberfaellige Medien: " << endl;
            if (type == 1 || type == 0) {
                cout << "------------+  Buecher  +------------" << endl;
                for (int i = 0; i < index_ausgeliehene_medien; i++) {
                    if (list_of_ausgeliehene_medien[i][1]/100 == 1) {
                        if(list_of_buecher[i].IsUeberfaellig()) {
                            cout << "Benutzer ID: " << list_of_ausgeliehene_medien[i][0] << endl;
                            list_of_buecher[i].Anzeigen();
                            cout << "---------------------------------------------" << endl;
                        }
                    }
                }
            }

            if (type == 2 || type == 0) {
                cout << "------------+  Zeitschriften  +------------" << endl;
                for (int i = 0; i < index_ausgeliehene_medien; i++) {
                    if (list_of_ausgeliehene_medien[i][1]/100 == 2) {
                        if (list_of_zeitschriften[i].IsUeberfaellig()) {
                            cout << "Benutzer ID: " << list_of_ausgeliehene_medien[i][0] << endl;
                            list_of_zeitschriften[i].Anzeigen();
                            cout << "---------------------------------------------" << endl;
                        }
                    }
                }
            }

            if (type == 3 || type == 0) {
                cout << "------------+  DVDs  +------------" << endl;
                for (int i = 0; i < index_ausgeliehene_medien; i++) {
                    if (list_of_ausgeliehene_medien[i][1]/100 == 3) {
                        if (list_of_dvds[i].IsUeberfaellig()) {
                            cout << "Benutzer ID: " << list_of_ausgeliehene_medien[i][0] << endl;
                            list_of_dvds[i].Anzeigen();
                            cout << "---------------------------------------------" << endl;
                        }
                    }
                }
            }
        cout << "+-------------------------------------------+" << endl;
        } 
        
        //////////////////////////////////////////////////////////////////////////////////
};