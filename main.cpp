#include "Bibliothek.hpp"
using namespace std;


int main(){
    Bibliothek b;
    int eingabe=1;
    unsigned int id, idx, ISBN, ausgabenummer, id_medium;
    string name, titel, autor;
    unsigned int jahr, monat, tag, ausleihdauer;
    unsigned int stunde, minute, sekunde;

    while(true){
        cout << "1. Benutzer" << endl;
        cout << "2. Medien" << endl;
        cout << "3. Ausleihen" << endl;
        cout << "4. Zurueckgeben" << endl;
        cout << "5. Ausgeliehene Medien anzeigen" << endl;
        cout << "6. ausgeliehene ueberfaellige Medien" << endl;
        cout << "0. Beenden" << endl;
        
        cout << "Bitte waehlen Sie eine Option: ";
        cin >> eingabe;
        cout << endl;


        switch(eingabe){
            case 1:
                cout << "1. neue Benutzer hinzufuegen." << endl;
                cout << "2. Benutzer loeschen." << endl;
                cout << "3. ein Benutzer anzeigen." << endl;
                cout << "4. alle Benutzer anzeigen." << endl;
                cout << "0. zurueck." << endl;

                cout << "Bitte waehlen Sie eine Option: ";
                cin >> eingabe;
                cout << endl;

                switch(eingabe){
                    case 1: // neuer Benutzer
                        cout << "geben Sie den Namen ein: ";
                        cin.ignore();
                        getline(cin, name);
                        b.BenutzerHinzufuegen(name);
                        cout << endl;
                        break;

                    case 2: // Benutzer loeschen
                        cout << "geben Sie die ID des Benutzers ein (wenn Sie nicht ID haben, koennen Sie einfach in Benutzer anzeigen finden): ";
                        cin >> id;
                        if (b.UngueltigInputUnsignedInt(id)) {break;}
                        b.BenutzerLoeschen(id);
                        cout << endl;
                        break;

                    case 3: // Benutzer anzeigen 
                        cout << "1. mit ID" << endl;
                        cout << "2. mit Name" << endl;
                        cout << "Bitte waehlen Sie eine Option: ";
                        cin >> eingabe;
                        cout << endl;

                        switch(eingabe){
                            case 1: // mit ID 
                                cout << "geben Sie die ID des Benutzers ein(wenn Sie nicht ID haben, koennen Sie einfach in Benutzer anzeigen finden): ";
                                cin >> id;
                                if (b.UngueltigInputUnsignedInt(id)) {break;}
                                b.AnzeigenFuerEinBenutzer(id);
                                cout << endl;
                                break;

                            case 2: // mit Name 
                                cout << "geben Sie den Namen des Benutzers ein: ";
                                cin.ignore();
                                getline(cin, name);
                                name = b.ToLowerCase(name);
                                idx = b.SearchBenutzerMitName(name);
                                cout << endl;
                                if (idx == -1) {
                                    cout << "Benutzer nicht gefunden!" << endl;
                                    break;
                                }
                                cout << "Benutzer gefunden: " << endl;
                                b.AnzeigenFuerEinBenutzer(idx);
                                cout << endl;
                                break;

                            default:
                                cout << "Ungueltige Eingabe!" << endl;
                        }

                        break;
                    case 4: // alle Benutzer anzeigen 
                        cout << "alle Benutzer anzeigen: " << endl;
                        b.AnzeigenFuerAlleBenutzer();
                        break;

                    case 0:
                        cout << "Zurueck..." << endl;
                        break;
                    default:
                        cout << "Ungueltige Eingabe!" << endl;
                }

                break;
            case 2: // Medien 
                cout << "1. Buch" << endl;
                cout << "2. Zeitschrift" << endl;
                cout << "3. DVD" << endl;
                cout << "4. alle Medien anzeigen" << endl;
                cout << "0. zurueck" << endl;

                cout << "Bitte waehlen Sie eine Option: ";
                cin >> eingabe;
                cout << endl;

                switch(eingabe){
                    case 1: // Buch 
                        cout << "1. neues Buch hinzufuegen." << endl;
                        cout << "2. Buch loeschen." << endl;
                        cout << "3. Buch suchen." << endl;
                        cout << "4. alle Buecher anzeigen." << endl;
                        cout << "0. zurueck." << endl;

                        cout << "Bitte waehlen Sie eine Option: ";
                        cin >> eingabe;
                        cout << endl;

                        switch(eingabe){
                            case 1: // Buch hinzufuegen 
                                cout << "\ngeben Sie den Titel des Buches ein: ";
                                cin.ignore();
                                getline(cin, titel);
                                cout << "\ngeben Sie den Autor des Buches ein: ";
                                cin.ignore();
                                getline(cin, autor);
                                cout << "\ngeben Sie die ISBN des Buches ein: ";
                                cin >> ISBN;
                                b.HinzufuegenBuch(titel, autor, ISBN, true);
                                cout << endl;
                                break;

                            case 2: // Buch loeschen 
                                cout << "geben Sie das Buch ID ein (wenn Sie nicht ID haben, koennen Sie einfach in Buch anzeigen finden): ";
                                cin >> id;
                                if (b.UngueltigInputUnsignedInt(id)) {break;}
                                b.LoeschenBuch(id);
                                cout << endl;
                                break;

                            case 3: // Buch suchen 
                                cout << "1. mit Titel" << endl;
                                cout << "2. mit ISBN" << endl;
                                cout << "3. mit Autor" << endl;
                                cout << "4. mit ID" << endl;
                                cout << "0. zurueck" << endl;
                                
                                cout << "Bitte waehlen Sie eine Option: ";
                                cin >> eingabe;
                                cout << endl;
                                break;

                                switch(eingabe){
                                    case 1: // mit Titel 
                                        cout << "geben Sie den Titel des Buches ein: ";
                                        cin.ignore();
                                        getline(cin, titel);
                                        titel = b.ToLowerCase(titel);
                                        if (b.UngueltigEingaben(titel)) {break;}
                                        b.SearchBuchTitleAnzeigen(titel);
                                        cout << endl;
                                        break;

                                    case 2: // mit ISBN 
                                        cout << "geben Sie die ISBN des Buches ein: ";
                                        cin >> ISBN;
                                        if (b.UngueltigInputUnsignedInt(ISBN)) {break;}
                                        b.SearchBuchISBNAnzeigen(ISBN);
                                        cout << endl;
                                        break;

                                    case 3: // mit Autor 
                                        cout << "geben Sie den Autor des Buches ein: ";
                                        cin.ignore();
                                        getline(cin, autor);
                                        autor = b.ToLowerCase(autor);
                                        if (b.UngueltigEingaben(autor)) {break;}
                                        b.SearchBuchAutherAnzeigen(autor);
                                        cout << endl;
                                        break;

                                    case 4: // mit ID
                                        cout << "geben Sie die ID des Buches ein(wenn Sie nicht ID haben, koennen Sie einfach in Buch anzeigen finden): ";
                                        cin >> id;
                                        if (b.UngueltigInputUnsignedInt(id)) {break;}
                                        b.AnzeigenMedienMitId(id);
                                        cout << endl;
                                        break;

                                    case 0: // zurueck 
                                        cout << "Zurueck..." << endl;
                                        break;

                                    default:
                                        cout << "Ungueltige Eingabe!" << endl;
                                        break;
                                }

                                
                            case 4: // alle Buecher anzeigen 
                                cout << "alle Buecher anzeigen: " << endl;
                                b.AnzeigenAllMedien(1);
                                break;

                            case 0: // zurueck
                                cout << "Zurueck..." << endl;
                                break;
                            default:
                                cout << "Ungueltige Eingabe!" << endl;
                                break;
                        }
                    break;
                    
                    case 2: // Zeitschrift 
                    cout << "1. neues Zeitschrift hinzufuegen." << endl;
                    cout << "2. Zeitschrift loeschen." << endl;
                    cout << "3. Zeitschrift suchen." << endl;
                    cout << "4. alle Zeitschriften anzeigen." << endl;
                    cout << "0. zurueck." << endl;

                    cout << "Bitte waehlen Sie eine Option: ";
                    cin >> eingabe;
                    cout << endl;

                    switch(eingabe){
                        case 1: // Zeitschrift hinzufuegen 
                            cout << "\ngeben Sie den Titel der Zeitschrift ein: ";
                            cin.ignore();
                            getline(cin, titel);
                            titel = b.ToLowerCase(titel);
                            if (b.UngueltigEingaben(titel)) {break;}
                            cout << "\ngeben Sie die Ausgabenummer der Zeitschrift ein: ";
                            cin >> ausgabenummer;
                            if (b.UngueltigInputUnsignedInt(ausgabenummer)) {break;}

                            b.HinzufuegenZeitschrift(titel, ausgabenummer, true);
                            cout << endl;
                            break;

                        case 2: // Zeitschrift loeschen 
                            cout << "geben Sie die ID der Zeitschrift ein (wenn Sie nicht ID haben, koennen Sie einfach in Zeitschrift anzeigen finden): ";
                            cin >> id;
                            if (b.UngueltigInputUnsignedInt(id)) {break;}
                            b.LoeschenZeitschrift(id);
                            cout << endl;
                            break;

                        case 3: // Zeitschrift suchen 
                            cout << "1. mit Titel" << endl;
                            cout << "2. mit Ausgabenummer" << endl;
                            cout << "3. mit ID" << endl;
                            cout << "0. zurueck" << endl;

                            cout << "Bitte waehlen Sie eine Option: ";
                            cin >> eingabe;
                            cout << endl;

                            switch(eingabe){
                                case 1: // mit title 
                                    cout << "geben Sie den Titel der Zeitschrift ein: ";
                                    cin.ignore();
                                    getline(cin, titel);
                                    titel = b.ToLowerCase(titel);
                                    if (b.UngueltigEingaben(titel)) {break;}
                                    b.SearchZeitschriftTitleAnzeigen(titel);
                                    cout << endl;
                                    break;

                                case 2: // mit Ausgabenummer 
                                    cout << "geben Sie die Ausgabenummer der Zeitschrift ein: ";
                                    cin >> ausgabenummer;
                                    if (b.UngueltigInputUnsignedInt(ausgabenummer)) {break;}
                                    b.SearchZeitschriftAusgaabeNummerAnzeigen(ausgabenummer);
                                    cout << endl;
                                    break;

                                case 3: // mit ID 
                                    cout << "geben Sie die ID der Zeitschrift ein(wenn Sie nicht ID haben, koennen Sie einfach in Zeitschrift anzeigen finden): ";
                                    cin >> id;
                                    if (b.UngueltigInputUnsignedInt(id)) {break;}
                                    b.AnzeigenMedienMitId(id);
                                    cout << endl;
                                    break;

                                case 0: // zurueck
                                    cout << "Zurueck..." << endl;
                                    break;
                                default:
                                    cout << "Ungueltige Eingabe!" << endl;
                                    break;
                            }
                            break;

                        case 4: // alle Zeitschriften anzeigen
                            cout << "alle Zeitschriften anzeigen: " << endl;
                            b.AnzeigenAllMedien(2);
                            break;
                            
                        case 0: // zurueck
                            cout << "Zurueck..." << endl;
                            break;
                        default:
                            cout << "Ungueltige Eingabe!" << endl;
                            break;
                    }
                    break;

                    case 3: // DVD 
                        cout << "1. neue DVD hinzufuegen." << endl;
                        cout << "2. DVD loeschen." << endl;
                        cout << "3. DVD suchen." << endl;
                        cout << "4. alle DVDs anzeigen." << endl;
                        cout << "0. zurueck." << endl;

                        cout << "Bitte waehlen Sie eine Option: ";
                        cin >> eingabe;
                        cout << endl;
                        
                        switch(eingabe){
                            case 1: // DVD hinzufuegen 
                                cout << "\ngeben Sie den Titel des DVD ein: ";
                                cin.ignore();
                                getline(cin, titel);
                                cout << "\nBitte geben Sie die Videolänge ein (jeweils getrennt nach Stunde, Minute und Sekunde)";
                                cout << "\nStunde: ";
                                cin >> stunde;
                                cout << "\nMinute: ";
                                cin >> minute;
                                cout << "\nSekunde: ";
                                cin >> sekunde;
                                if (stunde < 0 || minute < 0 || sekunde < 0) {
                                    cout << "Ungueltige Eingabe!\t nicht negativ" << endl;
                                    break;
                                }
                                if (minute > 59 || sekunde > 59) {
                                    cout << "Ungueltige Eingabe!\t nicht groesser als 59 fuer Minute und Sekunde" << endl;
                                    break;
                                }
                                b.HinzufuegenDVD(titel, stunde, minute, sekunde, true);
                                cout << endl;
                                break;
                                
                            case 2: // DVD loeschen 
                                cout << "geben Sie die ID der DVD ein (wenn Sie nicht ID haben, koennen Sie einfach in DVD anzeigen finden): ";
                                cin >> id;
                                if (b.UngueltigInputUnsignedInt(id)) {break;}
                                b.LoeschenDVD(id);
                                cout << endl;
                                break;

                            case 3: // DVD suchen  #
                                cout << "1. mit Titel" << endl;
                                cout << "2. mit ID" << endl;
                                cout << "0. zurueck" << endl;

                                cout << "Bitte waehlen Sie eine Option: ";
                                cin >> eingabe;
                                cout << endl;

                                switch(eingabe){
                                    case 1: // mit title 
                                        cout << "geben Sie den Titel der DVD ein: ";
                                        cin.ignore();
                                        getline(cin, titel);
                                        titel = b.ToLowerCase(titel);
                                        if (b.UngueltigEingaben(titel)) {break;}
                                        b.SearchDVDTitleAnzeigen(titel);
                                        cout << endl;
                                        break;
                                        
                                    case 2: // mit ID 
                                        cout << "geben Sie die ID der DVD ein(wenn Sie nicht ID haben, koennen Sie einfach in DVD anzeigen finden): ";
                                        cin >> id;
                                        if (b.UngueltigInputUnsignedInt(id)) {break;}
                                        b.AnzeigenMedienMitId(id);
                                        cout << endl;
                                        break;
                                    
                                    case 0: // zurueck
                                        cout << "Zurueck..." << endl;
                                        break;
                                    default:
                                        cout << "Ungueltige Eingabe!" << endl;
                                        break;
                                }
                                break;
                                
                            case 4: // alle DVDs anzeigen  
                                cout << "alle DVDs anzeigen: " << endl;
                                b.AnzeigenAllMedien(3);
                                cout << endl;
                                break;
     
                            case 0: // zurueck
                                cout << "Zurueck..." << endl;
                                break;
                            
                            default:
                                cout << "Ungueltige Eingabe!" << endl;
                                break;
                        
                        }
                    break;
                    case 4: // alle Medien anzeigen 
                        cout << "1. alle Buecher anzeigen" << endl;
                        cout << "2. alle Zeitschriften anzeigen" << endl;
                        cout << "3. alle DVDs anzeigen" << endl;
                        cout << "4. alle Medien anzeigen" << endl;
                        cout << "0. zurueck" << endl;

                        cout << "Bitte waehlen Sie eine Option: ";
                        cin >> eingabe;
                        cout << endl;

                        switch(eingabe){
                            case 1: // buch 
                                cout << "alle Buecher anzeigen: " << endl;
                                b.AnzeigenAllMedien(1);
                                cout << endl;
                                break;

                            case 2: // zeitschrift 
                                cout << "alle Zeitschriften anzeigen: " << endl;
                                b.AnzeigenAllMedien(2);
                                cout << endl;
                                break;

                            case 3: // dvd 
                                cout << "alle DVDs anzeigen: " << endl;
                                b.AnzeigenAllMedien(3);
                                cout << endl;
                                break;

                            case 4: // alle Medien 
                                cout << "alle Medien anzeigen: " << endl;
                                b.AnzeigenAllMedien(0);
                                cout << endl;
                                break;

                            case 0: // zurueck
                                cout << "Zurueck..." << endl;
                                break;
                            default:
                                cout << "Ungueltige Eingabe!" << endl;
                                break;
                            }
                        break;

                    case 0: // zurueck
                        cout << "Zurueck..." << endl;
                        break;
                    default:
                        cout << "Ungueltige Eingabe!" << endl;
                        break;
                }
                break;

            case 3: // Ausleihen 
                cout << "geben Sie die ID des Mediums ein(wenn Sie nicht ID haben, koennen Sie einfach in Medien anzeigen finden): ";
                cin >> id_medium;
                if (b.UngueltigInputUnsignedInt(id_medium)) {break;}

                cout << "geben Sie die Ausleihdauer in Tagen ein: ";
                cin >> ausleihdauer;
                if (b.UngueltigInputUnsignedInt(ausleihdauer)) {break;}

                if (ausleihdauer > b.GetAusleihdauer()) {
                    cout << "Ungueltige Eingabe!\t nicht groesser als " << b.GetAusleihdauer() << " Tage" << endl;
                    break;
                }

                cout << "geben Sie Benutzer ID ein(wenn Sie nicht ID haben, koennen Sie einfach in Benutzer anzeigen finden): ";
                cin >> id;
                if (b.UngueltigInputUnsignedInt(id)) {break;}

                cout << "1. Ausleihdatum jetzt" << endl;
                cout << "2. Ausleihdatum eingeben" << endl;
                cout << "0. zurueck" << endl;

                cout << "Bitte waehlen Sie eine Option: ";
                cin >> eingabe;
                cout << endl;

                switch(eingabe){
                    case 1: // jetzt 
                        b.Ausleihen(id, id_medium, ausleihdauer);
                        cout << endl;
                        break;
                        
                    case 2: // custom 
                        cout << "geben Sie Info ein:" << endl;
                        cout << "Jahr: ";
                        cin >> jahr;
                        cout << "\nMonat: ";
                        cin >> monat;
                        cout << "\nTag: ";
                        cin >> tag;

                        if (b.UngueltigInputUnsignedInt(jahr) || b.UngueltigInputUnsignedInt(monat) || b.UngueltigInputUnsignedInt(tag)) {break;}
                        if (monat < 1 || monat > 12) {
                            cout << "Ungueltige Eingabe!\t nicht groesser als 12" << endl;
                            break;
                        }
                        if (tag < 1 || tag > 31) {
                            cout << "Ungueltige Eingabe!\t nicht groesser als 31" << endl;
                            break;
                        }
                        if (monat == 2 && tag > 28) {
                            cout << "Ungueltige Eingabe!\t nicht groesser als 28" << endl;
                            break;
                        }
                        if ((monat == 4 || monat == 6 || monat == 9 || monat == 11) && tag > 30) {
                            cout << "Ungueltige Eingabe!\t nicht groesser als 30" << endl;
                            break;
                        }

                        b.Ausleihen(id, id_medium, ausleihdauer, tag, monat, jahr);
                        cout << endl;
                        break;


                    case 0: // zurueck
                        cout << "Zurueck..." << endl;
                        break;

                    default:
                        cout << "Ungueltige Eingabe!" << endl;
                        break;   
                }
            break;

            case 4: // Zurueckgeben 
                cout << "geben Sie die ID des Mediums ein(wenn Sie nicht ID haben, koennen Sie einfach in Medien anzeigen finden): ";
                cin >> id_medium;
                if (b.UngueltigInputUnsignedInt(id_medium)) {break;}
                cout << endl;

                cout << "geben Sie Benutzer ID ein(wenn Sie nicht ID haben, koennen Sie einfach in Benutzer anzeigen finden): ";
                cin >> id;
                if (b.UngueltigInputUnsignedInt(id)) {break;}
                cout << endl;

                b.Zurueckgeben(id, id_medium);
                break;

            case 5: // Ausgeliehene Medien anzeigen 
                cout << "1. Buch" << endl;
                cout << "2. Zeitschrift" << endl;
                cout << "3. DVD" << endl;
                cout << "4. alle Medien" << endl;
                cout << "0. zurueck" << endl;
                cout << "Bitte waehlen Sie eine Option: ";
                cin >> eingabe;
                cout << endl;

                switch(eingabe){
                    case 1: // Buch 
                    b.AnzeigenAllMedien(1);
                    cout << endl;
                    break;

                    case 2: // Zeitschrift 
                    b.AnzeigenAllMedien(2);
                    cout << endl;
                    break;

                    case 3: // DVD 
                    b.AnzeigenAllMedien(3);
                    cout << endl;
                    break;

                    case 4: // alle Medien 
                    b.AnzeigenAllMedien(0);
                    cout << endl;
                    break;

                    case 0: // zurueck
                        cout << "Zurueck..." << endl;
                        break;
                        
                    default:
                        cout << "Ungueltige Eingabe!" << endl;
                        break;   
                }
            break;

            case 6: // Ausgeliehene ueberfaellige Medien anzeigen 
                cout << "1. Buch" << endl;
                cout << "2. Zeitschrift" << endl;
                cout << "3. DVD" << endl;
                cout << "4. alle Medien" << endl;
                cout << "0. zurueck" << endl;
                cout << "Bitte waehlen Sie eine Option: ";
                cin >> eingabe;
                cout << endl;

                switch(eingabe){
                    case 1: // Buch 
                    b.AnzeigenUeberfaelligeMedien(1);
                    cout << endl;
                    break;

                    case 2: // Zeitschrift 
                    b.AnzeigenUeberfaelligeMedien(2);
                    cout << endl;
                    break;

                    case 3: // DVD 
                    b.AnzeigenUeberfaelligeMedien(3);
                    cout << endl;
                    break;

                    case 4: // alle Medien 
                    b.AnzeigenUeberfaelligeMedien(0);
                    cout << endl;
                    break;

                    case 0: // zurueck
                        cout << "Zurueck..." << endl;
                        break;

                    default:
                        cout << "Ungueltige Eingabe!" << endl;
                        break;   
                }
            break;

            case 0:
                cout << "Programm wird beendet..." << endl;
                return 0;

            default:
                cout << "Ungueltige Eingabe!" << endl;
        }
        cout << endl;
        cout << "Druecken Sie eine Taste um fortzufahren..." << endl;
        cin.ignore();
        // cin.get();
        // system("cls");
        // system("clear");
    }
}