#ifndef __AUTO_H__
#define __AUTO_H__
#include <string.h>
#include "motore.h"

class Auto{
private:      
  char* marca;
  char* modello;
  Motore motore;
  Motore* motoreScorta;
public:
  Auto(Tcombustibile _tipo,int _cil,char* _marca, char* _modello); 
  ~Auto();
  Auto(const Auto& a);
  void stampa() const; 
  void setMotoreScorta(Tcombustibile _tipo,int _cil);              
};
      
#endif
