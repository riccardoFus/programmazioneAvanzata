#include <iostream>
#include <string>
#include "automobile.h"
using namespace std;

Automobile::Automobile(string _marca, string _modello, int cilindrata, Tipo_Combustibile* tipo_combustibile): motore(cilindrata, tipo_combustibile){
    marca = _marca;
    modello = _modello;
    motore_scorta = NULL;
    cout << "Creata automobile di marca " << *this << endl;
}

Automobile::~Automobile(){
    cout << "Distrutta automobile di marca " << *this << endl;
    if(motore_scorta != NULL){
        delete motore_scorta;
    }
}

void Automobile::add_motore_scorta(int cilindrata, Tipo_Combustibile* tipo_combustibile){
    motore_scorta = new Motore(cilindrata, tipo_combustibile);
    cout << "Aggiunto motore di scorta nell'automobile di marca " << *this << endl;
}

ostream& operator << (ostream& os, const Automobile& automobile){
    os << automobile.marca << ", modello " << automobile.modello << ". " << automobile.motore;
    if(automobile.motore_scorta != NULL){
        os << " " << *(automobile.motore_scorta);
    }
    return os;
}