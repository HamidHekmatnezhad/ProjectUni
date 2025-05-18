#include <string>
#include <iostream>

using namespace std;

class Benutzer {
    private:
        string name="";
        unsigned int id=0;
        unsigned int liste_ausgeliehener_bücher[10];
        int index=0;

    public:
        Benutzer() {}
        Benutzer(string name, unsigned int id) {
            this->name = name;
            this->id = id;
        }

        ~Benutzer() {
            cout << "Benutzer destructor called  id:" << id << endl;
        }

        // Void ausleihen(Buch, Zeitschrift oder DVD));
        // Void Zurückgeben (Inventar-ID);
        // void anzeigen() const; // Liste der ausgeliehen Bücher

        string GetName() {
            return name;
        }

        unsigned int GetId() {
            return id;
        }

        unsigned int* GetListeAusgeliehenerBuecher() {
            return liste_ausgeliehener_bücher;
        }

        void SetName(string name) {
            this->name = name;
        }

        void SetId(unsigned int id) {
            this->id = id;
        }
        
};