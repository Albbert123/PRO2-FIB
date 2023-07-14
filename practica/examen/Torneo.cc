/** @file Torneo.cc
    @brief Implementación de la clase Torneo
*/

#include "Torneo.hh"

Torneo::Torneo() {

}

Torneo::Torneo(int categoria){
    this->categoria = categoria;
    disputado = false;
}

BinTree<int> Torneo::modificador_torneo(const BinTree<string>& resultats, const BinTree<int>& parejas, int nivel, const Cjt_Categorias& cc, vector<Actualizar_datos>& est){
    int sets_gi, sets_gd, juegos_gi, juegos_gd;
    bool gana_izquierdo = true;
    if(not parejas.left().empty() and not parejas.right().empty()) {
        BinTree<int> izquierdo = modificador_torneo(resultats.left(), parejas.left(), nivel+1, cc, est);
        BinTree<int> derecho = modificador_torneo(resultats.right(), parejas.right(), nivel+1, cc, est);

        partido(resultats.value(), gana_izquierdo, juegos_gi, juegos_gd, sets_gi, sets_gd);
        if (gana_izquierdo) {
            //stats del jugador izquierdo(ganador)
            est[izquierdo.value() -1].juegos_g += juegos_gi;
            est[izquierdo.value() -1].sets_g += sets_gi;
            ++est[izquierdo.value() -1].partidos_g;
            est[izquierdo.value() -1].juegos_p += juegos_gd;
            est[izquierdo.value() -1].sets_p += sets_gd;
            //stats del jugador derecho(perdedor)
            est[derecho.value() -1].juegos_g += juegos_gd;
            est[derecho.value() -1].sets_g += sets_gd;
            ++est[derecho.value() -1].partidos_p;
            est[derecho.value() -1].juegos_p += juegos_gi;
            est[derecho.value() -1].sets_p += sets_gi;
            est[derecho.value() -1].puntos += cc.consultar_punts(categoria, nivel);

            return BinTree<int>(izquierdo.value(), izquierdo, derecho);
        }
        else {
            //stats del jugador derecho(ganador)
            est[derecho.value() -1].juegos_g += juegos_gd;
            est[derecho.value() -1].sets_g += sets_gd;
            ++est[derecho.value() -1].partidos_g;
            est[derecho.value() -1].juegos_p += juegos_gi;
            est[derecho.value() -1].sets_p += sets_gi;
            //stats del jugador izquierdo(perdedor)
            est[izquierdo.value() -1].juegos_g += juegos_gi;
            est[izquierdo.value() -1].sets_g += sets_gi;
            ++est[izquierdo.value() -1].partidos_p;
            est[izquierdo.value() -1].juegos_p += juegos_gd;
            est[izquierdo.value() -1].sets_p += sets_gd;
            est[izquierdo.value() -1].puntos += cc.consultar_punts(categoria, nivel);
            
            return BinTree<int>(derecho.value(), izquierdo, derecho);
        }
    }
    return BinTree<int> (parejas.value()); 
}

void Torneo::leer_inscritos(const Cjt_Jugadores& cj) {
    cin >> ninscritos;
    ranking_local = vector<string>(ninscritos);
    for(int i=0; i<ninscritos; ++i) {
        int n; //jugador
        cin >> n;
        ranking_local[i] = cj.consultar_nombre(n);
    }
}

BinTree<string> Torneo::leer_resultados(){ 
    string partit;
    cin >> partit;
    if(partit != "0") { 
        BinTree<string> izquierdo = leer_resultados();
        BinTree<string> derecho = leer_resultados();
        return BinTree<string>(partit, izquierdo, derecho);
    }
    return BinTree<string>(partit);
}

BinTree<int> Torneo::crear_emparejamiento(int profundidad, int raiz, int nivel){
    int b;
    if(nivel == 1) {
        b=2;
    }
    else {
        if(raiz%2 != 0) b = profundidad - raiz;
        else b = profundidad - raiz + 2;
    } 
    if(b<=ninscritos) { 
        BinTree<int> izquierdo = crear_emparejamiento(profundidad*2, raiz, nivel+1);
        BinTree<int> derecho = crear_emparejamiento(profundidad*2, b, nivel+1);
        return BinTree<int> (raiz, izquierdo, derecho);
    }
    return BinTree<int>(raiz);
}

void Torneo::escribir_resultado_emparejamiento(const BinTree<int>& t) const{
    if(not t.empty()) {
        if(t.left().empty() and t.right().empty()) cout << t.value() << "." << ranking_local[t.value() -1];
        else {
            cout << "(";
            escribir_resultado_emparejamiento(t.left());
            cout << " ";
            escribir_resultado_emparejamiento(t.right());
            cout << ")";
        }
    }
}

void Torneo::escribir_cuadro_resultados(const BinTree<string>& c, const BinTree<int>& i) const {
    if(not c.empty() and not i.empty()) {
        if((not c.left().empty() and not c.right().empty()) and (not i.left().empty() and not i.right().empty())) {
            cout << "(";
            cout << i.left().value() << "." << ranking_local[i.left().value() -1] << " vs " 
                 << i.right().value() << "." << ranking_local[i.right().value() -1] << " " << c.value();
            
            escribir_cuadro_resultados(c.left(), i.left());
            escribir_cuadro_resultados(c.right(), i.right());
            cout << ")";
        }   
    }
}

void Torneo::partido(const string& partido, bool& gana_izquierdo, int& juegos_gi, int& juegos_gd, int& sets_gi, int& sets_gd) {
    sets_gd = 0; //sets ganados del hijo derecho
    sets_gi = 0; //sets ganados del hijo izquierdo
    if(partido.size() == 3) {
        if((partido[0] - '0')==1 and (partido[2] - '0')==0) gana_izquierdo = true;
        else if ((partido[0] - '0')==0 and (partido[2] - '0')==1) gana_izquierdo = false;
        juegos_gi=0;
        juegos_gd=0;
    }

    else if(partido.size() == 7) {
        juegos_gi = (partido[0] - '0') + (partido[4] - '0');
        juegos_gd = (partido[2] - '0') + (partido[6] - '0');
        if(juegos_gi > juegos_gd) {
            sets_gi = sets_gi + 2;
            gana_izquierdo = true;
        }
        else {
            sets_gd = sets_gd + 2;
            gana_izquierdo = false;
        }
    }

    else if(partido.size() == 11) {
        juegos_gi = (partido[0] - '0') + (partido[4] - '0') + (partido[8] - '0');
        juegos_gd = (partido[2] - '0') + (partido[6] - '0') + (partido[10] - '0');
        int i=0;
        int j=2;
        while(sets_gi < 2 and sets_gd < 2) {
            if((partido[i] - '0') > (partido[j] - '0')) ++sets_gi;
            else ++sets_gd;
            i = i + 4;
            j = j + 4;
        }
        if(sets_gi > sets_gd) gana_izquierdo = true;
        else gana_izquierdo = false;
    }
}

void Torneo::quitar_puntuaciones_pasadas(Cjt_Jugadores& cj) {
    map<string,int>::const_iterator it = puntuaciones_pasadas.begin(); 
    while(it != puntuaciones_pasadas.end()) { //quitar puntos de ediciones pasadas
        cj.quitar_puntos((*it).first, (*it).second);
        ++it;
    }
}

void Torneo::actualizar_y_listar(vector<Actualizar_datos>& est, Cjt_Jugadores& cj) {
    map<string,int> torneo_ant;
    for(int j=0; j<ninscritos; ++j) { //pasar del struct a los datos del jugador
        cj.modificar_estadisticas(ranking_local[j], est[j].puntos, est[j].sets_g, est[j].sets_p, est[j].juegos_g, 
        est[j].juegos_p, est[j].partidos_g, est[j].partidos_p, 1);
;
        torneo_ant[ranking_local[j]] = est[j].puntos;

        if (est[j].puntos!= 0) { //escribir jugadores con los puntos actualizados
            cout << j+1 << "." << ranking_local[j] << " " << est[j].puntos << endl;
        }
    }
    puntuaciones_pasadas = torneo_ant;
}

//Modificadoras

void Torneo::quitar_puntos(Cjt_Jugadores& cj) {
    for (map<string,int>::const_iterator it = puntuaciones_pasadas.begin(); it != puntuaciones_pasadas.end(); ++it) {
        cj.quitar_puntos((*it).first, (*it).second);
    }
}

void Torneo::iniciar_torneo(const Cjt_Jugadores& cj){
    leer_inscritos(cj);
    emparejamiento = crear_emparejamiento(2,1,1);
    escribir_resultado_emparejamiento(emparejamiento);
    cout << endl;
    finalizado = false;
    disputado = true;
}

void Torneo::finalizar_torneo(Cjt_Jugadores&cj, const Cjt_Categorias&cc){
    vector<Actualizar_datos> est(ninscritos);
    resultados = leer_resultados();
    emparejamiento = modificador_torneo(resultados, emparejamiento, 2, cc, est);
    est[emparejamiento.value() -1].puntos = cc.consultar_punts(categoria,1); //sumar puntos del ganador

    //escribir_cuadro_resultados(resultados, emparejamiento);
    //cout << endl;

    quitar_puntuaciones_pasadas(cj);
    actualizar_y_listar(est,cj);

    cj.reordenar_ranking();

    primer_torneo = false;

    finalizado = true;
}


void Torneo::baja_jugador(const string& nom) { 
    map<string,int>::const_iterator it = puntuaciones_pasadas.find(nom);
    if(it != puntuaciones_pasadas.end()) it = puntuaciones_pasadas.erase(it);
}

void Torneo::resultados_torneo() {
    escribir_cuadro_resultados(resultados, emparejamiento);
    cout << endl;
    //primer_torneo = false;
}

//Consultoras

int Torneo::consultar_categoria() const{
    return categoria;
}

bool Torneo::consultar_primer_torneo() const {
    return primer_torneo;
}

bool Torneo::consultar_finalizado() const {
    return finalizado;
}

bool Torneo::consultar_disputado() const {
    return disputado;
}

