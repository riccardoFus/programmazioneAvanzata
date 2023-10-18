#include <cstdlib>
#include <iostream>
#include "persona.h"
using namespace std;

Persona::Persona(string _nome,string _cognome,int _eta){
  nome=_nome;  cognome=_cognome;  eta=_eta;                    
}
Persona::~Persona(){
	cout << "distrutto Persona" << endl;
}
void Persona::stampa()const{
  cout << nome <<" "<<cognome<<" "<<" di eta'="<<eta<<endl;    
}

ostream& Persona::stampaOperator(ostream& os)const{
    os << nome << " " << cognome << " di eta'=" << eta;
    return  os;          
}

ostream& operator << (ostream& os, const Persona& p){
	/*
	 attenzione che così facendo se si dichiara
	 Persona* p = new Studente("Anna","Bianchi",234555,22); 
	 cout << "Persona*="<< *p << endl;
	 viene invocato questo operatore e non il << di Studente!!!
	 */
    //os << p.nome << " " << p.cognome << " di eta'=" << p.eta << endl;
    //return  os;  
	//soluzione corretta  
    return p.stampaOperator(os);
}
