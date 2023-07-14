/** @file Cjt_categorias.hh
    @brief Especificación de la clase Cjt_Categorias
*/

#ifndef CJT_CATEGORIAS_HH
#define CJT_CATEGORIAS_HH

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#include <vector>
#endif

using namespace std;

/** @class Cjt_Categorias
    @brief Representa el conjunto de categorias

*/

class Cjt_Categorias {

private:
    /** @brief Matriz de puntos de las categorias */
    vector<vector<int>> matpuntos; 

    /** @brief vector de las categorias del circuito */
    vector<string> categorias;

    /** @brief numero de categorias */
    int ncategorias;

    /** @brief numero de niveles de la categoria */
    int nniveles;


public:
    //Constructoras
    
    /** @brief Creadora por defecto
    
         Se ejecuta automáticamente al declarar un Cjt_Categorias.
         \pre Cierto.
         \post El resultado es un conjunto de categorias vacio.
    */
    Cjt_Categorias();

    //Consultoras

    /** @brief Consultora de los puntos de la categoria
        \pre Cierto.
        \post El resultado son los puntos de la categoria del parametre implicit.
    */
    int consultar_punts(int c, int k) const;

    /** @brief Consultora del nombre de la categoria por posicion
        \pre Cierto.
        \post El resultado es el nombre de la categoria de posicion i del parametre implicit.
    */
    string consultar_nombre_categoria(int i) const;

    /** @brief Consultora de la maxima categoria del circuito
        \pre La categoria esta entre 1 i C.
        \post El resultado es un entero con la maxima categoria del parametro implicito.
    */
    int max_categoria() const;


    //escriptura y lectura

    /** @brief Escribe las categorias del circuito
        \pre Cierto.
        \post Se listan por orden creciente de nombre, el nombre y la tabla de puntos por niveles
        (en orden creciente de nivel) de cada categoria del parametre implicit.
    */
    void listar_categorias() const;

    /** @brief Operacion de lectura
        \pre Esta preparado el map "categoria" y la matriz "matpuntos".
        \post El parametro implicito pasa a tener los valores leídos.
    */
    void leer();

};
#endif