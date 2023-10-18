#ifndef __MOTORE_H__
#define __MOTORE_H__
#include "tipocomb.h"

class Motore{
 private:
   Tipocomb* tipo; //losanga vuota 1,1
   Tipocomb* tipo2; //losanga vuota 0,1
   int cilindrata;       
 public:
   Motore(Tipocomb* _tipo, int _cil);
   ~Motore();
   void stampa() const; 
   void setTipo2(Tipocomb* _tipo);  
   friend ostream& operator<<(ostream& os, const Motore& m);        
};
ostream& operator<<(ostream& os, const Motore& m);   
#endif
