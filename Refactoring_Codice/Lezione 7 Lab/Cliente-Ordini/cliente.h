#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <vector>
#include <list>
#include "ordine.h"
using namespace std;

class Ordine;

class Cliente{
    private:
        int id_cliente;
        vector<Ordine*> vettore_ordini;
        list<Ordine> lista_ordini;
    public:
        Cliente(int id_cliente);
        ~Cliente();
        void add_ordine_vettore(Ordine* ordine);
        void add_ordine_lista(int id_ordine);
        friend ostream& operator << (ostream& os, const Cliente& c);
};

ostream& operator << (ostream& os, const Cliente& c);

#endif