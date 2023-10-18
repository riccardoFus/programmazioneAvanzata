#include <cstdlib>
#include <iostream>
#include "motore.h"
using namespace std;

Motore::Motore(Tipocomb* _tipo, int _cil){
  tipo=_tipo;
  cilindrata=_cil;
  tipo2 = NULL;
  cout<<">>creatoMotore";tipo->stampa();cout<<"-"<<cilindrata<<endl;                          
}
Motore::~Motore(){
  cout<<">>distruttoMotore";tipo->stampa();cout<<"-"<<cilindrata<<endl;                   
}
void Motore::setTipo2(Tipocomb* _tipo){
 tipo2 = _tipo;   
}
void Motore::stampa() const{
  cout << "[Motore:";
  tipo->stampa();
  if (tipo2!=NULL){
    tipo2->stampa();
  }
  cout << ","<<cilindrata<<" cc]"<<endl;     
}
ostream& operator<<(ostream& os, const Motore& m){
 os<<"cilindrata: "<<m.cilindrata;
 if (m.tipo!=NULL)  os<<"carburante: "<<*(m.tipo);
 if (m.tipo2!=NULL) os<<"carburante alternativo: "<<*(m.tipo2);
 return os;
}
