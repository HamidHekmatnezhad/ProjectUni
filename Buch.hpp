#include <Medium.hpp>
using namespace std;

class Buch: public Medium {
    private:
        string autor="";
        unsigned int ISBN=0;

    public:
        Buch() {}
        Buch(string titel, unsigned int id, bool verfuegbar, string autor, unsigned int ISBN) : Medium(titel, id, verfuegbar) {
            this->autor = autor;
            this->ISBN = ISBN;
        }

        ~Buch() {
            cout << "Buch destructor called  id:" << GetId() << endl;
        }

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

        void SetAutor(string autor) {
            this->autor = autor;
        }
        
        void SetISBN(unsigned int ISBN) {
            this->ISBN = ISBN;
        }
};