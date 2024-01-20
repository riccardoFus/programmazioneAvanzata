#include "negozio.h"
#include "vendita.h"
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

Negozio::Negozio(){}

Negozio::Negozio(int id, string n){
    this->id = id;
    nome = n;
}

Negozio::~Negozio(){
}

void Negozio::addVendita(string nome, int qta, float prezzoTot){
    try{
        vendite.push_back(Vendita(qta, prezzoTot, nome));
    }catch(const invalid_argument& e){
        vendite.push_back(Vendita(qta, -prezzoTot, nome));
        cout << e.what() << endl;
    }catch(const out_of_range& e){
        vendite.push_back(Vendita(-qta, prezzoTot, nome));
        cout << e.what() << endl;
    }catch(const overflow_error& e){
        vendite.push_back(Vendita(1, prezzoTot, nome));
        cout << e.what() << endl;
    }
    cout << "CIAO" << endl;
    vendite.back().setNegozio(this);
}

ostream& operator << (ostream& os, const Negozio& n){
    os << n.id << " " << n.nome << ", vendite:" << endl;
    for(const auto& v : n.vendite){
        os << "\t" << v << endl;
    }
    return os;
}