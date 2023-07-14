#include "LlistaIOParInt.hh"
using namespace std;


int main() {
    list<ParInt> l;
    LlegirLlistaParInt(l);
    int n;
    cin >> n;
    
    int suma=0;
    int n_n=0;
    
    list<ParInt>::const_iterator it;
    for (it = l.begin(); it != l.end(); ++it) {
        if ((*it).primer() == n) {
            suma = suma + (*it).segon();
            ++n_n;
        }
    }
    
    cout << n << " " << n_n << " " << suma << endl;
}