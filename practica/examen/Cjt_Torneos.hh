/** @file Cjt_torneos.hh
    @brief Especificación de la clase Cjt_Torneos
*/

#ifndef CJT_TORNEOS_HH
#define CJT_TORNEOS_HH

#include "Torneo.hh"
#include "Cjt_Categorias.hh"
#include "Cjt_jugadores.hh"

/** @class Cjt_Torneos
    @brief Representa el conjunto de torneos (circuito)

*/

class Cjt_Torneos {

private:
    /** @brief Map del conjunto de torneos (circuito) con clave string */    
    map<string,Torneo> circuito;

    /** @brief Numero de torneos */
    int ntorneos;
    
public:
    //Constructoras
    
    /** @brief Creadora por defecto
    
         Se ejecuta automáticamente al declarar un Cjt_torneos.
         \pre Cierto.
         \post El resultado es un conjunt de jugadores vacío.
    */
    Cjt_Torneos();

    //Modificadoras

    /** @brief Crea un nuevo Torneo
        \pre Categoria entre 1 y C, no hay otro torneo con el mismo nombre en el parametre implicit.
        \post Se añade el Torneo con nombre "t" y categoria "categoria" al parametre implicit y se imprime el numero de torneos.
    */
    void nuevo_torneo(const string& t, int categoria);
    
    /** @brief Da de baja un torneo
        \pre Existe un torneo con nombre "t" en el parametre implicit.
        \post Se quita el torneo con nombre "t" del paremetre implicit, asi como los posibles puntos conseguidos por los 
        jugadores en este torneo y se actualiza el ranking. Se imprime el numero de torneos.
    */
    void baja_torneo(const string& t, Cjt_Jugadores& cj); // cj
    
     /** @brief Inicia un Torneo
        \pre el torneo con nombre "t" existe en el parametre implicit
        \post Se lee la inscripcion del torneo (n jugadores inscritos i luego n enteros con sus posiciones en 
        el ranking ordenado creientemente), se confecciona e imprime el cuadro de emparejamientos segun el ranking local.
    */
    void iniciar_torneo(const string& t, const Cjt_Jugadores& cj); //potser no es const ni string

    /** @brief Finaliza un Torneo
        \pre El torneo con nombre "t" existe en el parametre implicit, se ha ejecutado "iniciar_torneo" con el
        mismo identificador anteriormente.
        \post Se leen los resultados del torneo t, se produce e imprime el cuadro oficial de resultados, y se listan 
        los puntos para el ranking ganados por cada uno de los participantes. Si un jugador no gana puntos no se lista.
        Se actualiza el ranking y las estadísticas de los jugadores.
    */
    void finalizar_torneo(const string& t, Cjt_Jugadores&cj, Cjt_Categorias&cc);

    /** @brief Modificadora que da de baja al jugador de los torneos
        \pre Existe el jugador con nombre "nom" en el parametre implicit.
        \post El jugador con el identificador "nom" ha sido borrado de los torneos partícpes.
    */
    void baja_jugador(const string& nom);
    
    //Consultoras

    /** @brief Consulta la existencia de un torneo
        \pre Cierto.
        \post El resultado es un booleano diciendo si el torneo con nombre "t" existe en el parametre implicit.
    */
    bool existe_torneo(const string& t) const;

    /** @brief Consulta el numero de torneos
        \pre Cierto.
        \post El resultado es el numero total de torneos del parametre implicit.
    */
    int consultar_numero_torneos() const;

    //escriptura i lectura

    /** @brief Escribe los torneos
        \pre Cierto.
        \post Se listan, por orden creciente de identificador(nombre), el nombre y la categoría de cada torneo del 
        parametre implicit.
    */
    void listar_torneos(const Cjt_Categorias& cc) const;

    bool consultar_primer_torneo(const string& nom);

    bool consultar_finalizado(const string& nom);

    bool consultar_disputado(const string& nom);

    void resultados_torneo(const string& nom);

    /** @brief Operacion de lectura
        \pre Esta preparado el map "circuito".
        \post El parametro implicito pasa a tener los valores leídos.
    */
    void leer();

};
#endif