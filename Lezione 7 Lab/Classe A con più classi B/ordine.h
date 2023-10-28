#ifndef ORDINE_H
#define ORDINE_H
class Cliente;
#include <iostream>
#include "cliente.h"
using namespace std;

class Ordine{
    private:
        int idOrdine;
        Cliente* clienteOrdine;
    public:
        Ordine(int _idOrdine);
        ~Ordine();
        void setCliente(Cliente* cliente);
        friend ostream& operator << (ostream& os, const Ordine& o);
};

ostream& operator << (ostream& os, const Ordine& o);

#endif