#include <string>
#include <iostream>
using namespace std;

#define MAX_ANZAHL 10
class Benutzer {
    private:
        string name="";
        unsigned int id=0;
        unsigned int liste_ausgeliehener_bücher[MAX_ANZAHL];
        int index=0;

    public:
        Benutzer() {}
        Benutzer(string name, unsigned int id) {
            this->name = name;
            this->id = id;
        }

        ~Benutzer() {}

        void Ausleihen(unsigned int medium_id) {
            liste_ausgeliehener_bücher[index] = medium_id;
            index++;
        }
        
        void Zurueckgeben (unsigned int medium_id) {
            bool found = false;
            for (int i = 0; i < index; i++) {
                if (liste_ausgeliehener_bücher[i] == medium_id) {
                    found = true;
                    for (int j = i; j < index - 1; j++) {
                        liste_ausgeliehener_bücher[j] = liste_ausgeliehener_bücher[j + 1];
                    }
                    index--;
                    break;
                }
            }
        }
        
        void Anzeigen() const {
            cout << "Benutzer ID: " << id << endl;
            cout << "Benutzer Name: " << name << endl;
            cout << "Ausgeliehene Bücher: \n";
            for (int i = 0; i < index; i++) {
                cout << liste_ausgeliehener_bücher[i] << endl;
            }
        }

        string GetName() {
            return name;
        }

        unsigned int GetId() {
            return id;
        }

        unsigned int* GetListeAusgeliehenerBuecher() {
            return liste_ausgeliehener_bücher;
        }

        int GetIndex() {
            return index;
        }

        void SetName(string name) {
            this->name = name;
        }

        void SetId(unsigned int id) {
            this->id = id;
        }
        
        int GetMaxAusleihungen() {
            return MAX_ANZAHL;
        }
};