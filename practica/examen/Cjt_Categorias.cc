/** @file Cjt_Categorias.cc
    @brief Implementación de la clase Cjt_Categorias
*/

#include "Cjt_Categorias.hh"

Cjt_Categorias::Cjt_Categorias() {
    
}

//Consultoras

int Cjt_Categorias::consultar_punts(int c, int k) const{
    return matpuntos[c-1][k-1];
}

string Cjt_Categorias::consultar_nombre_categoria(int i) const {
    return categorias[i-1];
}

int Cjt_Categorias::max_categoria() const{
    return ncategorias;
}

//escriptura y lectura

void Cjt_Categorias::listar_categorias() const{
    cout << ncategorias << " " << nniveles << endl;
    for(int i=0; i<ncategorias; ++i) {
        cout << categorias[i];
        for (int j=0; j<nniveles; ++j) {
            cout << " " << matpuntos[i][j];
        }
        cout << endl;
    }
}

void Cjt_Categorias::leer(){
    cin >> ncategorias >> nniveles;
    categorias = vector<string>(ncategorias);
    matpuntos = vector<vector<int>>(ncategorias,vector<int>(nniveles));
    for(int i=0; i<ncategorias; ++i) {
        cin >> categorias[i];
    }
    for(int j=0; j<ncategorias; ++j) {
        for(int l=0; l<nniveles; ++l) {
            cin >> matpuntos[j][l];
        }
    }
}
