OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
program.exe: program.o Cjt_Torneos.o Cjt_Categorias.o Cjt_jugadores.o Jugador.o Torneo.o 
	g++ -o program.exe program.o Cjt_Torneos.o Cjt_Categorias.o Cjt_jugadores.o Jugador.o Torneo.o 
#
program.o: program.cc
	g++ -c program.cc $(OPCIONS)
#
Cjt_Torneos.o: Cjt_Torneos.cc Cjt_Torneos.hh
	g++ -c Cjt_Torneos.cc $(OPCIONS)
#
Torneo.o: Torneo.cc Torneo.hh
	g++ -c Torneo.cc $(OPCIONS)
#
Cjt_Categorias.o: Cjt_Categorias.cc Cjt_Categorias.hh
	g++ -c Cjt_Categorias.cc $(OPCIONS)
#
Cjt_jugadores.o: Cjt_jugadores.cc Cjt_jugadores.hh
	g++ -c Cjt_jugadores.cc $(OPCIONS)
#
Jugador.o:  Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS)
#
practica.tar: program.cc Jugador.cc Jugador.hh Cjt_jugadores.cc Cjt_jugadores.hh Torneo.cc Torneo.hh Cjt_Torneos.cc Cjt_Torneos.hh Cjt_Categorias.cc Cjt_Categorias.hh Makefile 
	tar -cvf practica.tar program.cc Jugador.cc Jugador.hh Cjt_jugadores.cc Cjt_jugadores.hh Torneo.cc Torneo.hh Cjt_Torneos.cc Cjt_Torneos.hh Cjt_Categorias.cc Cjt_Categorias.hh Makefile 
#
clean:
	rm -f *.o
	rm -f *.exe
