#include "cliente.h"
using namespace std;

Cliente::Cliente(int _idCliente){
    idCliente = _idCliente;
    cout << "Costruttore di Cliente: " << idCliente << " eseguito\n";
}

Cliente::~Cliente(){
    cout << "Distruttore di Cliente: " << idCliente << " eseguito\n";
}

void Cliente::addOrdine(Ordine* ordine){
    vettore_ordini.push_back(ordine);
    cout << "Aggiunto ordine a Cliente: " << idCliente << "\n";
    ordine->setCliente(this);
}

void Cliente::addOrdine2(int idOrdine){
    Ordine o(idOrdine);
    o.setCliente(this);
    lista_ordini.push_front(o);
}

ostream& operator << (ostream& os, const Cliente& c){
    os << "ID Cliente: " << c.idCliente << "\n";
    os << "Ordini fatti:\n";
    for(const auto& it : c.vettore_ordini){
        os << "     " << *it << "\n";
    }
    for(const auto& it : c.lista_ordini){
        os << "     " << it << "\n";
    }
    return os;
}