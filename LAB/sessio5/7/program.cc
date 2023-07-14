#include "BinTreeIOEst.hh"
using namespace std;

int cerca(const BinTree<Estudiant>& a, int n, int& s) {
    if (not a.empty()) {
        Estudiant est = a.value();
        if (est.consultar_DNI() == n) {
            if (est.te_nota()) s = est.consultar_nota();
            else s = -1;
            return 0;
        }
        int left = cerca(a.left(), n, s);
        int n_aux;
        int right = cerca(a.right(), n, n_aux); //per quan x==x'

        if (left != -1 and right != -1) { // si no estan buits
            if (left <= right) return 1 + left; // comparacions de profunditat si x==x'
            else {
                s = n_aux;
                return 1 + right;
            }
        }
        if (left != -1) return 1 + left; // si x==x' mirem el de mes a l'esquerra
        else if (right != -1) {
            s = n_aux;
            return 1 + right;
        }
        else return -1;

    }
    return -1;
}

int main() {
    BinTree<Estudiant> a;
    read_bintree_est(a);

    int n, s;
    while (cin >> n) {
        int p = cerca(a, n, s);
        if (p != -1) {
            cout << n << ' ' << p << ' '  << s << endl;
        } else cout << n << ' ' << -1 << endl;
    }
}