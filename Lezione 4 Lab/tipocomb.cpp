#include <iostream>
#include "tipocomb.h"
#include <string>
using namespace std;

Tipocomb::Tipocomb(Tcombustibile _comb): comb(_comb){
	// comb = _comb;
	cout << "Creato combustibile " << *this << endl << endl;
}

Tipocomb::~Tipocomb(){
	cout << "Distrutto combustibile " << *this << endl << endl;
}


ostream& operator << (ostream& os, const Tipocomb& tc){
	// string res;
	switch(tc.comb){
		case DIESEL:
			os << "DIESEL";
			// res = "diesel";
			break;
		case BENZINA:
			os << "BENZINA";
			// res = "benzina";
			break;
		case GPL:
			os << "GPL";
			// res = "gpl";
			break;
	}
	return os;
}
