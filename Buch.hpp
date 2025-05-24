#include "Medium.hpp"
using namespace std;

class Buch: public Medium {
    private:
        string autor="";
        unsigned int ISBN=0;

    public:
        Buch() {}
        Buch(string ttl, unsigned int idd, bool vrfgbr, string atr, unsigned int IN) : Medium(ttl, idd, vrfgbr) {
            autor = atr;
            ISBN = IN;
        }

        ~Buch() {}

        void Anzeigen() override final {
            cout << "Titel: " << GetTitel() << endl;
            cout << "ID: " << GetId() << endl;
            cout << "Verfuegbar: " << (GetVerfuegbar() ? "Ja" : "Nein") << endl;
            cout << "Autor: " << autor << endl;
            cout << "ISBN: " << ISBN << endl;
            
            ShowAusleihdatum();
            ShowRueckgabedatum();
        }

        short Type() override final {
            return 1; // Nummer fuer Buch type
        }

        string GetAutor() {
            return autor;
        }

        unsigned int GetISBN() {
            return ISBN;
        }

        void SetAutor(string atr) {
            autor = atr;
        }
        
        void SetISBN(unsigned int IN) {
            ISBN = IN;
        }
};