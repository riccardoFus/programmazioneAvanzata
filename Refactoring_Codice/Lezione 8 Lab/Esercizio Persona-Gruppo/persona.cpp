#include "persona.h"
#include <iostream>
using namespace std;

Persona::Persona(){
    nome = "Default";
    cout << "Costruttore senza parametri di " << nome << " eseguito" << endl; 
}

Persona::Persona(string nome){
    this->nome = nome;
    cout << "Costruttore con parametro di " << nome << " eseguito" << endl;
}

Persona::Persona(const Persona& persona){
    nome = persona.nome;
    cout << "Costruttore di copia di " << nome << " eseguito" << endl;
}

Persona::~Persona(){
    cout << "Distruttore di " << nome << " eseguito" << endl;
}

bool Persona::operator < (const Persona& persona) const {
    return nome < persona.nome; // per decrescente, basta mettere >
}

ostream& operator << (ostream& os, const Persona& persona){
    return os << persona.nome;
}