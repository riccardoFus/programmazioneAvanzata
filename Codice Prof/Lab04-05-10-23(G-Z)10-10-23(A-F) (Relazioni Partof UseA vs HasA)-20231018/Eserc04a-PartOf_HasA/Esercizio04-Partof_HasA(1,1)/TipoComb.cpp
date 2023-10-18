#include "TipoComb.h"

#include <iostream>
#include <string>
using namespace std;

TipoComb::TipoComb(Combustibile _comb) : comb(_comb)
{
}


void TipoComb::stampa() const{
	switch (comb) {
			case COMB_DIESEL: cout << "Diesel"; break;
			case COMB_BENZINA: cout << "Benzina"; break;
			case COMB_ELETTRICO: cout << "Elettrico"; break;
			case COMB_IDROGENO: cout << "Idrogeno"; break;
			case COMB_GAS: cout << "Gas"; break;
			default: cout << "Boh?!";
	}
}

string TipoComb::get_comustibile()const{
	switch (comb) {
			case COMB_DIESEL: return "Diesel"; break;
			case COMB_BENZINA: return "Benzina"; break;
			case COMB_ELETTRICO: return "Elettrico"; break;
			case COMB_IDROGENO: return "Idrogeno"; break;
			case COMB_GAS: return "Gas"; break;
			default: return "Boh?!";
	}	
}

