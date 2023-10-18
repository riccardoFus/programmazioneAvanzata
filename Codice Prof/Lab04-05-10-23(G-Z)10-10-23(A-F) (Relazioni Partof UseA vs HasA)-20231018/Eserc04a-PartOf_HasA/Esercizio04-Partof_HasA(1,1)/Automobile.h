#ifndef __AUTOMOBILE_H__
#define __AUTOMOBILE_H__

#include "Motore.h"
#include <string>
using namespace std;

class Automobile {
private:
	Motore motore;
	string marca;
	string modello;
	string targa;
	int velocita;		
	bool is_accesa;

public:
	Automobile(string _marca, string _modello, 
						 Combustibile comb, int _cilindata);

	void immatricola(string _targa);

	void accendi();
	void spegni();

	void accelera();
	void ferma();		

	int get_velocita()const;
	void stampa()const;
	friend ostream& operator << (ostream& os, const Automobile& a);
};

ostream& operator << (ostream& os, const Automobile& a);

#endif

