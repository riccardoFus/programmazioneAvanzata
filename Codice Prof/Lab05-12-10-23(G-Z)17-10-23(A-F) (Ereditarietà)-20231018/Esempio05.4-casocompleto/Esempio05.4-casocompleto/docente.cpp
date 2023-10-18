#include <cstdlib>
#include <iostream>
#include "docente.h"
using namespace std;

Docente::Docente(string _no,string _co,int _cor,int _eta):
          Persona(_no,_co,_eta){
   corsi=_cor;                                                         
}
Docente::~Docente(){
	cout << "distrutto Docente" << endl;
}
void Docente::stampa()const{
   Persona::stampa();
   printf("corsi=%d\n",corsi);  
}
ostream& Docente::stampaOperator(ostream& os)const{
    os << nome << " " << cognome << " di eta'=" << eta;
    os << " corsi=" << corsi;
    return  os;          
}

ostream& operator << (ostream& os, const Docente& d){
    //os << d.nome << " " << d.cognome << " di eta'=" << d.eta;
    //os << " corsi=" << d.corsi << endl;
    //return  os;
    return  d.stampaOperator(os);      
}
  
