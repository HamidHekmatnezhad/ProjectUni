#include "Medium.hpp"
using namespace std;

class Zeitschrift: public Medium {
    private:
        unsigned int ausgaabe_nummer=0;

    public:
        Zeitschrift() {}
        Zeitschrift(string ttl, unsigned int idd, bool vrfgbr, unsigned int asgb_nm) : Medium(ttl, idd, vrfgbr) {
            ausgaabe_nummer = asgb_nm;
        }

        ~Zeitschrift() {}

        void Anzeigen() override final {
            cout << "Titel: " << GetTitel() << endl;
            cout << "ID: " << GetId() << endl;
            cout << "Verfuegbar: " << (GetVerfuegbar() ? "Ja" : "Nein") << endl;
            cout << "Ausgaabe Nummer: " << ausgaabe_nummer << endl;

            ShowAusleihdatum();
            ShowRueckgabedatum();
        }

        short Type() override final {
            return 2; // Nummer fuer Zeitschrift type
        }

        unsigned int GetAusgaabeNummer() {
            return ausgaabe_nummer;
        }

        void SetAusgaabeNummer(unsigned int asgb_nm) {
            ausgaabe_nummer = asgb_nm;
        }

};