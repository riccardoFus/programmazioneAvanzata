#ifndef CLIENTE_H
#define CLIENTE_H
class Ordine;
#include "ordine.h"
#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Cliente{
    private:
        int idCliente;
        // l'ordine non devo modificarlo, spostarlo ecc...
        // mantiene un riferimento perché è una losanga vuota
        // il vector di default è vuoto -> sto rispettando la richiesta 0...*
        vector<Ordine*> vettore_ordini;
        // mantiene un oggetto associato all'istanza, perché è una losanga piena
        list<Ordine> lista_ordini;
    public:
        Cliente(int _idCliente);
        ~Cliente();
        void addOrdine(Ordine* ordine);
        void addOrdine2(int idOrdine);
        friend ostream& operator << (ostream& os, const Cliente& c);
};

ostream& operator << (ostream& os, const Cliente& c);

#endif