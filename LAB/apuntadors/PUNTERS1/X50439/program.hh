
node_pila* copia_node_pila_it(node_pila* m)
{
  node_pila* arriba;
  if(m==NULL) arriba = NULL;
  else {
    node_pila* aux;
    aux = new node_pila;
    arriba = aux;

    aux->info = m->info;
    m = m->seguent;

    while(m!=NULL) {
      aux->seguent = new node_pila;
      aux = aux->seguent;
      aux->info = m->info;
      m = m->seguent;
    }
    aux->seguent = NULL;
  }
  return arriba;
}

Pila& operator=(const Pila& original)

{
    if (this != &original) {
      altura = original.altura;
      esborra_node_pila_it(primer_node);
      primer_node = copia_node_pila_it(original.primer_node);
    }
    return *this;
}
