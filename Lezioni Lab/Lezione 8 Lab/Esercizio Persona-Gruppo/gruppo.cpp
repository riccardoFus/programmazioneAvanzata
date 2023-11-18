#include <iostream>
#include "gruppo.h"
using namespace std;

Gruppo::Gruppo(){
    cout << "Creato gruppo" << endl;
}

Gruppo::~Gruppo(){
    cout << "Distrutto gruppo" << endl;
}

void Gruppo::add_persona1(Persona p){
    set_persona.insert(p);
}

void Gruppo::add_persona2(const Persona& p){
    set_persona.insert(p);
}

void Gruppo::add_persona3(string nome){
    set_persona.insert(Persona(nome));
}

void Gruppo::add_persona4(Persona* p){
    set_puntatori_persona.insert(p);
}

ostream& operator << (ostream& os, const Gruppo& g){
    for(auto& i : g.set_persona){
        os << i << " ";
    }
    for(auto& i : g.set_puntatori_persona){
        os << *i << " ";
    }
    return os;
}

void Gruppo::remove_persona(string nome){
    set<Persona>::iterator set_iterator;
    set_iterator = set_persona.find(Persona(nome));
    if(set_iterator != set_persona.end()){
        set_persona.erase(set_iterator);
    }
}