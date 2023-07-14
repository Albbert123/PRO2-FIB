#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a) {
  ParInt p;
  if (p.llegir()){
	BinTree<ParInt> al;
    BinTree<ParInt> ar;

	read_bintree_parint(al);
	read_bintree_parint(ar);
	a=BinTree<ParInt>(p,al,ar);
  }
}

void write_bintree_parint(const BinTree<ParInt>& a) {
	if (not a.empty()) {
		write_bintree_parint(a.left()); 
		a.value().escriure();
		write_bintree_parint(a.right());
  }
}
