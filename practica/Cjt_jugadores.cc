/** @file Cjt_jugadores.cc
    @brief Implementación de la clase Cjt_Jugadores
*/

#include "Cjt_jugadores.hh"
#include <algorithm>

Cjt_Jugadores::Cjt_Jugadores(){

}

//Modificadoras

void Cjt_Jugadores::nuevo_jugador(const string& nom) {
    map<string, Jugador>::iterator it = jugadores.end();
    it = jugadores.insert(it, make_pair(nom,Jugador(njugadores+1)));
    it_ranking.push_back(it);
    ++njugadores;
}

void Cjt_Jugadores::baja_jugador(const string& nom) {
    map<string, Jugador>::const_iterator it = jugadores.find(nom);
    int i = (*it).second.consultar_posicion();
    it = jugadores.erase(it);
    //sumar +1 posicion a los que estaban detras del jugador
    for(int j=i-1; j<njugadores-1; ++j) {
        it_ranking[j] = it_ranking[j+1];
        it_ranking[j]->second.modificar_posicion(-1);
    }
    it_ranking.pop_back();
    --njugadores;
}

void Cjt_Jugadores::quitar_puntos(const string& nom, int puntos){
    jugadores[nom].sumar_puntos(-puntos);
}

void Cjt_Jugadores::modificar_posicion(const string& nom, int posicion){
    jugadores[nom].modificar_posicion(posicion);
}

void Cjt_Jugadores::modificar_estadisticas(const string& nom, int puntos, int sets_g, int sets_p, int juegos_g,
    int juegos_p, int partidos_g, int partidos_p, int torneos_jugados) {
        map<string,Jugador>::iterator it = jugadores.find(nom);
        (*it).second.sumar_puntos(puntos);
        (*it).second.sumar_sets_g(sets_g);
        (*it).second.sumar_juegos_g(juegos_g);
        (*it).second.sumar_sets_p(sets_p);
        (*it).second.sumar_juegos_p(juegos_p);
        (*it).second.sumar_partidos_g(partidos_g);
        (*it).second.sumar_partidos_p(partidos_p);
        (*it).second.sumar_torneos(torneos_jugados);
}

bool Cjt_Jugadores::cmp(const map<string,Jugador>::iterator& a, const map<string,Jugador>::iterator& b) {
    if ((*a).second.consultar_puntos() == (*b).second.consultar_puntos()) {
        return ((*a).second.consultar_posicion() < (*b).second.consultar_posicion());
    }
    return ((*a).second.consultar_puntos() > (*b).second.consultar_puntos());
}

void Cjt_Jugadores::reordenar_ranking() {
    sort(it_ranking.begin(), it_ranking.begin()+njugadores, cmp);

    for(int i=0; i<njugadores; ++i) {
        int posicion = (*it_ranking[i]).second.consultar_posicion();
        (*it_ranking[i]).second.modificar_posicion(i + 1 - posicion);
    }
}

//Consultoras

int Cjt_Jugadores::consultar_posicion(const string& nom) const {
    map<string, Jugador>::const_iterator it = jugadores.find(nom);
    return (*it).second.consultar_posicion();
}

int Cjt_Jugadores::consultar_puntos(const string& nom) const{
    map<string, Jugador>::const_iterator it = jugadores.find(nom);
    return (*it).second.consultar_puntos();
}

int Cjt_Jugadores::consultar_torneos(string& nom) const{
    map<string, Jugador>::const_iterator it = jugadores.find(nom);
    return (*it).second.consultar_torneos();
}

bool Cjt_Jugadores::existe_jugador(const string& nom) const{
    map<string, Jugador>::const_iterator it = jugadores.find(nom);
    return it != jugadores.end();
}

int Cjt_Jugadores::consultar_numero_jugadores() const{
    return njugadores;
}

string Cjt_Jugadores::consultar_nombre(int posicion) const {
    return (*it_ranking[posicion-1]).first;
}

void Cjt_Jugadores::consultar_jugador(const string& nom) const{
    map<string, Jugador>::const_iterator it = jugadores.find(nom);
    cout << (*it).first << " ";
    (*it).second.escribir_jugador();
}

//escriptura y lectura;

void Cjt_Jugadores::listar_jugadores() const{
    cout << njugadores << endl;
    for(map<string, Jugador>::const_iterator it=jugadores.begin(); it!=jugadores.end(); ++it) {
        cout << (*it).first << " ";
        (*it).second.escribir_jugador();
    }
}

void Cjt_Jugadores::listar_ranking() const{
    for(int i=0; i<njugadores; ++i) {
        cout << i+1 << " ";
        cout << (*it_ranking[i]).first << " " << (*it_ranking[i]).second.consultar_puntos() << endl;
    }
}

void Cjt_Jugadores::leer(){
    map<string, Jugador>::iterator it = jugadores.end();
    cin >> njugadores;
    it_ranking = vector<map<string,Jugador>::iterator>(njugadores);
    
    for(int i=0; i<njugadores; ++i) {
        string nom;
        cin >> nom;
        it = jugadores.insert(it,make_pair(nom,Jugador(i+1)));
        it_ranking[i] = it;
    }
}
