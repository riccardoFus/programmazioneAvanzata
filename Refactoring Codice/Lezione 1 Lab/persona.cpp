#include <cstdlib>
#include <iostream>
#include "persona.h"
using namespace std;

Persona::Persona(){
    cout << "Costruttore a zero parametri" << endl;
    nome = "Riccardo";
    cognome = "Fusiello";
    eta = 21;
    vettore_dinamico = NULL;
}

Persona::Persona(string _nome, string _cognome, int _eta){
    cout << "Costruttore a tre parametri" << endl;
    nome = _nome;
    cognome = _cognome;
    eta = _eta;
    vettore_dinamico = new int [5];
    for(int i = 0; i < 5; i++){
        vettore_dinamico[i] = i;
    }
}

Persona::Persona(const Persona& p){
    cout << "Costruttore di copia" << endl;
    nome = p.nome;
    cognome = p.cognome;
    eta = p.eta;
    if(p.vettore_dinamico == NULL){
        vettore_dinamico = NULL;
    }else{
        vettore_dinamico = new int [5];
        for(int i = 0; i < 5; i++){
            vettore_dinamico[i] = p.vettore_dinamico[i];
        }
    }
}

Persona::~Persona(){
    cout << "Distruttore" << endl;
    if(vettore_dinamico != NULL){
        delete[] vettore_dinamico;
    }
}

void Persona::stampa() const {
    cout << nome << " " << cognome << " di eta: " << eta << endl;
    if(vettore_dinamico != NULL){
        for(int i = 0; i < 5; i++){
            cout << "[" << vettore_dinamico[i] << "] ";
        }
        cout << endl;
    }
}

int Persona::get_eta() const{
    return eta;
}

string Persona::get_nome() const{
    return nome;
}

string Persona::get_cognome() const{
    return cognome;
}

int* Persona::get_vettore_dinamico() const{
    return vettore_dinamico;
}

void Persona::set_eta(int _eta){
    eta = _eta;
}

void Persona::set_nome(string _nome){
    nome = _nome;
}

void Persona::set_cognome(string _cognome){
    cognome = _cognome;
}

void stampa_con_copia(const Persona p){
    p.stampa();
}

void stampa_con_puntatore(const Persona* p){
    p->stampa();
}

void stampa_con_riferimento(const Persona& p){
    p.stampa();
}

ostream& operator << (ostream& os, const Persona& p){
    int* vettore_temporaneo = p.get_vettore_dinamico();
    os << p.get_nome() << " " << p.get_cognome() << " di eta: " << p.get_eta() << "\n";
    if(vettore_temporaneo != NULL){
        for(int i = 0; i < 5; i++){
            os << "[" << vettore_temporaneo[i] << "] ";
        }
        os << "\n";
    }
    return os;
}