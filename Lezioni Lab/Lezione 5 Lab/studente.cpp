#include <iostream>
#include <string>
#include "studente.h"
using namespace std;

Studente::Studente(int _matricola, string _nome, string _cognome, int _eta): 
    Persona(_nome, _cognome, _eta){
    matricola = _matricola;
    esami = 0;
    cout << "Creato studente\n" << *this << endl;
}

Studente::~Studente(){
    cout << "Distrutto studente\n" << *this << endl;
}

// se non lo implemento, verrà usato quello di Persona::stampa()
void Studente::stampa(){
    cout << matricola << " " << nome << " " << cognome << " di eta' " << eta << endl;
}

ostream& Studente::stampaOperator(ostream& os) const{
    os << matricola << " " << nome << " " << cognome << " di eta' " << eta;
    // soluzione : al posto di private, mettiamo protected
    return os;
}

ostream& operator << (ostream& os, const Studente& s){
    return s.stampaOperator(os);
}