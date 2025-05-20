#include <Buch.hpp>
#include <Zeitschrift.hpp>
#include <DVD.hpp>

using namespace std;


ostream& operator<<(ostream& os, Medium& m) {
    m.Anzeigen();
    return os;
}

// id zaehler for medium    
// id zaehler for benutzer

int main(){
    
}