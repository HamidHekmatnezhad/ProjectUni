#include <Medium.hpp>
using namespace std;

class Zeitschrift: public Medium {
    private:
        unsigned int ausgaabe_nummer=0;

    public:
        Zeitschrift() {}
        Zeitschrift(string titel, unsigned int id, bool verfuegbar, unsigned int ausgaabe_nummer) : Medium(titel, id, verfuegbar) {
            this->ausgaabe_nummer = ausgaabe_nummer;
        }

        ~Zeitschrift() {
            cout << "Zeitschrift destructor called  id:" << GetId() << endl;
        }

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

        void SetAusgaabeNummer(unsigned int ausgaabe_nummer) {
            this->ausgaabe_nummer = ausgaabe_nummer;
        }

};