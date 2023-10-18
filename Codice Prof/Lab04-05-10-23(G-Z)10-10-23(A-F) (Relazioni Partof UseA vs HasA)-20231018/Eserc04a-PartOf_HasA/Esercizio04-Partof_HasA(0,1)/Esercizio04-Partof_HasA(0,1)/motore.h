#ifndef __MOTORE_H__
#define __MOTORE_H__
#include "tipocomb.h"

class Motore{
private:
  int cil;
  Tipocomb tipo;      
public:
  Motore(Tipocomb _tipocomb,int _cil);
  Motore(Tcombustibile _tipo,int _cil=1000); 
  ~Motore();
  int get_cil() const;
  Tipocomb get_tipo() const;
  void stampa() const;                  
};

#endif
