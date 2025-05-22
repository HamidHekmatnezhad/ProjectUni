#include <Bibliothek.hpp>
using namespace std;



ostream& operator<<(ostream& os, Medium& m) {
    m.Anzeigen();
    return os;
}

// id zaehler for medium    
// id zaehler for benutzer

int main(){
    Bibliothek b;
    int eingabe;
    unsigned int id, idx, ISBN;
    string name, titel, autor;
    unsigned int jahr, monat, tag, ausleihdauer;

    while(1){
        cout << "1. Benutzer" << endl;
        cout << "2. Medien" << endl;
        cout << "3. Ausleihen" << endl;
        cout << "4. Zurueckgeben" << endl;
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
                        cin >> name;
                        b.BenutzerHinzufuegen(name);
                        break;

                    case 2: // Benutzer loeschen
                        cout << "geben Sie die ID des Benutzers ein (wenn Sie nicht ID haben, koennen Sie einfach in Benutzer anzeigen finden): ";
                        cin >> id;
                        b.BenutzerLoeschen(id);
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
                                b.AnzeigenFuerEinBenutzer(id);
                                break;

                            case 2: // mit Name 
                                cout << "geben Sie den Namen des Benutzers ein: ";
                                cin >> name;
                                idx = b.SearchBenutzerMitName(name);
                                if (idx == -1) {
                                    cout << "Benutzer nicht gefunden!" << endl;
                                    break;
                                }
                                cout << "Benutzer gefunden: " << endl;
                                b.AnzeigenFuerEinBenutzer(idx);
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
            case 2: // Medien #
                break;
            case 3: // Ausleihen #
                break;
            case 4: // Zurueckgeben #
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
        cin.get();
        system("clear");
        system("cls");



    }
    
}