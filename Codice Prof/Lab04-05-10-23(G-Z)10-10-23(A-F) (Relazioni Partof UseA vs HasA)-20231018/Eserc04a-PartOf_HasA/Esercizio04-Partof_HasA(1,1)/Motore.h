#ifndef __MOTORE_H__
#define __MOTORE_H__

#include "TipoComb.h"
#include <iostream>
using namespace std;

class Motore
{
 private:
		TipoComb tipo;
		int cilindata;
		int livello_batteria;
		int numero_giri;

 public:
		Motore(Combustibile comb, int _cilindata);

		void accendi();
		void spegni();
		bool is_acceso()const;

		int get_cilindrata()const;
		int get_carica()const;
		int get_giri()const;
		string get_comb()const;

		void accelera(); // premi acceleratore
		void rilascia(); // rilascia acceleratore

		void ricarica();
		void stampa()const;
}; // end of class Motore

ostream& operator << (ostream& os, const Motore& m);

#endif

