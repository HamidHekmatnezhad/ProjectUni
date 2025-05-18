#include<string>
using namespace std;

struct datum {
    unsigned int tag=0;
    unsigned int monat=0;
    unsigned int jahr=0;
};

class Medium {
    private:
        string titel="";
        unsigned int id=0;
        bool verfuegbar=false;
        datum ausleihdatum;
        datum rueckgabedatum;

        public:
        Medium() {}
        Medium(string titel, unsigned int id, bool verfuegbar) { //TODO: ino niyaz nadaraim ye jorayi, chon mostaghim in init nemishe 
            this->titel = titel;
            this->id = id;
            this->verfuegbar = verfuegbar;
        }

        ~Medium() {
            cout << "Medium destructor called  id:" << id << endl;
        }

        virtual void Anzeigen() {}

        virtual short Type() {} // fuer Buch:1 , Zeitschrift:2 , DVD:3

        friend ostream& operator<<(ostream& os, const Medium& m);

        bool operator==(Medium m) {
            if (this->id == m.id) {
                return true;
            }
            return false;
        }

        string GetTitel() {
            return titel;
        }

        unsigned int GetId() {
            return id;
        }

        bool GetVerfuegbar() {
            return verfuegbar;
        }

        datum GetAusleihdatum() {
            return ausleihdatum;
        }

        datum GetRueckgabedatum() {
            return rueckgabedatum;
        }

        void SetTitel(string titel) {
            this->titel = titel;
        }

        void SetId(unsigned int id) {
            this->id = id;
        }

        void SetVerfuegbar(bool verfuegbar) {
            this->verfuegbar = verfuegbar;
        }

        void SetAusleihdatum(int tag, int monat, int jahr) {
            this->ausleihdatum.tag = tag;
            this->ausleihdatum.monat = monat;
            this->ausleihdatum.jahr = jahr;
        }

        void SetRueckgabedatum(int tag, int monat, int jahr) {
            this->rueckgabedatum.tag = tag;
            this->rueckgabedatum.monat = monat;
            this->rueckgabedatum.jahr = jahr;
        }

};