#include <iostream>
#include "persona.h"
#include "studente.h"
using namespace std;

int main(int argc, char** argv) {
	// Persona p("Riccardo", "Fusiello", 20);
	// cout << p << endl << endl;
	// il default va nell'header NON nel .cpp
	// Persona p2("Appena", "Nato");
	// cout << p2 << endl << endl;
	// p2.stampa();

	Studente s1(123456, "std1", "cognome1", 22); // N.B: va dichiarato lo "studente.h" -> evito l'include di
	// deve dichiare il metodo virtuale della classe puramente virtuale
	 
	// "persona.h" iif devo usare solo studenti
	// s1.stampa();

	// Persona* pp;
	/*
	pp = new Persona("Michele", "Misseri", 77);
	delete pp;
	*/

	// pp = new Studente(666, "Nome Del Diavolo", "Cognome Del Diavolo", 99);

	// pp->stampa();

	// trucco per chiamare << della sottoclasse (è sempre all'esame!!)
	// cout << *pp << endl;
	// pp->Persona::stampa();

	// delete pp; // non muore lo studente!!!

	// take-home message : override dei metodi se faccio A* = B -> virtual!!!!

	// p = s1;
	// p.stampa(); // std1 cognome 1 di eta' 22

	return 0;
}
