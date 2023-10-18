#ifndef __COMBUSTIBILE_H__
#define _COMBUSTIBILE_H__

#include <iostream>
using namespace std;

typedef enum Combustibile 
{
		COMB_DIESEL, 
		COMB_BENZINA, 
		COMB_ELETTRICO, 
		COMB_IDROGENO, 
		COMB_GAS 
}Combustibile;

class TipoComb
{
 private:
		Combustibile comb;
		
 public:
		TipoComb(Combustibile _comb);
		void stampa()const;
		string get_comustibile()const;
}; // end of class



#endif

