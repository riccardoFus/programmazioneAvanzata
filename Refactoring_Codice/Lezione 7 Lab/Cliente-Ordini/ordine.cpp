#include "ordine.h"
using namespace std;

Ordine::Ordine(int id_ordine){
    this->id_ordine = id_ordine;
    cliente_ordine = NULL;
    cout << "Costruttore di Ordine: " << id_ordine << endl;
}

Ordine::~Ordine(){
    cout << "Distruttore di Ordine: " << id_ordine << endl;
}

void Ordine::set_cliente(Cliente* cliente_ordine){
    this->cliente_ordine = cliente_ordine;
}

ostream& operator << (ostream& os, const Ordine& o){
    os << "id_ordine: " << o.id_ordine;
    return os;
}