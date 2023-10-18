#include <cstdlib>
#include <iostream>
#include "studente.h"
using namespace std;

Studente::Studente(string _no,string _co,int _mat,int _eta):
          Persona(_no,_co,_eta){
   matricola=_mat;                              
   esami=0;                             
}
Studente::~Studente(){
	cout << "distrutto Studente" << endl;
}
void Studente::stampa()const{
   Persona::stampa();
   printf("matricola=%d con esami=%d\n",matricola, esami);  
}

ostream& Studente::stampaOperator(ostream& os)const{
    os << nome << " " << cognome << " di eta'=" << eta;
    os << " matricola=" << matricola << " con esami=" << esami;
    return  os;          
}
     
ostream& operator << (ostream& os, const Studente& s){
    //os << s.nome << " " << s.cognome << " di eta'=" << s.eta;
    //os << " matricola=" << s.matricola << " con esami=" << s.esami;
    //return  os; 
    return  s.stampaOperator(os);        
}               
