/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#include "Cjt_jugadores.hh"
#include "Cjt_Categorias.hh"

#ifndef NO_DIAGRAM
#include <map>
#include "BinTree.hh"
#include <cmath>
#include <string>
#endif

/** @class Torneo
    @brief Representa un torneo del circuito

*/

class Torneo {

private:
     /** @brief Categoria del torneo */
    int categoria;

    /** @brief Numero de inscritos en el torneo */
    int ninscritos;

    /** @brief Vector de strings con los nombres de los jugadores */
    vector<string> ranking_local;

    /** @brief Mapa con clave string que tiene los puntos de la edicion pasada */
    map<string,int> puntuaciones_pasadas;

    /** @brief Tupla auxilizar para actualizar las estadisticas del jugador */
    struct Actualizar_datos {
      int puntos, sets_g, sets_p, juegos_g, juegos_p, partidos_g, partidos_p, torneos_jugados;
    };

    /** @brief Booleano para saber si es el primer torneo */
    bool primer_torneo = true;

    /** @brief Arbol binario de enteros para guardar los emparejamientos de los torneos */
    BinTree<int> emparejamiento;

    /** @brief Arbol binario de strings para guardar los resultados de los partidos */
    BinTree<string> resultados;

    /** @brief Funcion para modificar el arbol de emparejamientos previo, i actualiza las estadisticas de la Tupla auxuliar
        \pre Se han leido los resultados i se ha creado los emparejamientos.
        \post El resultado es un arbol binario de enteros con los ganadores de cada partido. La Tupla ha sido actualizada
        con las estadisticas del torneo.
    */
    BinTree<int> modificador_torneo(const BinTree<string>& resultats, const BinTree<int>& parejas, int nivel, const Cjt_Categorias& cc, vector<Actualizar_datos>& est);

    /** @brief Funcion para leer los inscritos del torneo
        \pre Existe el torneo en el circuito. Los ninscritos no superan los njugadores el circuito; ninscritos<=njugadores.
        \post El resultado son los jugadores inscritos en el torneo (leídos crecientemente por ranking). Se guardan los
        nombres en el ranking local.
    */
    void leer_inscritos(const Cjt_Jugadores& cj);

    /** @brief Funcion para leer los resultados en arbol binario
        \pre Se ha creado el emparejamiento del torneo.
        \post El resultado es un arbol binario de strings con los resultados de los partidos del torneo, leídos en preorden.
    */
    BinTree<string> leer_resultados();

    /** @brief Funcion para crear el emparejamiento del torneo
        \pre Se han leido los inscritos del torneo.
        \post Se crea el arbol binario de los emparejamientos del torneo, según la posicion en el ranking local.
    */
    BinTree<int> crear_emparejamiento(int profundidad, int raiz); 

    /** @brief Accion para escribir el resultado del emparejamiento
        \pre Se ha creado el arbol de emparejamiento.
        \post Se escribe el arbol creado con la posicion del torneo y el nombre.
    */
    void escribir_resultado_emparejamiento(const BinTree<int>& t) const;

    /** @brief Funcion para imprimir el cuadro de resultados
        \pre Se han leido los resultados.
        \post Se escribe el arbol creado con los resultados de cada partido, mostrando también posicion y nombre.
    */
    void escribir_cuadro_resultados(const BinTree<string>& c, const BinTree<int>& i) const;

    /** @brief Resultado de un partido
        \pre Los jugadores pertenecen al cjt_jugadores i la mida del partido (string) es de 3, 7 o 11.
        \post Se retorna el booleano a cierto si gana el izquierdo, i las estadisticas actualizadas dependiendo 
        del resultado del partido.
    */
    void partido(const string& partido, bool& gana_izquierdo, int& juegos_gi, int& juegos_gd, int& sets_gi, int& sets_gd);

    /** @brief Modificadora que quita los puntos de la edicion pasada
        \pre El jugador ha jugado la edicion anterior.
        \post El jugador del conjunto de jugadores se le han quitado los puntos de las edicion anterior.
    */
    void quitar_puntuaciones_pasadas(Cjt_Jugadores& cj);

    /** @brief Modificadora que actualiza los datos del jugador y los lista
        \pre Se han calculado y guardado los puntos de los jugadores al vector de la tupla "Actualizar_datos".
        \post Los datos de los jugadores han sido actualizados y se han listado por orden del ranking del torneo
        los jugadores con sus puntos conseguidos. Si un jugador no gana puntos no se lista.
    */
    void actualizar_y_listar(vector<Actualizar_datos>& est, Cjt_Jugadores& cj);

public:
    //Constructoras

    /** @brief Creadora por defecto

        Se ejecuta automáticamente al declarar un Torneo.
        \pre Cierto.
        \post El resultado es un torneo sin jugadores, con categoria y nombre.
    */
    Torneo();

    /** @brief Creadora con parametro Categoria

        \pre Categoria entre 1 i C.
        \post El resultado es un torneo sin jugadores, con categoria=categoria.
    */
    Torneo(int categoria);

    //Modificadoras

    /** @brief Modificadora que quita puntos al Jugador
        \pre El Jugador tiene >=0 puntos.
        \post Se han quitado los puntos al jugador con nombre "nom".
    */
    void quitar_puntos(Cjt_Jugadores& cj);

     /** @brief Inicia un Torneo
        \pre El torneo existe en el circuito. Se ha llamado a iniciar torneo del cjt_torneos.
        \post Se inicia el torneo con el conjunto de jugadores cj, se imprime el cuadro de emparejamientos del torneo
        teniendo en cuenta el ranking local de este.
    */
    void iniciar_torneo(const Cjt_Jugadores& cj);

    /** @brief Finaliza un Torneo
        \pre El torneo existe en el circuito. Se ha llamado a iniciar torneo previamente de ese torneo, y a finalizar 
        torneo del cjt_torneos.
        \post Se finaliza el torneo, imprimiendo los partidos con sus resultados y listando los jugadores
        participes del torneo con los puntos ganados. Si un jugador no gana puntos en el torneo no se lista. Al jugador
        partícipe se le suman o restan la diferencia de puntos respecto la anterior edición, en caso de haberla jugado.
        Se modifican todas las estadisitcas a los jugadores participes y se actualiza el ranking.
    */
    void finalizar_torneo(Cjt_Jugadores&cj, const Cjt_Categorias&cc);

    /** @brief Modificadora que da de baja al jugador del torneo
        \pre Existe el jugador con nombre "nom".
        \post El jugador con el identificador "nom" ha sido borrado de los torneos a los que participaba.
    */
    void baja_jugador(const string& nom);

    //Consultoras

    /** @brief Consultora de la categoria del torneo
        \pre Hay un torneo con una categoria C.
        \post El resultado es la categorua C del parametre implicit.
    */
    int consultar_categoria() const;

    /** @brief Consultora del primer torneo
        \pre Cierto.
        \post El resultado es un booleano mostrando si es el primer torneo del paramatre implicit.
    */
    bool consultar_primer_torneo() const;

};
#endif