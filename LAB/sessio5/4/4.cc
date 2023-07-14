#include <iostream>
// #include "listIOint.hh"
#include <list>
using namespace std;

/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
void inter(list<int>& uno, const list<int>& dos) {
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();

    while ((it1 != uno.end()) and (it2 != dos.end())) {
        if ((*it1)==(*it2)) {
            ++it1;
            ++it2;
        }
        else if ((*it1) < (*it2)) it1 = uno.erase(it1);
            
        else ++it2;
    }

    if (it2 == dos.end()) {
        while (it1 != uno.end()) it1 = uno.erase(it1);
    }
}
/*
int main() {
    list<int> uno;
    list<int> dos;
    llegir_llista_int(uno, 0);
    llegir_llista_int(dos, 0);
    inter(uno,dos);
    escriure_llista_int(uno);


}
*/
