#include "ordine.h"
using namespace std;

Ordine::Ordine(int _idOrdine){
    idOrdine = _idOrdine;
    clienteOrdine = NULL;
    cout << "Costruttore di Ordine: " << idOrdine << " eseguito\n";
}

Ordine::~Ordine(){
    cout << "Distruttore di Ordine: " << idOrdine << " eseguito\n";
}

void Ordine::setCliente(Cliente* cliente){
    clienteOrdine = cliente;
}

ostream& operator << (ostream& os, const Ordine& o){
    os << "ID Ordine: " << o.idOrdine;
    return os;
}