/**
 * @mainpage Practica de Programación 2: Torneos de Tennis.

Hecho por: <em>Albert Comas Pacheco</em>.

Fecha: <em>17 mayo 2022</em>.

Curso: <em>2021-2022</em>.

Esta práctica de programación tenia como objetivo enseñar como se trabaja con módulos, a partir de un circuito de tenis.
Para ello he implementado 5 clases:
    - Jugador.cc
    - Cjt_Jugadores.cc
    - Torneo.cc
    - Cjt_Torneos.cc
    - Cjt_Categorias.cc

Cada implementación tiene su especificación:
    - Jugador.hh
    - Cjt_Jugadores.hh
    - Torneo.hh
    - Cjt_Torneos.hh
    - Cjt_Categorias.hh

*/

/** @file program.cc
    @brief Programa principal para la practica <em>Torneos de tenis</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Cjt_jugadores.hh"
#include "Cjt_Torneos.hh"
#include "Cjt_Categorias.hh"

#ifndef NO_DIAGRAM // despues de hacer esta llamada no se añaden las poseriores
#include "BinTree.hh"
#include <map>
#include <vector>
#endif

/** @brief Programa principal para la practica <em>Torneos de tenis</em>.
*/


int main() {
    Cjt_Categorias cc;
    Cjt_Torneos ct;
    Cjt_Jugadores cj;

    cc.leer();
    ct.leer();
    cj.leer();

    string comando;
    cin >> comando;
    while (comando != "fin") {
        cout << "#";
        if(comando == "nuevo_jugador" or comando == "nj") {
            cout << comando << " ";
            string p;
            cin >> p;
            cout << p << endl;
            if (cj.existe_jugador(p)) cout << "error: ya existe un jugador con ese nombre" << endl;
            else {
                cj.nuevo_jugador(p);
                cout << cj.consultar_numero_jugadores() << endl;
            }
        }

        else if(comando == "nuevo_torneo" or comando == "nt") {
            cout << comando << " ";
            string t;
            int c;
            cin >> t >> c;
            cout << t << " " << c << endl;
            if (c > cc.max_categoria() or c<1) cout << "error: la categoria no existe" << endl;
            else if (ct.existe_torneo(t)) cout << "error: ya existe un torneo con ese nombre" << endl;
            else {
                ct.nuevo_torneo(t,c);
                cout << ct.consultar_numero_torneos() << endl;
            }
        }

        else if (comando == "baja_jugador" or comando == "bj") {
            cout << comando << " ";
            string p;
            cin >> p;
            cout << p << endl;
            if (not cj.existe_jugador(p)) cout << "error: el jugador no existe" << endl;
            else {
                cj.baja_jugador(p); //borrar de los jugadores
                ct.baja_jugador(p); //borrar de los torneos
                cout << cj.consultar_numero_jugadores() << endl;
            }
        }

        else if (comando == "baja_torneo" or comando == "bt") {
            cout << comando << " ";
            string t;
            cin >> t;
            cout << t << endl;
            if (not ct.existe_torneo(t)) cout << "error: el torneo no existe" << endl;
            else {
                ct.baja_torneo(t,cj);
                cout << ct.consultar_numero_torneos() << endl;
            }
        }

        else if (comando == "iniciar_torneo" or comando == "it") {
            cout << comando << " ";
            string t;
            cin >> t;
            cout << t << endl;
            ct.iniciar_torneo(t, cj);
        }

        else if (comando == "finalizar_torneo" or comando == "ft") {
            cout << comando << " ";
            string t;
            cin >> t;
            cout << t << endl;
            ct.finalizar_torneo(t,cj,cc);
        }

        else if (comando == "listar_ranking" or comando == "lr") {
            cout << comando << endl;
            cj.listar_ranking();
        }

        else if (comando == "listar_jugadores" or comando == "lj") {
            cout << comando << endl;
            cj.listar_jugadores();
        }

        else if (comando == "consultar_jugador" or comando == "cj") {
            cout << comando << " ";
            string nombre;
            cin >> nombre;
            cout << nombre << endl;
            if (not cj.existe_jugador(nombre)) cout << "error: el jugador no existe" << endl;
            else cj.consultar_jugador(nombre);
        }

        else if (comando == "listar_torneos" or comando == "lt") {
            cout << comando << endl;
            ct.listar_torneos(cc);
        }

        else if (comando == "listar_categorias" or comando == "lc") {
            cout << comando << endl;
            cc.listar_categorias();
        }

        cin >> comando;
    }
}
