/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @class Jugador
    @brief Representa un juagdor del torneo con sus estadísticas, sus consultoras y modificadoras

*/

class Jugador {

private:
    /** @brief Posicion del jugador */
    int posicion;

    /** @brief Puntos del jugador */
    int puntos;

    /** @brief Sets ganador del jugador */
    int sets_g; //ganados

    /** @brief Sets perdidos del jugador */
    int sets_p; //perdidos

    /** @brief Juegos ganados del jugador */
    int juegos_g; //ganados

    /** @brief Juegos perdidos del jugador */
    int juegos_p; //perdidos

    /** @brief Partidos ganados del jugador */
    int partidos_g;

    /** @brief Partidos perdidos del jugador */
    int partidos_p;

    /** @brief Torneos jugados del jugador */
    int torneos_jugados;

    // 0<=posicion, puntos, sets, juegos, torneos


public:
//Constructoras

/** @brief Creadora por defecto.

    Se ejecuta automáticamente al declarar un Jugador.
    \pre Cierto..
    \post El resultado es un jugador con estadisticas 0 i ultima posicion al ranking.
*/
Jugador();

/** @brief Creadora con valor posicion.

    \pre Posicio > 0.
    \post El resultado es un jugador con estadisticas 0 i posicion = POSICIO.
*/
Jugador(int posicio);

//Modificadoras

/** @brief Modificadora de loa posicion
    \pre El está en la posicion 1 o más.
    \post La posicion del parametre implicit pasa a ser "posicion".
*/
void modificar_posicion(int posicion);

/** @brief Modificadora de los puntos
    \pre El jugador tiene 0 o más puntos.
    \post Los puntos del patametre implicit pasa a ser "puntos".
*/
void sumar_puntos(int puntos);

/** @brief Modificadora de los sets ganados
    \pre El jugador tenia 0 o más sets ganados.
    \post Los sets ganados del patametre implicit pasa a ser "sets_g".
*/
void sumar_sets_g(int sets_g);

/** @brief Modificadora de los juegos ganados
    \pre El jugador tenia 0 o más juegos ganados.
    \post Los juegos ganados del patametre implicit pasa a ser "juegos_g".
*/
void sumar_juegos_g(int juegos_g);

/** @brief Modificadora de los sets perdidos
    \pre El jugador tenia 0 o más sets perdidos.
    \post Los sets perdidos del patametre implicit pasa a ser "sets_p".
*/
void sumar_sets_p(int sets_p);

/** @brief Modificadora de los juegos perdidos
    \pre El jugador tenia 0 o más juegos perdidos.
    \post Los juegos perdidos del patametre implicit pasa a ser "juegos_p".
*/
void sumar_juegos_p(int juegos_p);

/** @brief Modificadora de los partidos ganados
    \pre El jugador tenia 0 o más partidos ganados.
    \post Los partidos ganados del patametre implicit pasa a ser "partidos_g".
*/
void sumar_partidos_g(int partidos_g);

/** @brief Modificadora de los partidos perdidos
    \pre El jugador tenia 0 o más partidos perdidos.
    \post Los partidos perdidos del patametre implicit pasa a ser "partidos_p".
*/
void sumar_partidos_p(int partidos_p);

/** @brief Modificadora de los torneos jugados
    \pre El jugador tenia 0 o más torneos jugados.
    \post Los torneos jugados del patametre implicit pasa a ser "torneos_jugados".
*/
void sumar_torneos(int torneos_jugados);

//Consultoras

/** @brief Consultora de la posicion
    \pre Cierto.
    \post El resultado es la posicion del parametre implicit.
*/
int consultar_posicion() const;

/** @brief Consultora de los puntos
    \pre Cierto.
    \post El resultado son los puntos del parametre implicit.
*/
int consultar_puntos() const;

/** @brief Consultora de los torneos jugados
    \pre Cierto.
    \post El resultado son los torneos jugados del parametre implicit.
*/
int consultar_torneos() const;

/** @brief Consultora del nombre del jugador
    \pre Cierto.
    \post El resultado es el nombre del parametre implicit.
*/
string consultar_nom() const;

//escriptura y lectura

/** @brief Operacion de escritura
    \pre Cierto.
    \post se han escrito los atributos del parametro implicito.
    al canal estandard de salida
*/
void escribir_jugador() const;

};
#endif
