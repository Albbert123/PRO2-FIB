#include "BinTreeIOParInt.hh"
using namespace std;

int cerca(const BinTree<ParInt>& a, int n, int& s) {
    if (not a.empty()) {
        if (a.value().primer() == n) {
            s = a.value().segon();
            return 0; //si fos el primer, la profunditat seria 0
        }
        int left = cerca(a.left(), n ,s);
        if (left != -1) return 1 + left; //si fos el segon, seria 1 + profunditat(que es 0). el tercer seria 2 + prof(que es 0)...
        int right = cerca(a.right(), n, s);
        if (right != -1) return 1 + right;
    }
    return -1;
}

int main() {
    BinTree<ParInt> a;
    read_bintree_parint(a);

    int n, s;
    while (cin >> n) {
        int prof = cerca(a, n, s);
        if (prof != -1) {
            cout << n << " " << s << " " << prof << endl;
        }
        else cout << "-1" << endl;
    }
}