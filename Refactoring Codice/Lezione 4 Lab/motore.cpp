#include <iostream>
#include "motore.h"
using namespace std;

/*
Motore::Motore(int _cilindrata, tipo_combustibile _combustibile): cilindrata(_cilindrata), tipo(_comb){
    cout << "Creato motore di cilindrata " << *this << " con losanga piena" endl;
}
*/

Motore::Motore(int _cilindrata, Tipo_Combustibile* _tipo1){
    cilindrata = _cilindrata;
    tipo1 = _tipo1;
    tipo2 = NULL;
    cout << "Creato motore di cilindrata " << *this << endl;
}

Motore::~Motore(){
    cout << "Distrutto motore di cilindrata " << *this << endl; 
}

ostream& operator << (ostream& os, const Motore& motore){
    os << motore.cilindrata << " con combustibile " << *(motore.tipo1);
    if(motore.tipo2 != NULL){
        os << " e " << *(motore.tipo2);
    }
    return os;
}