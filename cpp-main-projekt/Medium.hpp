#include<string>
#include <ctime>
using namespace std;

class Medium {
    private:
        string titel="";
        unsigned int id=0;
        bool verfuegbar=false;
        time_t ausleihdatum;
        time_t rueckgabedatum;

        public:
        Medium() {}
        Medium(string titel, unsigned int id, bool verfuegbar) {  
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

        time_t GetAusleihdatum() { 
            return ausleihdatum;
        }

        time_t GetRueckgabedatum() { 
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

        void SetAusleihdatum() { 
            ausleihdatum = time(NULL);
        }

        void SetRueckgabedatum() {
            rueckgabedatum = time(NULL);
        }

};