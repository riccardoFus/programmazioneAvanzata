#ifndef VENDITA_H
#define VENDITA_H
#include <string>
#include "negozio.h"
using namespace std;

class Negozio;

class Vendita{
    private:
        int qta;
        float prezzoTot, prezzo;
        string nome;
        Negozio* negozio;
    public:
        // Vendita(int q, float pTot, float p, string n, Negozio* neg);
        Vendita();
        Vendita(int q, float ptot, string n);
        ~Vendita();
        Vendita(const Vendita& v);
        void setNegozio(Negozio* neg);
        friend ostream& operator << (ostream& os, const Vendita& v);
};

ostream& operator << (ostream& os, const Vendita& v);

#endif