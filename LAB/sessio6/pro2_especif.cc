/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.

En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc //nombre del archivo
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh; despues de hacer esta llamada no se añaden las poseriores(readbool)
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main () {
    Lavadora l;
    Cubeta c; //como pila
    int op;
    cin >> op;
    while (op != -8) {
        if (op == -1) {
            int pmax;
            cin >> pmax;
            bool col = readbool();
            l.inicializar(pmax,col);
        }

        else if (op == -2) {
            int pes;
            cin >> pes;
            bool col;
            col = readbool();
            Prenda p(pes,col);
            l.anadir_prenda(p);
        }

        else if (op == -3) {
            int pes;
            cin >> pes;
            bool col;
            col = readbool();
            Prenda p(pes,col);
            c.anadir_prenda(p);
        }

        else if (op == -4) {
            c.completar_lavadora(l);
        }

        else if (op == -5) {
            l.lavado();
        }

        else if (op == -6) {
            c.escribir();
        }

        else if (op == -7) {
            l.escribir();
        }
        cin >> op;
    }
}
