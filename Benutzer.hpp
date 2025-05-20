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

        ~Benutzer() {
            cout << "Benutzer destructor called  id:" << id << endl;
        }

        void Ausleihen(unsigned int medium_id) {
            if (index >= MAX_ANZAHL) {
                cout << "--> Maximale Anzahl an ausgeliehenen Medien erreicht!!!" << endl;
            }
            else {
            liste_ausgeliehener_bücher[index] = medium_id;
            index++;
            }
        }
        
        unsigned int Zurückgeben (unsigned int medium_id) {
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

            if (!found) {
                cout << "Medium mit ID " << medium_id << " nicht gefunden!" << endl;
                return 0;
            }
            else {
                cout << "Medium mit ID " << medium_id << " erfolgreich zurückgegeben!" << endl;
                return medium_id;
            }
        }
        
        unsigned int Anzeigen() const {
            cout << "Benutzer ID: " << id << endl;
            cout << "Benutzer Name: " << name << endl;
            cout << "Ausgeliehene Bücher: ";
            for (int i = 0; i < index; i++) {
                return liste_ausgeliehener_bücher[i];
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
        
};