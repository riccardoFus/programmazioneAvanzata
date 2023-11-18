#ifndef MOTORE_H
#define MOTORE_H
#include <iostream>
using namespace std;
#include "tipocomb.h"

// deve essere creato un motore -> deve essere creato un tipo di combustibile

class Motore{
	private:
		int cilindrata;
		Tipocomb* tipo1; // losanga vuota 1,1
		Tipocomb* tipo2; // losanga vuota 0,1
	public:
		// con questo costruttore non riesco a creare un'istanza di tipo combustibile
		// non va costruito un costruttore a due parametri!!!
		// Motore(int _cilindrata, Tcombustibile _comb);
		Motore(int _cilindrata, Tipocomb* _tipo1);
		~Motore();
		friend ostream& operator << (ostream& os, const Motore& motore);
};

ostream& operator << (ostream& os, const Motore& motore);

#endif
