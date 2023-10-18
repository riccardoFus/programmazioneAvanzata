//Autore: Roberti Pierluigi
//Data: 06-05-2010

//contiene l'impLementazione dell'interfaccia
#include "persona.h"

#include <iostream>
using namespace std;

Persona::Persona(const string &_nome, const string &_cognome, int _eta) {
 	nome = _nome;
	cognome = _cognome;
	eta=_eta;
}

void Persona::Stampa() const { 
	 cout << "Persona::Stampa " << nome << " " << cognome << " " << eta;
}

string Persona::get_nome() const {
    return nome;       
}
string Persona::get_cognome() const {
    return cognome;       
}
int Persona::get_eta() const {
    return eta;       
}
 
ostream& operator << (ostream& os, Persona& p){
   os << "Persona:" << p.nome << " " << p.cognome << " " << p.eta;  
   return os; 
} 

