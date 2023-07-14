#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a) {
  Estudiant est;
  est.llegir();
  if (est.consultar_DNI() != 0 or est.consultar_nota() != 0){
	BinTree<Estudiant> el;
    BinTree<Estudiant> er;

	read_bintree_est(el);
	read_bintree_est(er);
	a=BinTree<Estudiant>(est,el,er);
  }
}

void write_bintree_est(const BinTree<Estudiant>& a) {
	if (not a.empty()) {
		write_bintree_est(a.left()); 
		if (a.value().te_nota()) a.value().escriure();
        else cout << a.value().consultar_DNI() << " -1" << endl;
		write_bintree_est(a.right());
  }
}