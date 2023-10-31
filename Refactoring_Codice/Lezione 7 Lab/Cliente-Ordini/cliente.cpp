#include "cliente.h"
using namespace std;

Cliente::Cliente(int id_cliente){
    this->id_cliente = id_cliente;
    cout << "Costruttore di Cliente : " << id_cliente << endl;
}

Cliente::~Cliente(){
    cout << "Distruttore di Cliente : " << id_cliente << endl;
}

void Cliente::add_ordine_vettore(Ordine* ordine){
    vettore_ordini.push_back(ordine);
    cout << "Aggiunto ordine a Cliente : " << id_cliente << endl;
    ordine->set_cliente(this);
}

void Cliente::add_ordine_lista(int id_ordine){
    Ordine o(id_ordine);
    o.set_cliente(this);
    lista_ordini.push_front(o);
}

ostream& operator << (ostream& os, const Cliente& c){
    os << "id_cliente : " << c.id_cliente << endl;
    os << "ordini fatti : " << endl;
    for(const auto& it : c.vettore_ordini){
        os << "\t" << *it << endl;
    }
    for(const auto& it : c.lista_ordini){
        os << "\t" << it << endl;
    }
    return os;
}