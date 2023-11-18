#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <string>
#include <iostream>
#include "motore.h"
using namespace std;

class Automobile{
	private:
		string marca, modello;
		// 0 - 1 : elemento puntatore
		Motore motore;
		Motore* motoreScorta;
	public:
		Automobile(string _marca, string _modello, int cilindrata, Tipocomb* tipo);
		~Automobile();
		void addMotoreScorta(int cilindrata, Tipocomb* tipo);
		friend ostream& operator << (ostream& os, const Automobile& automobile);
};

ostream& operator << (ostream& os, const Automobile& automobile);

#endif
