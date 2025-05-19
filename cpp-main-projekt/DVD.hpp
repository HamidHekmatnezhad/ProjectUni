#include <Medium.hpp>
#include <iostream>
using namespace std;

struct zeitdauer {
    unsigned int stunde=0;
    unsigned int minute=0;
    unsigned int sekunde=0;
};

class DVD: public Medium {
    private:
        zeitdauer Abspieldauer;

    public:
        DVD() {}
        DVD(string titel, unsigned int id, bool verfuegbar) : Medium(titel, id, verfuegbar) {
            this->Abspieldauer = Abspieldauer;
        }

        ~DVD() {
            cout << "DVD destructor called  id:" << GetId() << endl;
        }
        
        void Anzeigen() override final {
            cout << "Titel: " << GetTitel() << endl;
            cout << "ID: " << GetId() << endl;
            cout << "Verfuegbar: " << (GetVerfuegbar() ? "Ja" : "Nein") << endl;
            cout << "Abspieldauer:  " << Abspieldauer.stunde << ":" << Abspieldauer.minute << ":" << Abspieldauer.sekunde << endl;

            ShowAusleihdatum();
            ShowRueckgabedatum();
        }

        short Type() override final {
            return 3; // Nummer fuer DVD type
        }

        zeitdauer GetAbspieldauer() {
            return Abspieldauer;
        }

        void SetAbspieldauer(unsigned int stunde, unsigned int minute, unsigned int sekunde) {
            this->Abspieldauer.stunde = stunde;
            this->Abspieldauer.minute = minute;
            this->Abspieldauer.sekunde = sekunde;
        }

};