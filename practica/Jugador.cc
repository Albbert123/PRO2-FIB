/** @file Jugador.cc
    @brief Implementación de la clase Jugador
*/

#include "Jugador.hh"

Jugador::Jugador() {
    puntos = 0;
    sets_g = 0;
    sets_p = 0;
    juegos_g = 0;
    juegos_p = 0;
    partidos_g = 0;
    partidos_p = 0;
    torneos_jugados = 0;
}

Jugador::Jugador(int posicio) {
    posicion = posicio;
    puntos = 0;
    sets_g = 0;
    sets_p = 0;
    juegos_g = 0;
    juegos_p = 0;
    partidos_g = 0;
    partidos_p = 0;
    torneos_jugados = 0;
}

// modificadoras

void Jugador::modificar_posicion(int posicion) {
    this->posicion = this->posicion + posicion;
}

void Jugador::sumar_puntos(int puntos) {
    this->puntos = this->puntos + puntos;
}

void Jugador::sumar_sets_g(int sets_g){
    this->sets_g = this->sets_g + sets_g;
}

void Jugador::sumar_juegos_g(int juegos_g){
    this->juegos_g = this->juegos_g + juegos_g;
}

void Jugador::sumar_sets_p(int sets_p){
    this->sets_p = this->sets_p + sets_p;
}

void Jugador::sumar_juegos_p(int juegos_p){
    this->juegos_p = this->juegos_p + juegos_p;
}

void Jugador::sumar_partidos_g(int partidos_g){
    this->partidos_g = this->partidos_g + partidos_g;
}

void Jugador::sumar_partidos_p(int partidos_p){
    this->partidos_p = this->partidos_p + partidos_p;
}

void Jugador::sumar_torneos(int torneos_jugados){
    this->torneos_jugados = this->torneos_jugados + torneos_jugados;
}

//Consultoras

int Jugador::consultar_posicion() const {
    return posicion;
}

int Jugador::consultar_puntos() const{
    return puntos;
}

int Jugador::consultar_torneos() const{
    return torneos_jugados;
}

// escitura y lectura

void Jugador::escribir_jugador() const {
    cout << "Rk:" << posicion << " " << "Ps:" << puntos << " " << "Ts:" << torneos_jugados << " "
         << "WM:" <<  partidos_g << " " << "LM:" << partidos_p << " "
         << "WS:" << sets_g << " " << "LS:" << sets_p << " "
         << "WG:" << juegos_g << " " << "LG:" << juegos_p << endl;
}
