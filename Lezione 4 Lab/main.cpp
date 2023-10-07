#include <iostream>
// #include "motore.h"
#include "automobile.h"
#include "tipocomb.h"
using namespace std;

int main(int argc, char** argv) {
	// Tipocomb c1(DIESEL);
	// cout << c1 << endl << endl;
	
	/*
		IL MAIN NON PASSA ISTANZA, PASSA PARAMETRI!!!!
	*/
	/*
	Motore m1(100, GPL);
	cout << m1 << endl << endl;
	*/
	
	Tipocomb diesel(DIESEL), benzina(BENZINA), gpl(GPL);
	
	Automobile a1("Fiat", "Bravo", 1500, &gpl);
	cout << a1 << endl << endl;
	a1.addMotoreScorta(1000, &benzina);

	// creerei il combustibile GPL per due istanze uguali (inutile) -> creo una reference al tipo di combustibile creato
	// aggregazione: mi riferisco ad una istanza della classe creata da qualcun'altro
	Automobile a2("TestaRossa", "Ferrari", 4000, &gpl);
	return 0;
}

// un istanza della classe deve avere un contenitore dove essere istanziata
// auto inclusa nel nostro main
// main non conosce la classe Motore (non sa come è fatta l'auto)
// si parte sempre dall'ultima classe

