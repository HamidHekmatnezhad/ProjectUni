#include <string>
#include <ctime>
#include <iostream>
using namespace std;

#pragma once

class Medium {
    private:
        string titel="";
        unsigned int id=0;
        bool verfuegbar=false;

        bool first_ausleihdatum = false;
        time_t ausleihdatum;
        bool first_rueckgabedatum = false;
        time_t rueckgabedatum;

        public:
        Medium() {}
        Medium(string titel, unsigned int id, bool verfuegbar) {  
            this->titel = titel;
            this->id = id;
            this->verfuegbar = verfuegbar;
        }

        ~Medium() {}

        virtual void Anzeigen() {}

        virtual short Type() = 0; // fuer Buch:1 , Zeitschrift:2 , DVD:3

        friend ostream& operator<<(ostream& os, const Medium& m);

        bool operator==(const Medium& m) const {
            return this->id == m.id;
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
            if (!first_ausleihdatum) {return 0; }
            else {return ausleihdatum; }
        }

        void ShowAusleihdatum() {
            if (first_ausleihdatum) {
                tm *tm = localtime(&ausleihdatum);
                cout << "Ausleihdatum: " << tm->tm_mday << "." << tm->tm_mon + 1 << "." << tm->tm_year + 1900;
                cout << "   " << tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << endl;
            }
        }
        
        time_t GetRueckgabedatum() { 
            if (!first_rueckgabedatum) {return 0; }
            else {return rueckgabedatum; }
        }

        void ShowRueckgabedatum() {
            if (first_rueckgabedatum) {
                tm *tm = localtime(&rueckgabedatum);
                cout << "Rueckgabedatum: " << tm->tm_mday << "." << tm->tm_mon + 1 << "." << tm->tm_year + 1900;
                cout << "   " << tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << endl;
            }
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
            first_ausleihdatum = true;
        }

        void SetAusleihdatum(int jahr, int monat, int tag, int stunde=0, int minute=0, int sekunde=0) {
            tm datetime_a;

            datetime_a.tm_year = jahr - 1900; 
            datetime_a.tm_mon = monat - 1;
            datetime_a.tm_mday = tag;
            datetime_a.tm_hour = stunde;
            datetime_a.tm_min = minute;
            datetime_a.tm_sec = sekunde;

            ausleihdatum = mktime(&datetime_a);
        }
        
        void SetRueckgabedatum(unsigned int tage) {
            tm *datetime_r = localtime(&ausleihdatum);
            datetime_r->tm_mday += tage;

            rueckgabedatum = mktime(datetime_r);
            first_rueckgabedatum = true;
        }

        void ResetAusleihdatum() {
            first_ausleihdatum = false;
        }
        
        void ResetRueckgabedatum() {
            first_rueckgabedatum = false;
        }

        bool IsUeberfaellig() {
            if (first_rueckgabedatum) {
                time_t now = time(NULL);
                if (now > rueckgabedatum) {
                    return true;
                }
            }
            return false;
        }

    };