#ifndef ORDINE_H
#define ORDINE_H
#include <iostream>
#include "cliente.h"
using namespace std;

class Cliente;

class Ordine{
    private:
        int id_ordine;
        Cliente* cliente_ordine;
    public:
        Ordine(int id_ordine);
        ~Ordine();
        void set_cliente(Cliente* cliente_ordine);
        friend ostream& operator << (ostream& os, const Ordine& o);
};

ostream& operator << (ostream& os, const Ordine& o);

#endif