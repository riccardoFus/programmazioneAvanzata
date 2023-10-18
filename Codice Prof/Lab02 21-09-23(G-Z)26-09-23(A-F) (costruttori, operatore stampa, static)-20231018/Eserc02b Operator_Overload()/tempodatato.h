#ifndef tempodatato_h
#define tempodatato_h

#include "tempo.h"

class tempodatato: public tempo{
	private:
	int giorno;
	int mese;
	int anno;
	public:
	tempodatato();
	tempodatato(int _g,int _m,int _a, int _o=0, int _mi=0, int _s=0);
	void AggiungiOra();
	friend ostream& operator<<(ostream& os, const tempodatato& td);      
};

void test_tempodatato();

#endif
