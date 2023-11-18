#include <iostream>
#include <string>
#include "persona.h"
using namespace std;

Persona::Persona(string _nome, string _cognome, int _eta){
	nome = _nome;
	cognome = _cognome;
	eta = _eta;
	cout << "Creata persona\n" << *this << endl;
}

Persona::~Persona(){
	cout << "Distrutta persona\n" << *this << endl;
}

void Persona::stampa() const{
	cout << nome << " " << cognome << " di eta' " << eta << endl; 
}
		
ostream& Persona::stampaOperator(ostream& os) const{
	os << nome << " " << cognome << " di eta' " << eta; 
	return os;
}

ostream& operator << (ostream& os, const Persona& p){
	// os << p.nome << " " << p.cognome << " di eta' " << p.eta; 
	// return os;
	return p.stampaOperator(os);
}
