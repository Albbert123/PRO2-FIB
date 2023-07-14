/** @file Cjt_jugadores.hh
    @brief Especificación de la clase Cjt_Jugadores
*/

#ifndef CJT_JUGADORES_HH
#define CJT_JUGADORES_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class Cjt_Jugadores
    @brief Representa el conjunto de los jugadores que participan en el circuito

*/

class Cjt_Jugadores {

private:
    /** @brief Entero con el numero de jugadores */
    int njugadores;

    double perc_sets_g;

    /** @brief Vector de iteradores del mapa con clave string i clase Jugador */
    vector<map<string,Jugador>::iterator> it_ranking;

    /** @brief Map con clave string i clase Jugador "jugadores" */
    map<string,Jugador> jugadores;

    /** @brief Booleano para ordenar los jugadores
        \pre Cierto..
        \post El resultado es Cierto. si los puntos de a es mayor que b, en caso de empate es Cierto.
        si la posicion anterior de a es mayor que la de b.
    */
    static bool cmp(const map<string,Jugador>::iterator& a, const map<string,Jugador>::iterator& b);

public:
    //Constructoras

    /** @brief Creadora por defecto

        Se ejecuta automáticamente al declarar un Cjt_jugadores.
        \pre Cierto..
        \post El resultado es un conjunt de jugadores vacío.
    */
    Cjt_Jugadores();

    //Modificadoras

    /** @brief Crea un nuevo jugador
        \pre No hay otro jugador con el mismo nombre "nom".
        \post Se ha añadido el jugador con nombre "nom" al parametre implicit, se imprime el número de jugadores P 
        en el circuito después de añadirlo.
    */
    void nuevo_jugador(const string& nom);

    /** @brief Da de baja a un jugador
        \pre Existe un jugador con el nombre "nom".
        \post Se ha borrado al jugador con nombre "nom", i los anteriores a él se le suma una posicion (act. ranking);
        se imprime en numero de jugadores P.
    */
    void baja_jugador(const string& nom);

    /** @brief Modificadora de la posicion
        \pre El jugador esta en la posicion 1 o mas.
        \post Se ha modificado la posicion "posicion" al jugador con nombre "nom".
    */
    void modificar_posicion(const string& nom, int posicion);

    /** @brief Modificadora de los puntos
        \pre El jugador tiene >=0 puntos.
        \post Se han quitado los puntos "puntos" al jugador con nombre "nom".
    */
    void quitar_puntos(const string& nom, int puntos);

    /** @brief Modificadora de las estadisiticas del jugador
        \pre El jugador tiene minimo 0 en las estadisticas.
        \post Se han modificado todas las estadisticas del jugador con nombre "nom".
    */
    void modificar_estadisticas(const string& nom, int puntos, int sets_g, int sets_p, int juegos_g, int juegos_p,
        int partidos_g, int partidos_p, int torneos_jugados);
    
    /** @brief Modificadora que reordena los jugadores
        \pre Cierto..
        \post Se ordenan los jugadores por orden de posicion mas bajo.
    */
    void reordenar_ranking();

    void modificar_perc(const float& porcentaje);

    void mejor_jugador();

    //Consultoras

    /** @brief Consultora de la posicion
        \pre Cierto.
        \post El resultado es la posicion del parametre implicit.
    */
    int consultar_posicion(const string& nom) const;

    /** @brief Consultora de los puntos
        \pre Cierto.
        \post El resultado son los puntos del parametre implicit.
    */
    int consultar_puntos(const string& nom) const;

    /** @brief Consultora de los torneos jugados
        \pre Cierto.
        \post El resultado son los torneos jugados del parametre implicit.
    */
    int consultar_torneos(string& nom) const;

    /** @brief Consultora de la existencia de un jugador
        \pre Cierto.
        \post El resultado es un booleano diciendo si existe el jugador con nombre "nom".
    */
    bool existe_jugador(const string& nom) const;

    /** @brief Consultora del numero de jugadores
        \pre Cierto.
        \post El resultado son el numero de jugadores totales del parametre implicit.
    */
    int consultar_numero_jugadores() const;

    /** @brief Consultora del nombre de un jugador
        \pre Existe un jugador con la posicion "posicion".
        \post El resultado es el nombre del jugador de la "posicion". 
    */
    string consultar_nombre(int posicion) const;

    /** @brief Consultora de un jugador
        \pre Existe un jugador amb nom_jugador = nom.
        \post El resultado es el jugador nom_jugador = nom
    */
    void consultar_jugador(const string& nom) const; //escribir.

    //escriptura y lectura;

    /** @brief Escritura de los jugadores
        \pre Cierto.
        \post Se han escrito los jugadores por orden creciente de nombre, con sus estadisiticas.
    */
    void listar_jugadores() const;

    /** @brief Escritura del ranking
        \pre Cierto.
        \post Se han escrito los jugadores por orden creciente de la posicion del ranking,
        con su posicion, su nombre y puntos.
    */
    void listar_ranking() const;

    /** @brief Operacion de lectura
        \pre  Esta preparado el vector "jugadores".
        \post El parametro implicito pasa a tener los valores leidos.
    */
    void leer();

};
#endif
