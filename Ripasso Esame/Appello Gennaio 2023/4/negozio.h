#ifndef NEGOZIO_H
#define NEGOZIO_H
#include <string>
#include <vector>
#include "vendita.h"
using namespace std;

class Vendita;

class Negozio{
    private:
        int id;
        string nome;
        vector<Vendita> vendite;
    public:
        Negozio();
        Negozio(int id, string n);
        ~Negozio();
        void addVendita(string nome, int qta, float prezzoTot);
        friend ostream& operator << (ostream& os, const Negozio& n);
};

ostream& operator << (ostream& os, const Negozio& n);

#endif