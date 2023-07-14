#include <iostream>
#include <list>
using namespace std;

void esborrar_elem(list<int>& l, int n, bool& borrat) {
    list<int>::iterator it = l.begin();
    borrat = false;

    while (it != l.end() and not borrat) {
        if ((*it)== n) {
            it = l.erase(it);
            borrat = true;
        }
        else ++it;
    }
}

void escriure(list<int>& l, int& max, int& min, double& suma) {
    min=0;
    max=0;
    suma=0;

    list<int>::iterator it;

    for (it = l.begin(); it != l.end(); ++it) {
        if (it == l.begin() or (*it) < min) {
            min = (*it);
        }
        if (it == l.begin() or (*it) > max) {
            max = (*it);
        }
        suma = suma + (*it);
    }

    if (l.empty()) cout << "0" << endl;
    else cout << min << " " << max << " " << suma / double(l.size()) << endl;
}

int main() {
    list<int> l;
    int codi, n;
    cin >> codi >> n;
    int max=n,min=n;
    double suma=0;
    bool borrat;
    while (codi !=0) {
        if (codi == -1) {
            l.insert(l.end(), n);
            if (n > max) max = n;
            if (n < min) min = n;
            suma = suma + n;
            if (l.empty()) cout << "0" << endl;
            else cout << min << " " << max << " " << suma / double(l.size()) << endl;
        }
        else {
            esborrar_elem(l,n,borrat);
            if (min == n or max == n) {
                escriure(l,max,min,suma);
            }
            else {
                if (l.empty()) cout << "0" << endl;
                else if (borrat){
                    suma = suma - n;
                    cout << min << " " << max << " " << suma / double(l.size()) << endl;
                } 
                else cout << min << " " << max << " " << suma / double(l.size()) << endl;
            }
        }
        cin >> codi >> n;
    }
}
