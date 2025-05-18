#include <Buch.hpp>
#include <Zeitschrift.hpp>
#include <DVD.hpp>

using namespace std;


ostream& operator<<(ostream& os, const Medium& m) {
    m->Anzeigen();
    return os;
}

int main(){
    
}