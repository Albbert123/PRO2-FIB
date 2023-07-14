
void concat(Cua &c)
/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
{
  if (not c.longitud == 0) {
      if(longitud==0) {
        primer_node = c.primer_node;
        ultim_node = c.ultim_node;
        longitud = c.longitud;
      }
      else {
        ultim_node->seguent = c.primer_node;
        longitud = longitud + c.longitud;
        ultim_node = c.ultim_node;
      }
  }
  c.primer_node = NULL;
  c.longitud= 0;
  c.ultim_node= NULL;
}
