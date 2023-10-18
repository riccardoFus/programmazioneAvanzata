#ifndef __AUTO_H__
#define __AUTO_H__
#include "motore.h"
#include <string>
using namespace std;

class Auto{
private:
  Motore motore;  //losanga piena 1,1
  Motore* motscorta;//losanga piena 0,1
  string marca;
  string modello;      
public:  
  Auto(Tipocomb* _tipo, int _cil,string _ma, string _mo);
  ~Auto();
  void stampa()const;  
  void setMotscorta(Tipocomb* _tipo, int _cil);
  void addMotoretipo(Tipocomb* _tipo);      
  friend ostream& operator<<(ostream& os, const Auto& a);     
};

ostream& operator<<(ostream& os, const Auto& a); 
#endif
