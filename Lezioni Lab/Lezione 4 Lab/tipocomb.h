#ifndef TIPOCOMB_H
#define TIPOCOMB_H

#include <iostream>
using namespace std;

typedef enum {
	DIESEL, 
	BENZINA,
	GPL
} Tcombustibile;

class Tipocomb{
	private:
		Tcombustibile comb;
	public:
		Tipocomb(Tcombustibile _comb);
		~Tipocomb();
		friend ostream& operator << (ostream& os, const Tipocomb& tc);
};
ostream& operator << (ostream& os, const Tipocomb& tc);

#endif

