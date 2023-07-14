/** @file Cjt_Torneos.cc
    @brief Implementación de la clase Cjt_Torneos
*/

#include "Cjt_Torneos.hh"

Cjt_Torneos::Cjt_Torneos(){
   
}

//modificadoras

void Cjt_Torneos::nuevo_torneo(const string& t, int categoria){
    Torneo a(categoria);
    circuito.insert(make_pair(t,a));
    ++ntorneos;
}

void Cjt_Torneos::baja_torneo(const string& t, Cjt_Jugadores& cj){ // cj
    map<string,Torneo>::iterator it = circuito.find(t);
    if (not (*it).second.consultar_primer_torneo()) {
      (*it).second.quitar_puntos(cj);
      cj.reordenar_ranking();
    }
    circuito.erase(it);
    --ntorneos;
}

void Cjt_Torneos::iniciar_torneo(const string& t, const Cjt_Jugadores& cj){
    circuito[t].iniciar_torneo(cj);
}

void Cjt_Torneos::finalizar_torneo(const string& t, Cjt_Jugadores&cj, Cjt_Categorias&cc){
    circuito[t].finalizar_torneo(cj,cc);
}

void Cjt_Torneos::baja_jugador(const string& nom) {
    for(map<string,Torneo>::iterator it = circuito.begin(); it != circuito.end(); ++it) { 
        (*it).second.baja_jugador(nom);
    } 
}



//Consultoras

bool Cjt_Torneos::existe_torneo(const string& t) const{
    map<string,Torneo>::const_iterator it = circuito.find(t);
    if (it == circuito.end()) return false;
    return true;
}

int Cjt_Torneos::consultar_numero_torneos() const{
    return ntorneos;
}

bool Cjt_Torneos::consultar_primer_torneo(const string& nom) {
    return circuito[nom].consultar_primer_torneo();
}

bool Cjt_Torneos::consultar_finalizado(const string& nom) {
    return circuito[nom].consultar_finalizado();
}

bool Cjt_Torneos::consultar_disputado(const string& nom) {
    return circuito[nom].consultar_disputado();
}

void Cjt_Torneos::resultados_torneo(const string& nom) {
    circuito[nom].resultados_torneo();
}

//escriptura i lectura

void Cjt_Torneos::listar_torneos(const Cjt_Categorias& cc) const{
    cout << ntorneos << endl;
    for(map<string,Torneo>::const_iterator it=circuito.begin(); it!=circuito.end(); ++it) {
        cout << (*it).first << " ";
        cout << cc.consultar_nombre_categoria((*it).second.consultar_categoria()) << endl;
    }
}

void Cjt_Torneos::leer(){
    cin >> ntorneos;
    for(int i=0; i<ntorneos; ++i) {
        string nom;
        int c; //categoria
        cin >> nom >> c;
        circuito.insert(make_pair(nom,Torneo(c)));
    }
}
