#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l){
  ParInt n;  
  list<ParInt>::iterator it = l.end();
  while (n.llegir()) {
    l.insert(it, n);
  }
}