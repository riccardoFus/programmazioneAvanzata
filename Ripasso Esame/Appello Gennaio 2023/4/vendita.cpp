#include "vendita.h"
#include "negozio.h"
#include <iostream>
#include <stdexcept>
using namespace std;

/*
Vendita::Vendita(int q, float pTot, float p, string n, Negozio* neg){
    qta = q;
    prezzoTot = pTot;
    prezzo = p;
    nome = 
}
*/

Vendita::Vendita(){}

Vendita::Vendita(int q, float ptot, string n){
    negozio = NULL;
    if(q < 0){
        q = -q;
        prezzo = ptot / q;
        if(prezzo < 0){
            prezzo = -prezzo;
            nome = n;
            qta = q;
            prezzoTot = ptot;
            throw invalid_argument("Prezzo negativo");
        }
        nome = n;
        qta = q;
        prezzoTot = ptot;
        throw out_of_range("Quantità negativa");
    }
    if(q == 0){
        q = 1;
        prezzo = ptot / q;
        if(prezzo < 0){
            prezzo = -prezzo;
            nome = n;
            qta = q;
            prezzoTot = ptot;
            throw invalid_argument("Prezzo negativo");
        }
        nome = n;
        qta = q;
        prezzoTot = ptot;
        throw overflow_error("Quantità uguale a 0");
    }
    prezzo = ptot / q;
    if(prezzo < 0){
        prezzo = -prezzo;
        nome = n;
        qta = q;
        prezzoTot = ptot;
        throw invalid_argument("Prezzo negativo");
    }
    nome = n;
    qta = q;
    prezzoTot = ptot;
}

Vendita::~Vendita(){
}

Vendita::Vendita(const Vendita& v){
    qta = v.qta;
    prezzoTot = v.prezzoTot;
    prezzo = v.prezzo;
    nome = v.nome;
    negozio = v.negozio;
}

void Vendita::setNegozio(Negozio* neg){
    this->negozio = neg;
}

ostream& operator << (ostream& os, const Vendita& v){
    os << v.qta << " " << v.prezzoTot << " " << v.prezzo << " " << v.nome;
    return os;
}