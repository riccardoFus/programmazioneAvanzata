#include <iostream>
#include <string>
#include "persona.h"
using namespace std;

Persona::Persona(string nome, string cognome, int eta){
    this->nome = nome;
    this->cognome = cognome;
    this->eta = eta;
    cout << "Creata persona " << *this << endl;
}

Persona::~Persona(){
    cout << "Distrutta persona " << *this << endl;
}

void Persona::stampa() const{
    cout << nome << " " << cognome << " di eta: " << eta << endl;
}

ostream& Persona::stampa_operator(ostream& os) const{
    os << nome << " " << cognome << " di eta: " << eta;
    return os;
}

ostream& operator << (ostream& os, const Persona& p){
    return p.stampa_operator(os);
}