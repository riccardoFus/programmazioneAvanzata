#include <iostream>
#include <string>
#include "studente.h"
using namespace std;

Studente::Studente(int matricola, string nome, string cognome, int eta): Persona(nome, cognome, eta){
    this->matricola = matricola;
    this->esami = 0;
    cout << "Creato studente " << *this << endl;
}

Studente::~Studente(){
    cout << "Distrutto studente " << *this << endl;
}

void Studente::stampa() const{
    cout << matricola << " " << nome << " " << cognome << " di eta: " << eta << endl;
}

ostream& Studente::stampa_operator(ostream& os) const{
    os << matricola << " " << nome << " " << cognome << " di eta: " << eta;
    return os;
}

ostream& operator << (ostream& os, const Studente& s){
    return s.stampa_operator(os);
}