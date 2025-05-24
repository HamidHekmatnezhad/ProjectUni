#include "Medium.hpp"
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
        DVD(string ttl, unsigned int idd, bool vrfgbr) : Medium(ttl, idd, vrfgbr) {}

        ~DVD() {}
        
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

        void SetAbspieldauer(unsigned int stnd, unsigned int mnt, unsigned int sknd) {
            Abspieldauer.stunde = stnd;
            Abspieldauer.minute = mnt;
            Abspieldauer.sekunde = sknd;
        }

};