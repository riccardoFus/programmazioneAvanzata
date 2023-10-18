#ifndef __TIPOCOMB_H__
#define __TIPOCOMB_H__

#include<cstdlib>
#include<iostream>
using namespace std;

typedef enum {DIESEL, BENZINA, GPL} Tcombustibile;

class Tipocomb{
 private:
   Tcombustibile comb;      
 public:
   Tipocomb(Tcombustibile _comb);
   ~Tipocomb();
   void stampa() const; 
   friend ostream& operator<<(ostream& os, const Tipocomb& tc);                   
};
ostream& operator<<(ostream& os, const Tipocomb& tc);
#endif
